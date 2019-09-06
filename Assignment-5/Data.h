#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"
#include <iostream>

class Data
{
public:
	Data();
	~Data();
	void printS();
	void printF();
	void findS();
	void findF();
	void getAdvisor();
	void getStuds();
	void addStud();
	void delStud();
	void addFac();
	void delFac();
	void changeAdv();
	void remAdv();
	void rollback();
	void run(string s);
	void save();
	void getFiles();

	GenStack<BST<Student>> *studStack;
	GenStack<BST<Faculty>> *facStack;

	BST<Student> *masterStudent;
	BST<Faculty> *masterFaculty;
};