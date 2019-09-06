#include <iostream>

using namespace std;

class GenQueue
{
public:
	GenQueue();
	GenQueue(int maxSize);	
	~GenQueue();
	void insert(char data);
	char remove();
	char peek();

	bool isFull();
	bool isEmpty();
	int getSize();

private:
	int front;
	int rear;
	int numElements;
	int size;
	char *myQueue;
};