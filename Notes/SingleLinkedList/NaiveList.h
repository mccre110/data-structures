class NaiveList
{
public:
	NaiveList();
	~NaiveList();

	void insertFront(int d);
	int removeFront();
	int deletePos(int pos);
	int find(int value);

	void printList();
	unsigned int getSize();

private:
	ListNode *front;
	unsigned int size;
	
};