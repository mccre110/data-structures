#include "GenStack.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	GenStack myStack(10);
	myStack.push('A');
	myStack.push('B');
	myStack.push('C');
	myStack.push('D');

	delete myStack;


	return 0;
}