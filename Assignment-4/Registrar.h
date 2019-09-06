#include "CalculateWait.h"
#include <iostream>
#include "IO.h"
#include "GenQueue.h"
#include "Student.h"
class Registrar
{
public:
	Registrar(string filename);
	~Registrar();
	void addStudent(int arrive, int time);
	void sim();
	void print();
	int tick;
	int time;
	IO* fi;
	Student* array;
	GenQueue<Student>* line;
	CalculateWait* wait;
	int windowCount;
	string fLine;
	bool ck;
	bool loop;

	
};