#include "CalculateWait.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

CalculateWait::CalculateWait(int winNum)
{
	windows = winNum;
	winArray= new int[winNum];
	myArray= new int[0];
}

CalculateWait::~CalculateWait(){}

void CalculateWait::addWaitTime(int w) //takes in wait time as a parameter
{
	totalWaitTime+= w; // adds that specific wait time to the TOTAL wait time
	count++;
	if (w > 10) // checks the amounts of wait times over 10 ticks
		countOver10++;

	if (w > longestWaitTime) // compares each wait time to find the longest wait times
		longestWaitTime = w;

	//Increase Array Size by 1
	int* newArray = new int[sizeof(myArray)+1]; // bc you cant grow the size of an array we create a new one and add that
												// to maske the size bigger (if the line grows ya know)
	for (int i = 0; i < sizeof(myArray); ++i)
	{
	 	newArray[i] = myArray[i]; 
	}
	myArray = newArray;
	
	myArray[count-1] =w; // this actually adds the new value to the array
}
void CalculateWait::addWin(int num)
{
	winArray[num]++;
}
void CalculateWait::print()
{
	cout << "Mean Wait Time: " << averageWaitTime << endl;
	cout << "Median Wait Time: " << medianWaitTime << endl;
	cout << "Longest Wait Time: " << longestWaitTime << endl;
	cout << "Sudents Waiting Over 10 mins Count: " << countOver10 << endl;
	cout << "Mean Window Idle Time: " << winAvg << endl;
	cout << "Longest Window Idle Time: " << longestWinTime << endl;
	cout << "Window Idle Over 5 mins Count: " << winOver5 << endl;
}
void CalculateWait::calc()
{
	//Average Student Calc
	averageWaitTime = totalWaitTime/count; // calculates mean wait time 

	//Median Student Calc
	medianWaitTime = findMedian(myArray, count); // calls methods to find median

	//Window Calc
	int total=0;
	for (int i = 0; i < windows; ++i)
	{
		total += winArray[i];
		if (winArray[i]>5) // checks each window time to see if its over 5 
			winOver5++;
		if (winArray[i]>longestWinTime) // checks each time@window to see whats the longest time
		{
			longestWinTime=winArray[i];
		}
	}
	//Average Window Calc
	winAvg = total/windows;
}

double CalculateWait::findMedian(int a[], int n) // https://www.includehelp.com/cpp-programs/sort-an-array-in-descending-order.aspx
{ 
	int temp;

    for (int i = 0; i < n; i++) // sorts the array in ascending order
    	for (int j = i+1; j < n; j++)
    		if (a[i] < a[j])
    		{
    			temp = a[i];
    			a[i]=a[j];
    			a[j]=temp;

    		}
    
    if (n % 2 != 0) // if the array isnt even then it averages the two middle numbers
       return (double)a[n/2]; 
      
    return (double)(a[(n/2)-1] + a[n/2])/2.0; // finds the median
}