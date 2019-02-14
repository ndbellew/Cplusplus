/*Nathan Bellew
CS 1
Quadratic Equations*/

#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void printline(ofstream &outf, char ch, int n)
{
	int i;
	for (i = 1; i <= n; i++) outf << ch;
		outf << endl;
}
void printtitles(ofstream &outf)

{
	printline(outf, '_', 60);
	outf <<setw(35)<< "Quadratic Roots" << endl;
	printline(outf, '=', 60);
	outf << setw(6) << "A" << setw(10) << "B" << setw(10) << "C" << setw(9) << "D" << setw(12) <<
		"Root I" << setw(11) << "Root II" << endl;
	printline(outf, '-', 60);
}

double findone(double A, double B, double &root1)
{
	
	
	root1 = (-B) / (2 * A);
	

	return root1;
}

void findtwo(double A, double B, double D, double &root1, double &root2)

{
	
	root1 = ((-B) + pow(D, .5)) / (2 * A);
	root2=((-B) - pow(D, .5)) / (2 * A);
	
}

double getd( double A, double B, double C)
{
	double D;
	D = pow(B, 2) - 4 * A * C;
	

	return D;
}
void main()
{
	
	double A, B, C, D, root1, root2;
	


	ifstream inf;
	ofstream outf;
	inf.open("QuadEq.dat");
	outf.open("QuadEq.ot");
	outf.setf(ios::fixed);
	
	printtitles(outf);
	while (!inf.eof())
	{
		inf >> A >> B >> C;
		outf.precision(2);
		root1 = 0;
		root2 = 0;
		outf << setw(7)<< A << setw(10) << B << setw(10)<< C;
		D = getd(A, B, C);
		outf <<right<< setw(10) << D;

		
		outf.precision(4);
		if (D > 0)
		{
			findtwo(A, B, D, root1, root2);
			outf <<right<< setw(10) << root1 << setw(10) << root2 << endl;
		}
		else if (D == 0)
		{

			root1 = findone(A, B, root1);
			outf  <<right<< setw(10) << root1 << setw(10) << root1 << endl;
		}
		else
		{
			outf <<right<< setw(21)<< "There is no root!" << endl;
			outf.precision(2);

		}
	}
	outf.precision(2);
		printline(outf, '=', 60);
			

		

		//root1 = D - C;
		//root2 = A + B;

		

	}

