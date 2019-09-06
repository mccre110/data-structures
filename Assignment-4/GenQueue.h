#include <iostream>
#include "NaiveList.h"
using namespace std;

template <class Type>class GenQueue
{
public:
	GenQueue();	
	~GenQueue();
	void insert(Type data);
	Type remove();
	Type peek();

	bool isFull();
	bool isEmpty();
	int getSize();

private:
	NaiveList<Type>* list;
};

template <class Type>
GenQueue<Type>::GenQueue()
{
	list = new NaiveList<Type>();
}
template <class Type>
GenQueue<Type>::~GenQueue()
{
	//delete list;
}
template <class Type>
void GenQueue<Type>::insert(Type data)
{
	list->insertFront(data);
}
template <class Type>
Type GenQueue<Type>::remove()
{
	if (!this->isEmpty())
		return list->removeBack();
}
template <class Type>
Type GenQueue<Type>::peek()
{
	if (!this->isEmpty())
		return list->back;
}
template <class Type>
bool GenQueue<Type>::isEmpty()
{
	return (list->back==NULL);
}