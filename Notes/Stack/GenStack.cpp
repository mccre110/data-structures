#include "GenStack.h"
#include <iostream>

using namespace std;

GenStack::GenStack()
{
	myArray = new char[10];
	size = 10;
	top = -1;
}
GenStack::GenStack(int maxSize)
{
	myArray = new char[maxSize];
	size = maxSize;
	top = -1;
}
GenStack::~GenStack()
{
	delete myArray;
	cout << "Stack Gone" << endl;
}
void GenStack::push(char d)
{
	// check if not isFull
	//error checkin 
	myArray[++top] = d;
}
char GenStack::pop()
{
	//error check
	return myArray[top--];
}
char GenStack::peak()
{
	//check isEmpty
	return myArray[top];
}
bool GenStack::isFull()
{
	return (top==size-1);
}
bool GenStack::isEmpty()
{
	return (top==-1);
}
