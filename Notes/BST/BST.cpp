#include "BST.h"
#include <cstddef>
#include <iostream>

BST::BST()
{
	root = NULL;
}
BST::~BST()
{
	//iterate and delete
}
void BST::printTree()
{
	recPrint(root);
}

bool BST::isEmpty()
{
	return root ==NULL;
}
void BST::recPrint(TreeNode *node)
{
	if (node == NULL)
		return;
	recPrint(node->left);
	cout << node->key <<endl;

	recPrint(node->right);
	cout << node->key <<endl;
}

void BST::insert(int value)
{
	//check for dup
	TreeNode *node = new TreeNode(value);

	if(isEmpty())
	{
		root=node;
	}
	else
	{
		TreeNode* current = root;
		TreeNode *parent;
		while (true)
		{
			parent = current;

			if (value < current->key)
			{
				current = current->left;
				if (current ==NULL)
				{
					parent->left=node;
					break;
				}
			}
			else 
			{
				current = current->right;
				if (current ==NULL)
				{
					parent->right=node;
					break;
				}
			}
		}
	}
}
bool BST::contains(int value)
{
	if (root == NULL)
		return false;
	else
	{
		TreeNode *current = root;
		while(current->key!= value)
		{
			if (current = NULL)
				return false;
			if (value < current->key)
				current = current->left;
			else
				current = current->right;
		}
	}
}

bool BST::deleteRec(int k)
{
	if (!contains(k))
		return false;
	
	TreeNode* current = root;
	TreeNode* parent = root;
	bool isLeft = true;

	while(current->key!=k)
	{
		parent = current;
		if (k < current->key)
		{
			isLeft = true;
			current = current->left;
		}
		else 
		{
			isLeft = false;
			current = current->right;
		} 
	}
	if (current->left ==NULL && current->right==NULL)
	{
		if (current ==root)
			root = NULL;
		else if (isLeft)
			parent->left ==NULL;
		else
			parent->right ==NULL;
	}
	else if (current->right==NULL)
	{
		if (current ==root)
			root = current->left;
		else if(isLeft)
			parent->left = current->left;
		else
			parent->right = current->right;
	}
	else if (current->left==NULL)
	{
		if (current ==root)
			root = current->right;
		else if(isLeft)
			parent->right = current->right;
		else
			parent->left = current->left;
	}
	else
	{
		TreeNode* succ = getSucc(current);

		if (current ==root)
			root = succ;
		else if(isLeft)
			parent->left = succ;
		else
			parent->right = succ;

		succ->left = current->left;
		return true;
	}

}

TreeNode* BST::getSucc(TreeNode* d)
{
	TreeNode* sp = d;
	TreeNode* succ = d;
	TreeNode* current = d->right;

	while(current!=NULL)
	{
		sp = succ;
		succ = current;
		current = current->left;
	}

	if (succ!=d->right)
	{
		sp->left = succ->right;
		succ->right = d->right;
	}

	return succ;
}