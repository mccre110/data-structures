#include "Student.h"

Student::Student(string name, string level, string major, int adv, double gpa)
{
	this->name = name;
	this->level = level;
	this->major = major;
	this->adv = adv;
	this->gpa = gpa;
	id = rand()%5000+1000;
}
Student::Student(string name, string level, string major, int adv, double gpa, int id)
{
	this->name = name;
	this->level = level;
	this->major = major;
	this->adv = adv;
	this->gpa = gpa;
	this->id = id;
}
Student::Student()
{

}
Student::Student(int id)
{
	this->id = id;
}
Student::~Student()
{

}
void Student::setAdv(int i)
{
	adv = i;
}
ostream& operator<<(ostream& os, const Student& s)  
{  
    os <<s.name<<'/'<< s.level<<'/'<<s.major<<'/'<<s.adv<<'/'<<s.gpa<<'/'<<s.id;  
    return os;  
}
bool operator> (const Student &s1, const Student &s2)
{
    return s1.id > s2.id;
}
bool operator< (const Student &s1, const Student &s2)
{
    return s1.id < s2.id;
}  
bool operator== (const Student &s1, const Student &s2)
{
    return s1.id == s2.id;
}
bool operator!= (const Student &s1, const Student &s2)
{
    return s1.id != s2.id;
}

