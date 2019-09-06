#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <algorithm> 
#include <locale>
#include <math.h>
#include <stdlib.h>
#include "DNA.h"

using namespace std;
DNA dna;

int main(int argc, char** argv)
{
	srand(time(0));
	if(argc > 1)
		{
			string fileName = argv[1];
			while (true)
			{
				readFile(fileName);
				writeFileSummary();
				writeString();
				cout << "Would you like to process another list? [Y/N]:"<<endl;
				string uinput;
				getline(cin, uinput);
				if (uinput =="y"||uinput =="Y")
				{
					cout << "Enter File Name:"<<endl;
					getline(cin, fileName);	
				}
				else if (uinput =="n"||uinput =="N")
					break;
				else
					cout << "Try Again" <<endl;
			}			
		}
		else
			cout <<"Enter a valid file name."<<endl;
}
bool validateInput(string input)
{
	for (int i=0; i<input.size(); i++)
	{
		char upper = toupper(input[i]);//Char to Upper Char
		if (upper=='A') //check A,T,C,G
			continue;
		else if (upper=='T')
			continue;
		else if (upper=='C')
			continue;
		else if (upper=='G')
			continue;
		else
			return false;
	}
	return true;
}
void readFile(string fileName)
{
	ifstream inputFile(fileName);
	if (inputFile)
	{
		string fileLine ="";
		int fileLineCount=1;
		while (getline(inputFile, fileLine)) 
		{
			trim(fileLine); 
			if (validateInput(fileLine))
			{
				for(auto& x: fileLine)
				{
        			x = toupper(x);
				}
				
	    		dna.calculate(fileLine);
        		fileLineCount++;
        	}
        	else
        	{
        		//fileLine ="";
        		cout <<"File Line: "<<fileLineCount<<" not valid."<<endl;
        		fileLineCount++;
        	}
		}
		dna.cleanup();	
	}
	else
		cout << "File Not Valid." << endl;

	inputFile.close();
	
}
double genLength()
{
	const double PI  =3.141592653589793238463;
	//ofstream outfile;
  	//outfile.open("CoreyMcCrea.out", ios_base::app);
  	double a = rand() / (RAND_MAX + 1.);
  	double b = rand() / (RAND_MAX + 1.);
  	double c = (sqrt(-2*log(a))*cos(2*PI*b));
  	double d = (dna.stddev*c) + dna.avg;
  	return d;
}
void writeFileSummary()
{
	ofstream outfile;
  	outfile.open("CoreyMcCrea.out", ios_base::app);
  	outfile << "Corey McCrea:2279388"<<endl;
  	outfile <<"Relative Prob A: "<<dna.relA<<endl;
  	outfile << "Relative Prob T: "<<dna.relT<<endl;
  	outfile << "Relative Prob C: "<<dna.relC<<endl;
  	outfile << "Relative Prob G: "<<dna.relG<<endl;
  	outfile << "Relative Prob AA: "<<dna.relAA<<endl;
  	outfile << "Relative Prob TA: "<<dna.relTA<<endl;
  	outfile << "Relative Prob CA: "<<dna.relCA<<endl;
  	outfile << "Relative Prob GA: "<<dna.relGA<<endl;
  	outfile << "Relative Prob AT: "<<dna.relAT<<endl;
  	outfile << "Relative Prob TT: "<<dna.relTT<<endl;
  	outfile << "Relative Prob CT: "<<dna.relCT<<endl;
  	outfile << "Relative Prob GT: "<<dna.relGT<<endl;
  	outfile << "Relative Prob AC: "<<dna.relAC<<endl;
  	outfile << "Relative Prob TC: "<<dna.relTC<<endl;
  	outfile << "Relative Prob CC: "<<dna.relCC<<endl;
  	outfile << "Relative Prob GC: "<<dna.relGC<<endl;
  	outfile << "Relative Prob AG: "<<dna.relAG<<endl;
  	outfile << "Relative Prob TG: "<<dna.relTG<<endl;
  	outfile << "Relative Prob CG: "<<dna.relCG<<endl;
  	outfile << "Relative Prob GG: "<<dna.relGG<<endl;
  	outfile << "Sum String Length: "<< dna.totalcount<<endl;
  	outfile <<"Mean String Length: "<< dna.avg<<endl;
  	outfile << "Variance: "<< dna.variance <<endl;
  	outfile << "Standard Deviation: "<< dna.stddev<<endl;
  	outfile.close();
}
void writeString()
{
	ofstream outfile;
  	outfile.open("CoreyMcCrea.out", ios_base::app);
	for (int i = 0; i < 1000; ++i)
	{
		string temp = "";
		double len = genLength();
		while (temp.size()<len)
		{
			int ranNum = (rand() % 4) + 1;
			if (ranNum == 1 &&check(dna.relA))
			{
				ranNum = (rand() % 4) + 1;
				temp += "A";
				if (ranNum == 1 &&check(dna.relAA)&&temp.size()<len)
					temp +="A";
				else if (ranNum == 2 &&check(dna.relAT)&&temp.size()<len)
					temp +="T";
				else if (ranNum == 3 &&check(dna.relAC)&&temp.size()<len)
					temp +="C";
				else if (ranNum == 4 &&check(dna.relAG)&&temp.size()<len)
					temp +="G";
			}
			else if (ranNum == 2 &&check(dna.relT))
			{
				ranNum = (rand() % 4) + 1;
				temp += "T";
				if (ranNum == 1 &&check(dna.relTA)&&temp.size()<len)
					temp +="A";
				else if (ranNum == 2 &&check(dna.relTT)&&temp.size()<len)
					temp +="T";
				else if (ranNum == 3 &&check(dna.relTC)&&temp.size()<len)
					temp +="C";
				else if (ranNum == 4 &&check(dna.relTG)&&temp.size()<len)
					temp +="G";
			}
			else if (ranNum == 3 &&check(dna.relC))
			{
				ranNum = (rand() % 4) + 1;
				temp += "C";
				if (ranNum == 1 &&check(dna.relCA)&&temp.size()<len)
					temp +="A";
				else if (ranNum == 2 &&check(dna.relCT)&&temp.size()<len)
					temp +="T";
				else if (ranNum == 3 &&check(dna.relCC)&&temp.size()<len)
					temp +="C";
				else if (ranNum == 4 &&check(dna.relCG)&&temp.size()<len)
					temp +="G";
			}
			else if (ranNum == 4 &&check(dna.relG))
			{
				ranNum = (rand() % 4) + 1;
				temp += "G";
				if (ranNum == 1 &&check(dna.relGA)&&temp.size()<len)
					temp +="A";
				else if (ranNum == 2 &&check(dna.relGT)&&temp.size()<len)
					temp +="T";
				else if (ranNum == 3 &&check(dna.relGC)&&temp.size()<len)
					temp +="C";
				else if (ranNum == 4 &&check(dna.relGG)&&temp.size()<len)
					temp +="G";
			}
		}
		outfile << temp << endl;
	}
	outfile.close();
}
bool check(double prob)
{
	return rand()%100<(prob*100);
}

//Source Included in readme (Trimming Whitespace)
//trim both ends
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}
// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}
// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}