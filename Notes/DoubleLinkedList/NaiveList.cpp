#include "NaiveList.h"

using namespace std;

NaiveList::NaiveList()
{
	back = NULL;
	front = NULL;
	size = 0;
}

NaiveList::~NaiveList()
{

}
unsigned int NaiveList::getSize()
{
	return size;
}
void NaiveList::printList()
{
	ListNode *curr = front;
	while (curr != NULL)
	{
		cout << curr->data << endl;
		curr = curr->next;
	}

}
void NaiveList::insertFront(int d)
{
	++size;
	ListNode *node = new ListNode(d);
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
}

int NaiveList::removeFront()
{
	--size;
	int temp = front->data;
	ListNode *ft = front;
	front = front->next;
	ft->next = NULL;
	delete ft;
	return temp;
}
int NaiveList::find(int value)
{
	int idx = -1;
	ListNode *curr = front;
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
int NaiveList::deletePos(int pos)
{
	--size;
	int idx =0;
	ListNode *curr = front;
	ListNode *prev = front;
	while (idx!=pos) //pointers in correct position
	{
		prev = curr;
		curr = curr->next;
		++idx;
	}

	//found pos, now delete
	prev->next = curr->next;
	curr->next = NULL;
	int d = curr-> data
	delete curr;
	return d;

}
int NaiveList::removeFront()
{
	ListNode*temp =front;
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
	int data = temp->data;
	delete temp;
	size--;
	return data;
}
int NaiveList::removeBack()
{
	ListNode*temp =back;
	if (back->prev ==NULL) //only node in ListNode
	{
		back = NULL;
	}
	else //MORE THAN ONE NODE
	{
		back->prev->next =NULL;
	}
	back = back->prev;
	temp->prev = NULL;
	int data = temp->data;
	delete temp;
	size--;
	return data;
}
int NaiveList::remove(int key)
{
	ListNode* current = front;
	while(current->data!=key)
	{
		current = current->next;
		if (current = NULL)
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
		back = curren->prev;
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