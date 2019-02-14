/*
		Created by Nathan Bellew 9/7/2016
		This program sorts numbers using bubble sort*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int arraysize = 10000;
double Ncmprs = 0;
double Ncopy = 0;
void swapem(double &a, double &b)
{
	double temp;
	temp = a;
	a = b;
	b = temp;
	Ncopy += 3;
}
void readem(double numbers[], ifstream &inf)
{
	int i = 0;
	for (i = 0; i < arraysize; i++)
	{
		inf >> numbers[i];
	}
}
void sortem(double numbers[])
{
	for (int j = 0; j < arraysize - 1; j++)
		for (int i = 0; i < arraysize - 1; i++)
		{
			Ncmprs++;
			if (numbers[i] > numbers[i + 1])
				swapem(numbers[i], numbers[i + 1]);
		}
}
void printem(double numbers[], ofstream &outf, clock_t timer)
{
	outf << "Time taken to read in then sort and swap 10,000 randomly generated numbers was " <<
		((float)timer) / CLOCKS_PER_SEC << " Second(s)" << endl;
	int row = 5;
	int incr = 1000;
	double relcopy = 0.0;
	double relcompare = 0.0;
	for (int i = 0; i < arraysize - 1; i += incr)
	{
		outf << setw(14) << numbers[i];
		i += incr;
		if (i % (row*incr) == 0)outf << endl;
		i -= incr;
	}
	outf << endl << "Amount of compares was " << Ncmprs << endl;
	outf << "Amount of copies was " << Ncopy << endl;
	relcopy = Ncopy / arraysize;
	relcompare = Ncmprs / arraysize;
	outf << "Relative number of copies is " << relcopy << endl;
	outf << "Relative number of compares is " << relcompare << endl;

}
void main()
{
	double numbers[arraysize];
	clock_t timer;
	ifstream inf;
	inf.open("Numers.txt");//Had to copy and paste numbers from one file to other in order to get it to work
	ofstream outf;
	outf.open("SrtNum.txt");
	outf.setf(ios::fixed);
	outf.precision(3);
	timer = clock();
	readem(numbers, inf);
	sortem(numbers);
	timer = clock() - 1;
	printem(numbers, outf, timer);
}
