#include <fstream>
#include <iostream>
#include "IO.h"
using namespace std;

//open input and output file
IO::IO(string inFile, string outFile)
{
	inputFile.open (inFile, ifstream::in);
  	outputFile.open(outFile, ios_base::app);
}
//delete streams
IO::~IO()
{
	inputFile.close();
	outputFile.close();
}

//reads file line one at a time
string IO::readLine()
{
	string fileLine = "";
	if (inputFile)
	{
		while(getline(inputFile, fileLine))
			return fileLine;
		
	}
	else
	{
		cout << "File Bad" << endl;
		exit(1);
	}
}

//writes string to file
void IO::writeLine(string fileLine)
{
	outputFile << fileLine << endl;
}