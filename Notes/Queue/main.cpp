#include "GenQueue.h"
#include <iostream>

using namespace std;



int main(int argc, char const *argv[])
{
	GenQueue myQ(10);
	myQ.insert('C');
	myQ.insert('J');
	myQ.insert('M');

	while (!myQ.isEmpty())
	{
		cout << "removed" << myQ.remove() <<endl;
	}



	return 0;
}