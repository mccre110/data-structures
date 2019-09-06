#include "NaiveList.h"
#include <iostream>
using namespace std;
class Faculty
{
public:
	Faculty(string name, string level, string dept);
	Faculty(string name, string level, string dept, int id);
	Faculty(int id);
	Faculty();
	~Faculty();
	void addAdv(int id);
	void delAdv(int id);
	int id;
	string name;
	string level;
	string dept;
	NaiveList<int>* adv;

	friend ostream& operator<<(ostream& os, const Faculty& f);
	friend bool operator> (const Faculty &s1, const Faculty &s2);
	friend bool operator< (const Faculty &s1, const Faculty &s2);
	friend bool operator== (const Faculty &s1, const Faculty &s2);
	friend bool operator!= (const Faculty &s1, const Faculty &s2);

};