#include "TreeNode.h"
class BST{
	public:
		BST();
		virtual ~BST();

		void insert(int value);
		bool contains(int value);
		bool deleteNode(int value);
		bool deleteRec(int k);
		bool isEmpty();

		void printTree();
		void recPrint(TreeNode *node);//inorder trav
		TreeNode* getSucc(TreeNode *d);

	private:
		TreeNode *root;
};

