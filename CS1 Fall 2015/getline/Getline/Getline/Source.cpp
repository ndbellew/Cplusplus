/*Nathan Bellew
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const int maxg = 6;
struct gtype
{
	string whole, whole1;
	string city, state, zipc,csz;
	string street;
	string first, last;
	char mid;
	int pledge;

};
const gtype initrec = { "popo", "popp", "popo", "popo","pop", "popo", "popo", "popo", "popo", 'd', 2 };
void initem(gtype g[])
{
	int i;
	for (i = 0; i < maxg; i++)g[i] = initrec;

}
void readem(ifstream &inf, gtype g[], int i, int &nums)
{
	i = 0;
	while (!inf.eof())
	{
		getline(inf,g[i].whole, '|');
		getline(inf, g[i].street, '|');
		getline(inf, g[i].csz, '|');
		inf >> g[i].pledge >> ws;
		i++;
	}
	nums = i;
}
void printem(ofstream &outf, gtype g[], int i, int nums)
{
	outf << right << setw(13) << "Alumnus" << setw(23) << "Almunus" << setw(19)
		<< "Alumnus" << setw(30) << "City-State-Zip" << endl
		<< setw(11) << "Name" << setw(25) << "Pledge" << setw(18) << "Street" << endl;
	for (i = 0; i < 90; i++)outf << "~";
	outf << endl;
	for (i = 0; i < nums; i++)
	{
		outf << left << setw(30) << g[i].whole << setw(15) << g[i].pledge << setw(20)
			<< g[i].street << g[i].csz << endl;
	}
	for (i = 0; i < 90; i++)outf << "~";
	outf << endl;
}
void printemp(ofstream &outf, gtype g[], int i, int nums)
{
	outf <<right<<setw(13)<< "Alumnus" << setw(23) << "Almunus" << setw(19)
		<< "Alumnus" << setw(30) << "City-State-Zip" << endl
		<< setw(11) << "Name" << setw(25) << "Pledge" << setw(18) << "Street" << endl;
	for (i = 0; i < 90; i++)outf << "~";
	outf << endl;
	for (i = 0; i < nums; i++)
	{
		outf << left << setw(30) << g[i].whole << setw(15) << g[i].pledge << setw(20)
			<< g[i].street << g[i].csz << endl;
	}
	for (i = 0; i < 90; i++)outf << "~";
	outf << endl;
}
void printitles(ofstream &outf)
{
	int i;
	for (i = 0; i < 90; i++)outf << "_";
	outf << endl;
	outf << setw(65)<< "Marvel College Alumni Pledges" << endl;
	outf << endl;
	for (i = 0; i < 90; i++)outf << "_";
	outf << endl;
}
void citystreetz(gtype g[], int nums)
{
	int i=0;
	for (int i = 0; i < nums; i++)
	{
		int comma = g[i].csz.find(",");
		g[i].state = g[i].csz.substr(comma+2,2);
		g[i].zipc = g[i].csz.substr(comma + 5, g[i].whole.length());
		g[i].city = g[i].csz.substr(0,comma);
	}
}

void swapem(gtype &a, gtype &b)
{
	gtype temp;
	temp = a;
	a = b;
	b = temp;
}
void sortem(int nums, gtype g[])
{
	int i, j;
	for (j = 0; j < nums-1; j++)
		for (i = 0; i < nums-1; i++)
			if (g[i].pledge > g[i + 1].pledge)
			{
				swapem(g[i], g[i + 1]);
			}
}
void sortemln(gtype g[], int nums)
{
	int i, j;
	for (i = 0; i < nums - 1; i++)
	{
		g[i].whole1 = g[i].last + ", " + g[i].first
			+ " " + g[i].mid + ".";
	}
	for (i = 0; i < nums-1; i++)
		for (j = 0; j < nums-1; j++)
			if (g[j].last > g[j + 1].last)
				swapem(g[j], g[j + 1]);
}
void seperatemn(gtype g[], int nums)
{
	char period;
	for (int i = 0; i < nums; i++)
	{
		 period = g[i].whole.find('.');
			g[i].first = g[i].whole.substr(0, period - 2);
			g[i].last = g[i].whole.substr(period + 2, g[i].whole.length());
			g[i].mid = g[i].whole[period - 1];
			g[i].whole1 = g[i].last + ", " + g[i].first + " " + g[i].mid + ".";
				}
}
void sortemcsz(gtype g[], int nums)
{
	int i, j;
	for (j = 0; j < nums - 1; j++)
		for (i = 0; i < nums - 1; i++)
			if (g[i].zipc > g[i + 1].zipc)
			{
				swapem(g[i], g[i + 1]);
			}
}
void printem2(ofstream &outf, int nums, gtype g[])
{
	int i, totpledge=0;
	for (i = 0; i < 90; i++)outf << "+";
	outf << endl;
	outf <<right<< setw(10) << "Names" << setw(33) << "Pledges" << endl;
	for (i = 0; i < 90; i++)outf << "_";
	outf << endl;
	for (i = 0; i < nums; i++)
	{
		outf<<left<< setw(22)<<g[i].whole1 << right<<setw(19) << g[i].pledge << endl;
		totpledge += g[i].pledge;
	}
	for (i = 0; i < 90; i++)outf << "_";
	outf << endl;
	outf << "Total Pledges ="<< setw(25) << totpledge<<endl;
	for (i = 0; i < 90; i++)outf << "+";
	outf << endl;
}
void printem3(ofstream &outf, int nums, gtype g[])
{
	int i;
	for (i = 0; i < 90; i++)outf << "w";
	outf << endl;
	for (i = 0; i < nums - 1;i++)
	g[i].whole1 = g[i].last + ", " + g[i].first + " " + g[i].mid + ".";
	outf << setw(12) << "Zipcode" << setw(17) << "Name" << endl;
	for (i = 0; i < 90; i++)outf << "-";
	outf << endl;
	for (i = 0; i < nums; i++)
	{
		outf <<right<<setw(10)<< g[i].zipc <<setw(25) <<g[i].whole1<<left<< endl;
	}
	for (i = 0; i < 90; i++)outf << "w";
	outf << endl;
}
void main()
{
	int nums=0;
	string temp1;
	gtype g[maxg];
	ifstream inf;
	inf.open("getline.dat");
	ofstream outf;
	outf.open("getline.ot");
	outf.setf(ios::fixed);
	outf.precision(2);
	int i=0;
	initem(g);
	readem(inf, g, i, nums);
	printitles(outf);
	printem(outf, g, i, nums);
	sortem(nums, g);
	printemp(outf, g, i, nums);
	seperatemn(g, nums);
	sortemln(g, nums);
	printem2(outf, nums, g);
	citystreetz(g, nums);
	sortemcsz(g, nums);
	outf << endl;
	printem3(outf, nums, g);
}
