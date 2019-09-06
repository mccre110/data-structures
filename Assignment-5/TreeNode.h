#include <cstddef>
using namespace std;

template <class Type>
class TreeNode
{
	public:
		TreeNode();
		TreeNode(Type k);
		virtual ~TreeNode();

		Type key;
		TreeNode *left;
		TreeNode *right;
}; 


template <class Type>
TreeNode<Type>::TreeNode()
{
	left = NULL;
	right = NULL;
}
template <class Type>
TreeNode<Type>::TreeNode(Type k)
{
	key = k;
	left = NULL;
	right = NULL;
}
template <class Type>
TreeNode<Type>::~TreeNode()
{
	delete left;
	delete right;
}
