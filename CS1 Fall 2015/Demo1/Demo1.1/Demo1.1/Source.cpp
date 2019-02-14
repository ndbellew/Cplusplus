/*
Nathan Bellew 
8/25/2015
CS1
Demo1.1
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
void main()
{
	int i, test1, test2, test3;
	double average;
	string name;
	//file statements
	ifstream inf;
	ofstream outf;
	inf.open("Demo1.dat");
	outf.open("Demo1.ot");
		for (i = 1; i <= 10; i++)
		{
			inf >> name >> test1 >> test2 >> test3;
			average = 1.0*(test1 + test2 + test3) / 3;
			outf << name << " has scores of " << test1 << ", " << test2 << ", and "
				<< test3 << " for an average of " << average << "." << endl;
		}
}