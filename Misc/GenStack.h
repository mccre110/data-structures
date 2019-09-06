#include <iostream>

using namespace std;

template <class Tdough>
class GenStack
{
	public:
		GenStack();
		GenStack(int maxSize);
		~GenStack();

		void push(Tdough d);
		Tdough pop();
		Tdough peek();

		bool isFull();
		bool isEmpty();

		int size;
		int top;

		Tdough *myArray;
		Tdough *newArr;
};


template <class Tdough>
GenStack<Tdough>::GenStack()
{
	// variables get initialized to default values
	myArray = new Tdough[10]; // what default size do i set it to if im storing the ]}) in here
	size = 10;
	top = -1;
}

template <class Tdough>
GenStack<Tdough>::GenStack(int maxSize)
{
	myArray = new Tdough[maxSize];
	size = maxSize;
	top = -1;
}

template <class Tdough>
GenStack<Tdough>::~GenStack()
{
	delete myArray;
	//cout << "stack destroyed" << endl;
}

template <class Tdough>
void GenStack<Tdough>::push(Tdough d)
{
	if (!this->isFull())
	{
		myArray[++top] = d;
	}
	else
	{
		newArr = new Tdough[size+5];
		for(int i =0; i<size;i++)
		{
			newArr[i] = myArray[i];
		}
		newArr=myArray;
		size+=5;
	}
}

template <class Tdough>
Tdough GenStack<Tdough>::pop()
{
	if (!this->isEmpty())
	{
		return myArray[top--]; // decrements AFTER return statement
	}
	else
	{
		throw std::invalid_argument("This stack is empty bud!");
	}
}

template <class Tdough>
Tdough GenStack<Tdough>::peek()
{
	if (!this->isEmpty())
	{
		return myArray[top];
	}
	else
	{
			throw std::invalid_argument("This stack is empty bud!");
	}

	
}

template <class Tdough>
bool GenStack<Tdough>::isFull()
{
	return (top == size-1);
}

template <class Tdough>
bool GenStack<Tdough>::isEmpty()
{
	return (top == -1); // meaning we havent entered anything into the stack
}
