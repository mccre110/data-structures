#include "ListNode.h"
#include <iostream>
using namespace std;

template <class Type>
class NaiveList
{
public:
	NaiveList();
	~NaiveList();

	void insertFront(Type d);
	Type removeFront();
	Type removeBack();
	Type deletePos(int pos);
	int find(Type value);

	void printList();
	unsigned int getSize();
	ListNode<Type>* remove(Type key);
	ListNode<Type> *front;
	ListNode<Type> *back;
	unsigned int size;
};

template <class Type>
NaiveList<Type>::NaiveList()
{
	back = NULL;
	front = NULL;
	size = 0;
}
template <class Type>
NaiveList<Type>::~NaiveList()
{

}
template <class Type>
unsigned int NaiveList<Type>::getSize()
{
	return size;
}
template <class Type>
void NaiveList<Type>::printList()
{
	ListNode<Type> *curr = front;
	while (curr != NULL)
	{
		cout << curr->data << endl;
		curr = curr->next;
	}

}
template <class Type>
void NaiveList<Type>::insertFront(Type d)
{
	ListNode<Type> *node = new ListNode<Type>(d);
	if (size ==0)
	{
		back = node;
	}
	else
	{
		front->prev = node;
		node->next = front;
	}
	front = node;
	++size;
	}
template <class Type>
Type NaiveList<Type>::removeFront()
{
	ListNode<Type> *temp =front;
	if (front->next ==NULL) //only node in ListNode
	{
		back = NULL;
	}
	else //MORE THAN ONE NODE
	{
		front->next->prev =NULL;
	}
	front = front->next;
	temp->next = NULL;
	Type data = temp->data;
	delete temp;
	size--;
	return data;
}
template <class Type>
Type NaiveList<Type>::removeBack()
{
	ListNode<Type> *temp =back;
	if (back->prev ==NULL) //only node in ListNode
	{
		front = NULL;
	}
	else //MORE THAN ONE NODE
	{
		back->prev->next =NULL;
	}
	back = back->prev;
	temp->prev = NULL;
	Type data = temp->data;
	delete temp;
	size--;
	return data;
}
template <class Type>
int NaiveList<Type>::find(Type value)
{
	int idx = -1;
	ListNode<Type> *curr = front;
	while (curr!=NULL)
	{
		++idx;
		if (curr->data= value)
		{
			break;
		}
		else
			curr = curr->next;
	}
	if (curr == NULL)
	{
		idx =-1;
	}
	return idx;
}
template <class Type>
Type NaiveList<Type>::deletePos(int pos)
{
	--size;
	int idx =0;
	ListNode<Type> *curr = front;
	ListNode<Type> *prev = front;
	while (idx!=pos) //pointers in correct position
	{
		prev = curr;
		curr = curr->next;
		++idx;
	}

	//found pos, now delete
	prev->next = curr->next;
	curr->next = NULL;
	Type d = curr-> data;
	delete curr;
	return d;

}
template <class Type>
ListNode<Type>* NaiveList<Type>::remove(Type key)
{
	ListNode<Type>* current = front;
	while(current->data!=key)
	{
		current = current->next;
		if (current == NULL)
			return NULL;
	}

	if (current == front)
	{
		front = current->next;
	}

	else
	{
		current->prev->next = current->next;
	}

	if(current == back)
	{
		back = current->prev;
	}

	else
	{
		current->next->prev = current->prev;
	}
	current->next = NULL;
	current ->prev = NULL;
	--size;
	return current;
}