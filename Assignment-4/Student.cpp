#include "Student.h"
using namespace std;


Student::Student(int arrival, int needed) //the queue for the registrar line will store objects of type Student 
										  //and each student comes w the time they arrived and the time they need at the window
{
	arrivalTime = arrival;
	timeNeeded = needed;
}
Student::Student()
{
	timeNeeded = -1;
}
Student::~Student()
{
	
}