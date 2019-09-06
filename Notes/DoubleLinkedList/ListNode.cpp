#include "ListNode.h"
using namespace std;



ListNode::ListNode()
{

}

ListNode::ListNode(int d)
{
	data = d;
	prev = NULL;
	next = NULL; //nullptr
}
ListNode::~ListNode()
{
	
}