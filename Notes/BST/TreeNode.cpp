#include "TreeNode.h"
#include <cstddef>

TreeNode::TreeNode()
{
	left = NULL;
	right = NULL;
}
TreeNode::TreeNode(int k)
{
	key = k;
	left = NULL;
	right = NULL;
}
TreeNode::~TreeNode(){}
