#include "IO.h"
class Algo
{
public:
	Algo(string file);
	~Algo();
	void bubbleSort(double arr[]);
	void insertionSort(double arr[]);
	int part(double arr[], int lower, int upper);
	void quickSort(double arr[], int lower, int upper);
	void selectionSort(double arr[]);
	void run();
	IO *in;
	double *one;
	double *two;
	double *three;
	double *four;
	int size;
	
};