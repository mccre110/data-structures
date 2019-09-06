using namespace std;

template <class Type> class GenStack
{
public:
	GenStack();
	GenStack(int maxSize);
	~GenStack();
	void push(Type d);
	Type pop();
	Type peak();
	void grow();
	bool isFull();
	bool isEmpty();

	int size;
	int top;

	Type*myArray;
};

template <class Type> 
GenStack<Type>::GenStack()
{
	myArray = new Type[10];
	size = 10;
	top = -1;
}
template <class Type> 
GenStack<Type>::GenStack(int maxSize)
{
	myArray = new Type[maxSize];
	size = maxSize;
	top = -1;
}
template <class Type> 
GenStack<Type>::~GenStack()
{
	delete myArray;
}
template <class Type> 
void GenStack<Type>::push(Type d)
{
	if (!this->isFull())
	 	myArray[++top] = d;
	 else
	 	this->grow();
}
template <class Type> 
Type GenStack<Type>::pop()
{
	if (!this->isEmpty())
		return myArray[top--];
	else
		throw std::invalid_argument("Stack Empty");
}
template <class Type> 
Type GenStack<Type>::peak()
{
	if (!this->isEmpty())
		return myArray[top];
	else
		throw std::invalid_argument("Stack Empty");
	
}
template <class Type> 
void GenStack<Type>::grow()
{
	Type* newArray = new Type[size+10];
	for (int i = 0; i < size; ++i)
	{
	 	newArray[i] = myArray[i]; 
	}
	myArray = newArray;
	size+=10; 
}
template <class Type> 
bool GenStack<Type>::isFull()
{
	return (top==size-1);
}
template <class Type> 
bool GenStack<Type>::isEmpty()
{
	return (top==-1);
}
