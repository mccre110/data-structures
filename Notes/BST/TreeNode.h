using namespace std;

class TreeNode
{
	public:
		TreeNode();
		TreeNode(int k);
		virtual ~TreeNode();

		int key;
		TreeNode *left;
		TreeNode *right;
}; 

