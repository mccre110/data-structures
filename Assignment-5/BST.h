#include "TreeNode.h"
#include <cstddef>
#include <iostream>
#include <fstream>
template <class Type>
class BST{
	public:
		BST();
		virtual ~BST();

		void insert(Type value);
		bool contains(Type value);
		bool deleteNode(Type value);
		bool deleteRec(Type k);
		bool isEmpty();
		Type search(Type value);
		void printTree();
		void recPrint(TreeNode<Type> *node);//inorder trav
		TreeNode<Type>* getSucc(TreeNode<Type> *d);
		void treeToFile(ofstream& file);
		void treeToFile(TreeNode<Type>* root, ofstream& file);

	private:
		TreeNode<Type> *root;
};
template <class Type>
BST<Type>::BST()
{
	root = NULL;
}
template <class Type>
BST<Type>::~BST()
{
	while (root !=NULL)
	{
		deleteRec(root->key);
	}
}
template <class Type>
void BST<Type>::printTree()
{
	recPrint(root);
}
template <class Type>
bool BST<Type>::isEmpty()
{
	return root ==NULL;
}
template <class Type>
void BST<Type>::recPrint(TreeNode<Type> *node)
{
	if (node == NULL)
		return;
	recPrint(node->left);
	cout << node->key <<endl;

	recPrint(node->right);
	//cout << node->key <<endl;
}
template <class Type>
void BST<Type>::insert(Type value)
{
	//check for dup
	TreeNode<Type> *node = new TreeNode<Type>(value);

	if(isEmpty())
	{
		root=node;
	}
	else
	{
		TreeNode<Type>* current = root;
		TreeNode<Type>* parent;
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
template <class Type>
bool BST<Type>::contains(Type value)
{
	if (root == NULL)
		return false;
	else
	{
		TreeNode<Type> *current = root;
		while(current->key != value)
		{
			if (current == NULL)
				return false;
			if (value < current->key)
				current = current->left;
			else
				current = current->right;
		}
		return true;
	}
}
template <class Type>
Type BST<Type>::search(Type value)
{
	TreeNode<Type> *current = root;
	while(current->key != value)
	{
		if (value < current->key)
			current = current->left;
		else
			current = current->right;
	}
	return current->key;
}


template <class Type>
bool BST<Type>::deleteRec(Type k)
{
	if (!contains(k))
	 	return false;
	
	TreeNode<Type>* current = root;
	TreeNode<Type>* parent = root;
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
			parent->left =NULL;
		else
			parent->right =NULL;
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
		TreeNode<Type>* succ = getSucc(current);

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
template <class Type>
TreeNode<Type>* BST<Type>::getSucc(TreeNode<Type>* d)
{
	TreeNode<Type>* sp = d;
	TreeNode<Type>* succ = d;
	TreeNode<Type>* current = d->right;

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
template <class Type>
void BST<Type>::treeToFile(ofstream& file)
{
    return treeToFile(root, file);
}
template <class Type>
void BST<Type>::treeToFile(TreeNode<Type>* root, ofstream& file)
{   
    if (root == NULL) {
        file << "#" << endl;
        return;
    }
    file << root->key << endl;
    treeToFile(root->left, file);
    treeToFile(root->right, file);
}