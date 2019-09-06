#include "Faculty.h"

Faculty::Faculty(string name, string level, string dept)
{
	this->name = name;
	this->level = level;
	this->dept = dept;
	adv = new NaiveList<int>();
	id = rand()%10000+6000;
}
Faculty::Faculty(string name, string level, string dept, int id)
{
	this->name = name;
	this->level = level;
	this->dept = dept;
	adv = new NaiveList<int>();
	this->id = id;
}
Faculty::Faculty(int id)
{
	this->id = id;
}
Faculty::Faculty(){}
void Faculty::addAdv(int id)
{
	adv->insertFront(id);
}
void Faculty::delAdv(int id)
{
	adv->remove(id);
}
Faculty::~Faculty(){}
ostream& operator<<(ostream& os, const Faculty& f)  
{  
    os << f.name << '/' << f.level << '/' << f.dept<<'/'<< f.id << '-';
    for (int i=0; i<f.adv->size; i++)
    {
    	int x = f.adv->removeBack();
    	os << x <<'|';
    	f.adv->insertFront(x);
    }  
    return os;
}
bool operator> (const Faculty &s1, const Faculty &s2)
{
    return s1.id > s2.id;
}
bool operator< (const Faculty &s1, const Faculty &s2)
{
    return s1.id < s2.id;
}  
bool operator== (const Faculty &s1, const Faculty &s2)
{
    return s1.id == s2.id;
}
bool operator!= (const Faculty &s1, const Faculty &s2)
{
    return s1.id != s2.id;
}
