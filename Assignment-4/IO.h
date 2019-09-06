#include <iostream>
#include <fstream>
using namespace std;

class IO
{
public:
	IO(string in, string out);
	~IO();
	string readLine();
	void writeLine(string line);
	bool lineCheck();
	ofstream outputFile;
	ifstream inputFile;
};