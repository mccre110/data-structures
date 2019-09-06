#include "DNA.h"
#include <math.h>
using namespace std;

DNA::DNA(){}
DNA::~DNA(){}

//Loops through input string for counting nucleotides and tracking lengths
int DNA::calculate(string input)
{
	
	stringNumber++;
	totalcount += input.size();
	lengths += (to_string(input.size())+" ");

	//Reset bigram for each string
	char j = '\0';
	//Count nucleotides and bigrams
	for (int i=0; i<input.size(); i++)
	{
		if(input[i] == 'A')
		{
			if (j=='A')
				countAA++;
			else if (j == 'T')
				countTA++;
			else if (j == 'C')
				countCA++;
			else if (j == 'G')
				countGA++;
			countA++;
		}			
		else if (input[i] == 'T')
		{
			if (j=='A')
				countAT++;
			else if (j == 'T')
				countTT++;
			else if (j == 'C')
				countCT++;
			else if (j == 'G')
				countGT++;
			countT++;
		}			
		else if (input[i] == 'C')
		{
			if (j=='A')
				countAC++;
			else if (j == 'T')
				countTC++;
			else if (j == 'C')
				countCC++;
			else if (j == 'G')
				countGC++;
			countC++;
		}
		else if (input[i] == 'G')
		{
			if (j=='A')
				countAG++;
			else if (j == 'T')
				countTG++;
			else if (j == 'C')
				countCG++;
			else if (j == 'G')
				countGG++;
			countG++;
		}
		j = input[i];
	}
}
//Completes Summary Calculations
void DNA::cleanup()
{
	double num =0;
	avg = totalcount/stringNumber;
	totalcount = countA+countT+countC+countG;
    string tempNum = "";

    //Loops through string of lengths for input in standard deviation
    //Delimiter is spaces so at space calculate and then clear number
    //this accounts for double digit numbers
	for (int i = 0; i < lengths.size(); i++)
	{
		if (lengths[i] !=' ')
		{
			tempNum +=lengths[i];
		}
		else if (lengths[i] ==' ')
		{
			int len = stoi(tempNum);
			num+= pow((len - avg),2);
			tempNum = "";
		}		
	}
	//Standard dev and Variance Calc
	stddev = sqrt(num/stringNumber);
	variance = pow(stddev,2);

	//Totals bigram count
	bigram = countAA+countTA+countCA+countGA+countAT+countTT+countCT+countGT+countAC+countTC+countCC+countGC+countAG
			+countTG+countCG+countGG;
	//Finds Relative Prob
	totalcount = countA+countT+countC+countG;
	relA = countA/totalcount;
	relT = countT/totalcount;
	relC = countC/totalcount;
	relG = countG/totalcount;
	relAA = countAA/bigram;
	relTA = countTA/bigram;
	relCA = countCA/bigram;
	relGA = countGA/bigram;
	relAT = countAT/bigram;
	relTT = countTT/bigram;
	relCT = countCT/bigram;
	relGT = countGT/bigram;
	relAC = countAC/bigram;
	relTC = countTC/bigram;
	relCC = countCC/bigram;
	relGC = countGC/bigram;
	relAG = countAG/bigram;
	relTG = countTG/bigram;
	relCG = countCG/bigram;
	relGG = countGG/bigram;
}
