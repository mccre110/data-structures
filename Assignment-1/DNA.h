#include <iostream>
using namespace std;

class DNA
{
	public:
	//Nucleotide and Bigram Counters
	double countA; double countT; double countC; double countG; double countAA; double countTA;	double countCA;
	double countGA;	double countAT;	double countTT;	double countCT;	double countGT;	double countAC;	double countTC;
	double countCC;	double countGC;	double countAG;	double countTG;	double countCG;	double countGG;	double relA;
	double relT;	double relC;	double relG;	double relAA;	double relTA;double relCA;	double relGA;
	double relAT;	double relTT;	double relCT;	double relGT;	double relAC;	double relTC;	double relCC;	double relGC;	double relAG;	double relTG;	double relCG;	double relGG;
	double bigram;
	//DNA Class Summary Variables
	double stringNumber = 0;
	double totalcount =0;
	double avg=0.0;
	double variance=0;
	double stddev=0;
	string lengths="";

	//DNA Class Methods
	DNA();
	~DNA();
	int calculate(string input);
	void cleanup();
};
//Methods used in main
bool validateInput(string input);
void writeFileSummary();
void writeString();
double genLength();
void readFile(string fileName);
bool check(double prob);
//Methods from readme
static inline void trim(std::string &s);
static inline void ltrim(std::string &s);
static inline void rtrim(std::string &s);