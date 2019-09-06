#include <iostream>
#include <fstream>
using namespace std;

class Board 
{
public:
	Board(int height, int length, double density, int m);
	Board(string fileName, int m);
	~Board();
	void printBoard();
	bool check(double prob);
	void readFile(string fileName);
	void setCell(int h, int l, char status);
	char getCell(int h, int l);
	char getCellClassic(int h, int l);
	char getCellMirror(int h, int l);
	char getCellDonut(int h, int l);
	void update();
	int mode;
	int height;
	int length;
	char**genInt;
	char**genNext;
	ofstream outfile;

private:

};