class NaiveList
{
public:
	NaiveList();
	~NaiveList();

	void insertFront(int d);
	int removeFront();
	int removeBack();
	int deletePos(int pos);
	int find(int value);

	void printList();
	unsigned int getSize();
	ListNode* remove(int key);

private:
	ListNode *front;
	ListNode *back;
	unsigned int size;
	
};