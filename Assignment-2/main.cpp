#include "Game.h"
#include <locale>
#include <unistd.h>
#include <fstream>

using namespace std;
int main(int argc, char const *argv[])
{
	ofstream out;
	srand(time(NULL));
	cout << "Mapped or Random Board? [M/R]" << endl;

	string uinput;
	getline(cin, uinput);

	//Random Board Generation
	if (uinput =="r" || uinput =="R")
	{

		//Varibale Declaration
		int height, length, mode, pause;
		double dens;
		string outf;

		cout << "Enter Height: " << endl;
		cin >> height;
		cout << "Enter Length: " << endl;
		cin >> length;
		cout << "Enter Population Density (0-1): " << endl;
		cin >> dens;
		cout << "Enter Game Mode 1.Classic 2.Donut 3.Mirror [1,2,3]: " << endl;
		cin >> mode;

		//Covers if User Input Isn't 1-3
		if (mode>3)
		{
			cout <<"Enter a valid mode"<<endl;
			return 0;
		}

		cout << "Enter Pause Mode 1.Enter 2.Pause 3.File Output [1,2,3]: " << endl;
		cin >> pause;
		if (pause == 3)
		{
			cout <<"Enter a file name: "<<endl;
			if (cin.peek() == '\n')
				cin.ignore();
			getline(cin, outf);
			out.open(outf, ios_base::app);
		}

		//Covers if User Input Isn't 1-3
		else if (pause>3)
		{
			cout <<"Enter a valid mode"<<endl;
			return 0;
		}
		Game myG = Game(height,length,dens,mode);
		int count = 0;

		//Loops program with either a pause, enter or file out
		do
		{
			if (pause ==1)
			{
				cout << count << endl;
				myG.print();
				cin.clear();
				cin.ignore();
			}
			else if (pause == 2)
			{
				cout << count << endl;
				myG.print();
				usleep(1000000);
			}
			else if (pause == 3)
			{
				//Proints board to file
				out << count << endl;
				for (int i = 0; i < myG.board->height; ++i)
				{
					for (int j = 0; j < myG.board->length; ++j)
					{
						out << myG.board->genNext[i][j]<<" ";
					}
					out << endl;
				}
				out <<endl;
			}
			myG.simulate();
			count++;
		}
		while (myG.check());

		//Program end sequnce
       	out.close();
       	if (cin.peek() == '\n')
				cin.ignore();
		cout << "Simulation Halted, Press Enter to Exit: " << endl;
		cin.ignore();
	}

	//Mapped Board
	else if (uinput =="m" || uinput =="M")
	{
		//Varible declaration
		int mode, pause;
		string fileName;
		string outf;

		cout << "Enter a fileName: " <<endl;
		getline(cin, fileName);

		cout << "Enter Game Mode 1.Classic 2.Donut 3.Mirror [1,2,3]: " << endl;
		cin >> mode;

		//Covers bad input
		if (mode>3)
		{
			cout <<"Enter a valid mode"<<endl;
			return 0;
		}
		cout << "Enter Pause Mode 1.Enter 2.Pause 3.File Output [1,2,3]: " << endl;
		cin >> pause;
		if (pause == 3)
		{
			cout <<"Enter a file name: "<<endl;
			if (cin.peek() == '\n')
				cin.ignore();
			getline(cin, outf);
			out.open(outf, ios_base::app);
		}

		//Covers bad input
		else if (pause>3)
		{
			cout <<"Enter a valid mode"<<endl;
			return 0;
		}
		Game myG = Game(fileName, mode);
		int count = 0;

		// Program Loop
		do
		{
			if (pause ==1)
			{
				cout << count << endl;
				myG.print();
				cin.clear();
				cin.ignore();
			}
			else if (pause == 2)
			{
				cout << count << endl;
				myG.print();
				usleep(1000000);
			}
			else if (pause == 3)
			{
				//Prints board to file
				out << count << endl;
				for (int i = 0; i < myG.board->height; ++i)
				{
					for (int j = 0; j <myG.board->length; ++j)
					{
						out << myG.board->genNext[i][j]<<" ";
					}
					out << endl;
				}
				out <<endl;
			}
			myG.simulate();
			count++;
		}
		while (myG.check());

		//Program Close
       	out.close();
       	if (cin.peek() == '\n')
				cin.ignore();
		cout << "Simulation Halted, Press Enter to Exit: " << endl;
		cin.ignore();
	}
	return 0;
}
