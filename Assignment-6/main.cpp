#include "Algo.h"
#include <iostream>


int main(int argc, char const *argv[])
{
	//good input
	if (argc>1)
	{
		//make and run algos
		Algo t = Algo(argv[1]);
		t.run();
	}
	//bad command line input
	else
		cout << " Enter a vaild file name."<<endl;
	return 0;
}