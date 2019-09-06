#include "Board.h"
#include <fstream>
#include <iostream>


using namespace std;
Board::Board(int h, int l, double density, int m)
{
	//sets class varibles
	mode = m;
	height = h;
	length = l;

	//creates two boards
	genInt = new char*[height];
	genNext = new char*[height];
	for(int i = 0; i < height; ++i)
	{
    	genInt[i] = new char[length];
    	genNext[i] = new char[length];
	}

	//fill boards based on density
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < length; ++j)
		{
			if (check(density))
			{
				genInt[i][j] = 'X';
				genNext[i][j] = 'X';
			}
			else
			{
				genInt[i][j] = '-';
				genNext[i][j] = '-';
			}
		}
}
Board::Board(string fileName, int m)
{
	mode = m;
	readFile(fileName);
}

Board::~Board()
{
	for(int i = 0; i < height; ++i)
	{
    	delete genInt[i];
    	delete genNext[i];
	}
	delete genInt;
	delete genNext;
}
void Board::printBoard()
{
	//loops through board and prints to console
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			cout << genNext[i][j]<<" ";
		}
		cout << endl;
	}
}
bool Board::check(double prob)
{
	return rand()%100<(prob*100);
}
void Board::readFile(string fileName)
{
	//reads in two lines, creates arrays based on dementions and then fills arrays ->
	//based on file
	ifstream inputFile(fileName);
	if (inputFile)
	{
		string fileLine ="";
		int fileLineCount=0;
		//sets two dimentions
		while (getline(inputFile, fileLine)) 
		{
			if (fileLineCount==0)
				height = stoi(fileLine);
			else if (fileLineCount==1)
			{
        		length = stoi(fileLine);
        		break;
			}
			fileLineCount++;
		}
		// array creation
			genInt = new char*[height];
			genNext = new char*[height];
			for(int i = 0; i < height; ++i)
			{
    			genInt[i] = new char[length];
    			genNext[i] = new char[length];
			}

		//fills arrays via file
    	fileLineCount=0;
		while (getline(inputFile, fileLine)) 
        {
        	for(int i=0; i<fileLine.length();++i)
			{
				if (fileLine[i] == 'X'||fileLine[i] == '-')
				{
					genInt[fileLineCount][i] = fileLine[i];
					genNext[fileLineCount][i] = fileLine[i];
				}
        		
			}
        	fileLineCount++;
        }
	}
	else
		cout << "File Not Valid." << endl;

	inputFile.close();
}

void Board::setCell(int h, int l, char status)
{
	genNext[h][l] = status;
}
char Board::getCell(int h, int l)
{
	//delegates which getter via mode
	if (this->mode == 1)
	{
		return getCellClassic(h,l);
	}
	else if (this->mode == 2)
	{
		return getCellDonut(h,l);
	}
	else
	{
		return getCellMirror(h,l);
	}
}
char Board::getCellClassic(int h, int l)
{
	//all out of bound queries are set to dead
	if (h>=0 && h<height && l>=0 && l<length)
		return genInt[h][l];
	else
		return '-';
}
char Board::getCellDonut(int h, int l)
{
	//all out of bound queries are set to other boarder
	if (h>=0 && h<height && l>=0 && l<length)
		return genInt[h][l];
	if (h<0)
		h = height-1;
	else if (h>=height)
		h = 0;
	if (l<0)
		l = length-1;
	else if (l>=length)
		l = 0; 
	return genInt[h][l];		
}
char Board::getCellMirror(int h, int l)
{
	//all out of bound queries are set to reflect
	if (h>=0 && h<height && l>=0 && l<length)
		return genInt[h][l];
	if (h<0)
		h++;
	else if (h>=height)
		h--;
	if (l<0)
		l++;
	else if (l>=length)
		l--; 
	return genInt[h][l];
}
void Board::update()
{
	//sets arrays values to each other
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < length; ++j)
		{	
			genInt[i][j] = genNext[i][j];
		}
}