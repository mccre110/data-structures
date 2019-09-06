#include "Registrar.h"
using namespace std;

Registrar::Registrar(string filename)
{
	fi = new IO(filename,"");
	line = new GenQueue<Student>();
	windowCount = stoi(fi->readLine()); // converts the first line (window count) to an integer 
	fLine = windowCount;
	array= new Student[windowCount];
	wait = new CalculateWait(windowCount);
	tick = 0;
	ck = true;
	loop = true;
}
Registrar::~Registrar(){}
void Registrar::addStudent(int arrive, int time)
{
	Student s(arrive, time);
	line->insert(s); // adds the new student to the queue 
}
void Registrar::sim()
{
	while (!line->isEmpty() || loop) // checks for the queue and file to not be empty
	{
		if (ck == true) // makes sure the file time doesnt get overwritten by the ticks
		{
			fLine = fi->readLine(); //converts the second line (when the students arrive) to an integer
			if (fLine !="")
			{
				time = stoi(fLine);
			}
			else
				loop = false;		
		}	
		if (tick == time)
		{
			ck = true;
			fLine = fi->readLine();
			int studentCount = stoi(fLine); // converts the third line (the number of students) to an integer
			for (int i = 0; i < studentCount; ++i)
			{
				fLine = fi->readLine();
				this->addStudent(tick, stoi(fLine));
			}
		}
		else
			ck = false;
		for (int i = 0; i < windowCount; ++i) // this loops through the array for each tick
		{										
			if (array[i].timeNeeded == -1 ||array[i].timeNeeded==0) // if the array is empty or the students are done
			{

				if (!line->isEmpty()) // if theres students in the queue put them in the array
				{
					array[i] = line->remove(); // removes them from queue
					array[i].windowTime = tick; 
					wait->addWaitTime(array[i].windowTime-array[i].arrivalTime); // this calculates their wait time
				}
				else
					wait->addWin(i); // adds idle time to the total window idle time (if the queue is empty)
			}
			else // if the students are still at the window, the time they need is decreased
				array[i].timeNeeded -= 1;
		}
		tick++;	// time increments after 1 cycle
	}
}
void Registrar::print()
{
	wait->calc(); // does the stats, prints them
	wait->print();
}
