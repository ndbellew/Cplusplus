/*
Last Updated by Nathan Bellew
Last Updated - 10/10/2016
for Intro to Algorithms, Payne
Program #3
*/
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const char maxset = 'Z'+1;
void InitArrays(bool Univ[], bool Vowel[], bool MyName[]);
void Printem(bool print[], ofstream &outf);
void Union(bool Vowel[], bool MyName[], ofstream &outf);
void Intersect(bool Vowel[], bool MyName[], ofstream &outf);
void Difference(bool Vowel[], bool MyName[], ofstream &outf);
void Equal(bool Vowel[], bool MyName[], ofstream &outf);
bool Subset(bool A[], bool B[], ofstream &outf);
void setem(bool MyName[]);
void main()
{
	ofstream outf;
	outf.open("Print.ot");
	bool Univ[maxset];
	bool Vowel[maxset];
	bool MyName[maxset];
	InitArrays(Univ, Vowel, MyName);
	setem(MyName);
		outf << "Letters of the Alphebet\n";
	Printem(Univ, outf);
		outf << "Vowels of the Alphabet\n";
	Printem(Vowel, outf);
		outf << "Letters of my name (organized)\n";
	Printem(MyName, outf);
		outf << "Unions" << endl;
	Union(Vowel, MyName, outf);
		outf << "Vowels and My Name Unionized\n";
		outf << "Intersections" << endl;
	Intersect(Vowel, MyName, outf);
		outf << "Vowels and My Name Intersected\n";
		outf << "Differences" << endl;
	Difference(Vowel, MyName, outf);
		outf << "Vowels and My Name Differenced" << endl;
		outf << "Checking to see if Sets are equal!\n";
	Equal(Vowel, MyName, outf);
		outf << "Checking to see if Sets are equal!\n";
	Equal(Vowel, Vowel, outf);
	outf << "Checking to see if sets are subsets of eachother\n";
		if (Subset(Vowel, MyName, outf))
			outf << "These are subsets\n";
		else
			outf << "These are not subsets\n";
		outf << "Checking to see if sets are subsets of eachother\n";
		if(Subset(Vowel,Univ, outf))
			outf << "These are subsets\n";
		else
			outf << "These are not subsets\n";
}
void setem(bool MyName[])//This needs to be in a file
{

	ifstream inf;
	inf.open("Name.txt");
	char ch;
	while(!inf.eof())
	{
		inf >> ch;
		MyName[ch] = true;
	}
}
void InitArrays(bool Univ[],bool Vowel[],bool MyName[])
{
	for (char i = 'A'; i <= 'Z'; i++)
	{
		cout << "mnsa\n";
		Univ[i] = 1;
		Vowel[i] = 0;
		MyName[i] = 0;
	}
	Vowel['A'] =1;
	Vowel['E'] = 1;
	Vowel['I'] = 1;
	Vowel['O'] = 1;
	Vowel['U'] = 1;
}
void initBasicArray(bool Basic[])
{
	for (char i = 'A'; i <= 'Z'; i++)
	{
		Basic[i] = false;
	}
}
void Printem(bool print[], ofstream &outf)
{
	for (char i = 'A'; i <= 'Z'; i++)
	{
		if (print[i] == 1) outf << i;
	}
	outf << endl;
}
void Union(bool foob1[], bool foob2[], ofstream &outf)
{
	bool Unn[maxset];
	initBasicArray(Unn);
	for (char i = 'A'; i <= 'Z'; i++)
		if (foob1[i] ==true|| foob2[i]==true)Unn[i]=true;
	Printem(Unn, outf);
}
void Intersect(bool Vowel[], bool MyName[], ofstream &outf)
{
	bool Inter[maxset];
	initBasicArray(Inter);
	for (char i = 'A'; i <= 'Z'; i++)
		if (Vowel[i] == true && MyName[i] == true)Inter[i] = true;
	Printem(Inter, outf);
}
void Difference(bool Vowel[], bool MyName[], ofstream &outf)
{
	bool Diff[maxset];
	initBasicArray(Diff);
	for (char i = 'A'; i <= 'Z'; i++)
		if (Vowel[i] != MyName[i])Diff[i] = true;
	Printem(Diff, outf);
}
void Equal(bool rray1[], bool rray2[], ofstream &outf)
{
	char i;
	int j=0;
	bool Equal[maxset];
	initBasicArray(Equal);
	for (i = 'A'; i < 'Z'; i++)
		if (rray1[i] != rray2[i])
		{
			outf << "Arrays are not equal!\n";
			i = 'Z';
			j = 1;
		}
	if(j!=1)outf << "The arrays are equal!\n";
}
bool Subset(bool A[], bool B[], ofstream &outf)
{
	for (char i = 'A'; i <= 'Z'; i++)
		if (A[i] == true && A[i] != B[i])
			return false;
	return true;
}
/*
Union is add all of the letters together natheiuo
Intersect is if they shar the same letters A
difference remove one from other NTH
Equal is if false in same place, send myname and vowel to be equal
*/