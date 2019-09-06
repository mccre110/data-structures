class CalculateWait
{
public:
	//CalculateWait(int arrival, int needed);
	CalculateWait(int winNum);
	~CalculateWait();
	
	int totalWaitTime =0;
	int longestWaitTime = 0;
	int medianWaitTime;
	int averageWaitTime;
	int count;
	int countOver10;
	int windows;
	int winAvg=0;
	int *myArray;
	int *winArray;
	int longestWinTime=0;
	int winOver5=0;
	void addWin(int num);
	void calc();
	void print();
	void addWaitTime(int w);
	double findMedian(int a[], int n);

};