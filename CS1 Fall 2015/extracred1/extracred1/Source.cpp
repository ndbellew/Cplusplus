/*
Nathan Bellew
Extra Credit
Matrix
*/
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int maxr = 3;
const int maxc = 3;

void initem(int A[maxr][maxc], int B[maxr][maxc], int C[maxr][maxc])
{
	int i;
	for (i = 0; i < maxc; i++)
		for (int j = 0; j < maxc; j++)
		{
			A[i][j] = 0;
			B[i][j] = 0;
			C[i][j] = 0;
		}
}
void readem(int A[maxr][maxc], int B[maxr][maxc])
{
	fstream inf;
	inf.open("ec1.dat");
	for (int i = 0; i < maxr; i++)
		for (int j = 0; j < maxc; j++)
		{
			inf >> A[i][j];
		}
	for (int i = 0; i < maxr; i++)
		for (int j = 0; j < maxc; j++)
		{
			inf >> B[i][j];
		}
}
void writem(int A[maxr][maxc], int B[maxr][maxc], ofstream &outf)
{
	int i, j;
	outf << "//Step 1: write out the originals" << endl;
	outf << "A =" << endl;
	for (i = 0; i < maxr; i++)
	{
		for (j = 0; j < maxc; j++)outf << A[i][j]<<"  ";
		outf << endl;
	}
	outf << endl;
	outf << "B =" << endl;
	for (i = 0; i < maxr; i++)
	{
		for (j = 0; j < maxc; j++)outf << B[i][j]<<"  ";
		outf << endl;
	}
}
void addem(int A[maxr][maxc], int B[maxr][maxc], int C[maxr][maxc])
{
	int i,j;
	for (i = 0; i < maxr; i++)
		for (j = 0; j< maxc; j++)
			C[i][j] = A[i][j] + B[i][j];

}
void subtractem(int A[maxr][maxc], int B[maxr][maxc], int C[maxr][maxc])
{
	int i, j;
	for (i = 0; i < maxr; i++)
		for (j = 0; j< maxc; j++)
			C[i][j] = A[i][j] - B[i][j];
}
void matrixmulti(int A[maxr][maxc], int B[maxr][maxc], int C[maxr][maxc])
{
	int i, j, k;
	for (i = 0; i < maxr; i++)
		for (j = 0; j < maxr; j++)
		{
			C[i][j] = 0;
			for (k = 0; k < maxr; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}

}
void scalarmulti(int A[maxr][maxc], int B[maxr][maxc], int C[maxr][maxc])
{
	int i, j;
	for (i = 0; i < maxr; i++)
		for (j = 0; j < maxr; j++)
			C[i][j] = A[i][j] * B[i][j];
}
void writem2(int C[maxr][maxc], ofstream &outf)
{
	int i, j;
	outf << "//Step Two Add them "<<endl << endl << "C =" << endl;
	for (i = 0; i < maxr; i++)
	{
		for (j = 0; j < maxc; j++)outf << C[i][j] << "  ";
		outf << endl;
	}
}
void writem3( int C[maxr][maxc], ofstream &outf)
{
	int i, j;
	outf << "//Step 3: Subtract them" << endl << "C =" << endl;
	for (i = 0; i < maxr; i++)
	{
		for (j = 0; j < maxc; j++)outf << C[i][j] << "  ";
		outf << endl;
	}
}
void writem4(int C[maxr][maxc], ofstream &outf)
{
	int i, j;
	outf << "// Step 4: Matrix Multiplication for Matrices" << endl << "C =" << endl;
	for (i = 0; i < maxr; i++)
	{
		for (j = 0; j < maxc; j++)outf << C[i][j] << "  ";
		outf << endl;
	}
}
void writem5(int C[maxr][maxc], ofstream &outf)
{
	int i, j;
	outf << "//Step 5: Scalar Multiplication with Matrices" << endl << "C =" << endl;
	for (i = 0; i < maxr; i++)
	{
		for (j = 0; j < maxc; j++)outf << C[i][j]<<"  ";
		outf << endl;
	}
}
void main()
{
	fstream inf;
	inf.open("ec1.dat");
	ofstream outf;
	outf.open("ec1.ot");


	int A[maxr][maxc];
	int B[maxr][maxc];
	int C[maxr][maxc];
	initem(A, B, C);
	readem( A, B);
	writem(A, B, outf);
	addem(A, B,C);
	writem2(C,outf);
	subtractem(A, B, C);
	writem3(C, outf);
	matrixmulti(A, B, C);
	writem4(C, outf);
	scalarmulti(A, B, C);
	writem5(C, outf);

}