#include "Algo.h"
#include <iostream>
Algo::Algo(string file)
{
	in = new IO(file,"");
	size = stoi(in->readLine());
	one = new double[size];
	two = new double[size];
	three = new double[size];
	four = new double[size];
	for (int i = 0; i < size; ++i)
	{
		string entry = in->readLine();
		if (entry !="")
		{
			one[i] = stod(entry);
			two[i] = stod(entry);
			three[i] = stod(entry);
			four[i] = stod(entry);
		}
	}
}
Algo::~Algo()
{
	delete one;
	delete two;
	delete three;
	delete four;
	delete in;
}
void Algo::run()
{
	bubbleSort(one);
	insertionSort(two);
	selectionSort(three);

	cout << "Quick Sort:" << endl;
	time_t now = time(0);
	tm* localtm = localtime(&now);
	cout << "Start: " << asctime(localtm);
	quickSort(four,0,size-1);
	now = time(0);
	localtm = localtime(&now);
	cout << "End:   " << asctime(localtm) <<endl;
}
//See readme for reference
void Algo::bubbleSort(double arr[]) 
{
	//print time
	cout << "Bubble Sort:" << endl;
	time_t now = time(0);
	tm* localtm = localtime(&now);
	cout << "Start: " << asctime(localtm);


	//check each value and swap accordingly
	for (int i = 0; i < this->size-1; i++)          
	   for (int j = 0; j < this->size-i-1; j++)  
		   if (arr[j] > arr[j+1])
		   {
		   		double temp = arr[j]; 
				arr[j] = arr[j+1]; 
				arr[j+1] = temp;
		   }

	//print time
	now = time(0);
	localtm = localtime(&now);
	cout << "End:   " << asctime(localtm) <<endl;
} 
//See readme for reference
void Algo::insertionSort(double arr[]) 
{ 
		//print time
	cout << "Insertion Sort:" << endl;
	time_t now = time(0);
	tm* localtm = localtime(&now);
	cout << "Start: " << asctime(localtm);

	for (int i = 1; i < this->size; i++) 
	{ 
		double tp = arr[i]; 
		int j = i-1;
		//this loop doesnt run if section is sorted already
		while (j >= 0 && arr[j] > tp) 
		{ 
			arr[j+1] = arr[j]; 
			j--; 
		} 
		arr[j+1] = tp; 
	} 
		//print time
	now = time(0);
	localtm = localtime(&now);
	cout << "End:   " << asctime(localtm) <<endl;
}
//See readme for reference
int Algo::part(double arr[], int lower, int upper) 
{ 
    double pv = arr[upper];   
    int i = (lower - 1);  // set smaller idx

    for (int j = lower; j <= upper- 1; j++) 
    { 
        if (arr[j] <= pv) 
        { 
            i++;    // inc idx of smaller
            double temp = arr[i]; 
			arr[i] = arr[j]; 
			arr[j] = temp;
        } 
    } 
	double temp = arr[i+1]; 
	arr[i+1] = arr[upper]; 
	arr[upper] = temp;
    return (i + 1); 
} 
//See readme for reference
void Algo::quickSort(double arr[], int lower, int upper) 
{
    if (lower < upper) 
    { 
        int pi = part(arr, lower, upper); 
        quickSort(arr, lower, pi - 1); 
        quickSort(arr, pi + 1, upper); 
    }
}
//See readme for reference
void Algo::selectionSort(double arr[]) 
{ 
		//print time
	cout << "Selection Sort:" << endl;
	time_t now = time(0);
	tm* localtm = localtime(&now);
	cout << "Start: " << asctime(localtm);

    for (int i=0; i<size-1; i++) 
    { 
        int idx = i; 
        for (int j = i+1; j < size; j++) 
          if (arr[j] < arr[idx]) 
            idx = j; 
        double temp = arr[idx]; 
		arr[idx] = arr[i]; 
		arr[i] = temp;
    }
    	//print time
    now = time(0);
	localtm = localtime(&now);
	cout << "End:   " << asctime(localtm) <<endl;
}