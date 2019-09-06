#include "GenQueue.h"

using namespace std;

GenQueue::GenQueue()
{

}
GenQueue::GenQueue(int maxSize)
{
	myQueue = new char[maxSize];
	size = maxSize;
	front = 0;
	rear = -1;
	numElements = 0;
}

void GenQueue::insert(char data)
{
	if (!this.isFull)
	{
		if (rear == size-1)
		{
			rear =-1;
		}
		myQueue[++rear] = data;
		numElements++;
	}
}
char GenQueue::remove()
{
	if (!this.isEmpty)
	{
		char c = '\0';
		c = myQueue[front];
		front++;

		if (front = size)
		{
			front =0;
		}
		
	
	}
}
char GenQueue::peek()
{
	return myQueue[front];
}
bool GenQueue::isEmpty()
{
	return (numElements==0);
}
