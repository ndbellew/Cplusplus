/*Nathan Bellew
CS1
Searching Program*/
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
const int maxp = 150;
const int maxquan = 4;
struct ptype
{
	int id;
	string product;
	int quan[maxquan];
	int tquan;
	double uprice;
	double sold;
};
const ptype initrec = { -1, "Le Gelford Huges", 0, 0, 0, 0, 0, 0.0, 0.0 };
void initem(ptype p[], int &nump)
{
	int i;
	for (i = 0; i < maxp; i++)p[i] = initrec;
	nump = 0;
}
void readem(ptype p[],int &nump)
{
	ifstream inf;
	inf.open("searching.dat");
	int i = 0, q;
	while (!inf.eof())
	{
		inf >> p[i].id >> p[i].product >> p[i].uprice;
		for (q = 0; q < maxquan; q++) inf >> p[i].quan[q];
		i++;
	}
	nump = i;
}
void printitles(ofstream &outf)
{
	int i;
	for (i = 0; i <94; i++)outf << "-";
	outf << endl;
	outf << setw(65) << "My Little Store Monthly Sales Review" << endl;
	for (i = 0; i < 94; i++)outf << "~";
	outf << endl;
}
void totalsales(ptype p[], int nump, double &totsales, double &tsold, int &totquan,
	int &tweek1, int &tweek2, int &tweek3, int &tweek4, ofstream &outf)
{
	int i;
	int q;
	totsales = 0;
	tsold = 0;
	totquan = 0;
	tweek1 = 0;
	tweek2 = 0;
	tweek3 = 0;
	tweek4 = 0;
	for (i = 0; i < maxp; i++)
	{
		for (q = 0; q < maxquan; q++)
		{
			p[i].tquan += p[i].quan[q];
			p[i].sold = p[i].tquan*p[i].uprice;
			totsales += p[i].sold;
		}
		tsold += p[i].sold;
		totquan += p[i].tquan;
		tweek1 += p[i].quan[0];
		tweek2 += p[i].quan[1];
		tweek3 += p[i].quan[2];
		tweek4 += p[i].quan[3];
	}
}
void swapem(ptype &a, ptype &b)
{
	ptype temp;
	temp = a;
	a = b;
	b = temp;
}
void sortem(int nump, ptype p[], ofstream &outf)
{
	int i, j;
	for (j = 0; j < nump - 1; j++)
		for (i = 0; i < nump - 1; i++)
			if (p[i].id < p[i + 1].id)
			{
				swapem(p[i], p[i + 1]);
			}
}
void printem(ptype p[], int nump, double &totsales, double &tsold, int &totquan, int &tweek1,
	int &tweek2, int &tweek3, int &tweek4, ofstream &outf)
{
	int i, q, j, g;
	outf << setw(65) << "Sales per Week" << endl; 
	outf<< setw(25) << "Unit" << setw(56) << "Total" << setw(13) << "Total"<< endl;
	outf << "ID" << setw(10) << "Product" << setw(13) << "Price" << setw(13) << "Week 1"
		<< setw(10) << "Week 2" << setw(10) << "Week 3" << setw(10) << "Week 4" << setw(15) <<
		"Quantity" << setw(11) << "Sales" << endl;
	for (g = 0; g < 94; g++)outf << "=";
	outf << endl;
	for (i = 0; i < nump; i++)
	{
		
		outf << left << setw(5) << p[i].id << setw(15) << p[i].product << right
			<< setw(5) << p[i].uprice;
		for (q = 0; q < maxquan; q++)outf << setw(10) << p[i].quan[q];
		outf << setw(15) << p[i].tquan << setw(14) << p[i].sold  << endl;
	}
	for (j = 0; j < 94; j++) outf << "=";
	outf << endl;
	outf << "Total Sales a Week:" << setw(22)<<tweek1 << setw(10) << tweek2 << setw(10) << tweek3 
		<< setw(10) << tweek4 << endl;
	for (j = 0; j < 94; j++)outf << "=";
	outf << endl;
	outf<<"Totals for Entire Month:"<<setw(56)<<totquan << setw(14) << tsold << endl;
	for (j = 0; j < 94; j++) outf << "_";
	outf << endl;
	
}
int searchem(ptype p[], int nump, string name)
{
	int i, ans;
	ans = -1;
	i = 0;
	while
		(i < nump&&name != p[i].product)i++;
	if (name == p[i].product)ans = i;
	return ans;
}
void main()
{
	ptype p[maxp];
	int nump, tweek1, tweek2, tweek3, tweek4, totquan, index,i;
	double totsales, tsold;
	ofstream outf;
	outf.open("searching.ot");
	outf.setf(ios::fixed);
	outf.precision(2);
	initem(p, nump);
	readem(p, nump);
	totalsales( p, nump, totsales, tsold, totquan,
		tweek1, tweek2, tweek3, tweek4, outf);
	sortem(nump, p, outf);
	printitles(outf);
	printem(p, nump, totsales, tsold, totquan, tweek1, tweek2, tweek3, tweek4, outf);
	index = searchem(p, nump, "Coffee");
		if (index != -1)outf << "INDEX = " << index << " For Product " 
			<< p[index].product<< "." << endl;
		else
			outf << "Product Not Found!!" << endl;
	index = searchem(p, nump, "Gelford Hughes");
	if (index != -1)outf << "INDEX = " << index << " For Product " << p[index].product
		<< endl;
	else
		outf << "Product Not Found!!" << endl;
	for (i = 0; i < 94; i++)outf << "-";
}

