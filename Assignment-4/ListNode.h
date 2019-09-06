#include <stddef.h>
using namespace std;

template <class Type>
class ListNode
{
public:
	ListNode();
	ListNode(Type d);
	~ListNode();

	Type data;
	ListNode *next;
	ListNode *prev;
	
};

template <class Type>
ListNode<Type>::ListNode(){}

template <class Type>
ListNode<Type>::ListNode(Type d)
{
	data = d;
	prev = NULL;
	next = NULL; //nullptr
}
template <class Type>
ListNode<Type>::~ListNode()
{
	
}