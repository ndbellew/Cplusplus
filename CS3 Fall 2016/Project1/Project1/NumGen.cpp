#include<iomanip>
#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include<time.h>
#include<string>
#include<fstream>
#include<math.h>


using namespace std;
const int Maxnum = 10000;
const double bound = 100000;
void main()
{
	int i;
	double numbers=0.0;
	ofstream outf;
	outf.open("Numbers.txt");
	srand(time(NULL));
	outf.setf(ios::fixed);
	outf.precision(3);
	for (i = 0; i <= Maxnum-1; i++)
	{
		numbers = rand();
		if (abs(numbers) <= bound)
		{
			numbers = numbers*tan(numbers);

		outf <<setw(14)<< numbers << endl;
		}

	}

}