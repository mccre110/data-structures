#include "NaiveList.h"

using namespace std;

NaiveList::NaiveList()
{
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
	node->next = front;
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