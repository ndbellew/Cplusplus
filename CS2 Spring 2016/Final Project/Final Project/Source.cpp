#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>  

using namespace std;
const int maxnum = 100000;
/*void bubblesort(const double numbers[], int length)
{
	for (int i = 0; i<length; i++)
		for (int j = 0; j < length; j++)
		{
			if (numbers[i]>numbers[i + 1])
				swap(numbers[i], numbers[i + 1]);
		}
}*/
int minLocation(const int numbers[], int first, int last)
{
	int loc, minIndex;
	minIndex = first;
	for (loc = first + 1; loc <= last; loc++)
		if (numbers[loc] < numbers[minIndex])
			minIndex = loc;
	return minIndex;
}

void swapem(int numbers[], int first, int second)
{
	int temp;
	temp = numbers[first];
	numbers[first] = numbers[second];
	numbers[second] = temp;
}
void selectionsort(int numbers[], int length)
{
	int loc, minIndex;
	for (loc = 0; loc < length; loc++)
	{
		minIndex = minLocation(numbers, loc, length - 1);
		swapem(numbers, loc, minIndex);
	}
}
void insertionsort(int numbers[], int length)
{
	int i, j, temp;
	for ( i = 1; i < length; i++)
	{
		 j = i;
		 while (j>0 && numbers[j - 1] > numbers[j])
		 {
			 temp = numbers[j];
			 numbers[j] = numbers[j - 1];
			 numbers[j - 1] = temp;
			 j--;
		 }
		
	}
}
int partition(int numbers[], int first, int last)
{
	double pivot;
	int index, smallIndex;
	swapem(numbers, first, (first + last) / 2);
	pivot = numbers[first];
	smallIndex = first;

	for (index = first + 1; index <= last; index++)
		if (numbers[index] < pivot)
		{
			smallIndex++;
			swapem(numbers, smallIndex, index);
		}
	swapem(numbers, first, smallIndex);
	return smallIndex;
}
void recQuickSort(int numbers[], int first, int last)
{
	int pivotLocation;
	if (first < last)
	{
		pivotLocation = partition(numbers, first, last);
		recQuickSort(numbers, first, pivotLocation - 1);
		recQuickSort(numbers, pivotLocation + 1, last);
	}
}
void quicksort(int numbers[], int length)
{
	recQuickSort(numbers, 0, length - 1);
}
void mergesort()
{

}
int sequentialSearch(const int numbers[], int length, const int num)
{
	int loc;
	bool found = false;
	loc = 0;
	while (loc < length&& !found)
	{
		if (numbers[loc] == num)
			found = true;
		else
			loc++;
	}
	if (found)
		return loc;
		else
			return -1;

}
void BinarySearch(const int numbers[], int length, const int num)
{
	int first = 0;
	int last = length - 1;
	int mid;
	bool found = false;
	while (first <= last&& !found)
	{
		mid = (first + last) / 2;
		if (numbers[mid] == num)
			found = true;
		else if (numbers[mid] > num)
			last = mid - 1;
		else
			first = mid + 1;
	}
	if (found)
		cout<< mid<<endl;
	else
	{
		cout<<"Number not Found!\n";
	}
	
}
void MakeNewArray(int numbers[], int &length)
{
	int i = 0;
	int num = 0;
	while (i<maxnum)
	{
		num = rand() % 100 + 1;
		numbers[i] = num;
		i++;
	}
	length = i;
}
void main()
{
	//ofstream outf;
	clock_t t;
	//outf.open("outfile.txt");
	int searchItem;
	searchItem = rand() % 100 + 1;
	int numbers[maxnum];
	int num=0;
	int length=0;
	int i = 0;
	t = clock();
	MakeNewArray(numbers, length);
	selectionsort(numbers, length);
	BinarySearch(numbers, length, searchItem);
	sequentialSearch(numbers, length, searchItem);
	t = clock() - 1;
	printf("time= %d Clicks (%f seconds)", t, ((float)t) / CLK_TCK);
	t = clock();
	MakeNewArray(numbers, length);
	insertionsort(numbers, length);
	t = clock() - 1;
	printf( "time= %d Clicks (%f seconds)", t, ((float)t) / CLK_TCK );
	MakeNewArray(numbers, length);
	/*for (int i = 0; i < length - 1; i++)
		cout << numbers[i] << endl;*/
	cout << endl;
	system("pause");
	}
