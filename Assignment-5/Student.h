#include <iostream>
using namespace std;

class Student
{
public:
	Student(string name, string level, string major, int adv, double gpa);
	Student(string name, string level, string major, int adv, double gpa, int id);
	Student(int id);
	Student();
	~Student();
	void setAdv(int i);

	int id;
	string name;
	string level;
	string major;
	double gpa;
	int adv;
	friend ostream& operator<<(ostream& os, const Student& s);
	friend bool operator> (const Student &s1, const Student &s2);
	friend bool operator< (const Student &s1, const Student &s2);
	friend bool operator== (const Student &s1, const Student &s2);
	friend bool operator!= (const Student &s1, const Student &s2);
};