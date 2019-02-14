
/*Nathan Bellew
10/14/2015
CS1
The assignment i spent too much time on from basic bugs*/
#include <iomanip>
#include <fstream>
#include <iostream> 
#include <string>
using namespace std;
const int maxc = 100;
void initthem(char grade[], string dept[], string course[], string crsnum[],
	int crshrs[], int qualpts[], int gradevalue[], int numc)
	//initializing the program
{
	for (int i = 0; i < maxc; i++)
	{
		grade[i] = 'x';
		dept[i] = "Gelford Hughes";
		course[i] = "doodoo";
		crsnum[i] = "power";
		crshrs[i] = 0;
		qualpts[i] =0;
		gradevalue[i] = 0;
	}
	numc = 0;
}
void readem(string dept[], string crsnum[], string course[],
	int crshrs[], char grade[], int &numc)
{
	ifstream inf;
	inf.open("stuffers.dat");
	int i=0;
	while (!inf.eof())
	{
		inf >> dept[i] >> crsnum[i] >> course[i] >> crshrs[i] >> grade[i]>>ws;
		i++;
	}
	numc = i;
}
void swapem(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void swapem(string &a, string &b)
{
	string temp;
	temp = a;
	a = b;
	b = temp;
}
void swapem(char &a, char &b)
{
	char temp;
	temp = a;
	a = b;
	b = temp;
}
void calcpts(char grade[maxc], int qualpts[maxc], int crshrs[maxc], int numc,
	int gradevalue[], ofstream &outf)
{
	int   i;
	for (i = 0; i < numc; i++)
	{
		if (grade[i] == 'A')
			gradevalue[i] = 4;
		else if (grade[i] == 'B')
			gradevalue[i] = 3;
		else if (grade[i] == 'C')
			gradevalue[i] = 2;
		else if (grade[i] == 'D')
			gradevalue[i] = 1;
		else
			gradevalue[i] = 0;
		qualpts[i] = crshrs[i] * gradevalue[i];
}
}
void printem(char grade[maxc], string dept[], string course[], string crsnum[],
	int crshrs[], int qualpts[], int gradevalue[], int numc, ofstream &outf)
{
	int i, totalcrshrs=0, totalqualpts=0, j;
	double gpa=0;
	for (i = 0; i < numc; i++)
	{
		totalcrshrs += crshrs[i];
		totalqualpts += qualpts[i];
	}
	gpa = 1.0*totalqualpts / totalcrshrs;
	for (j = 0; j < 80; j++) outf << '-';
	outf << endl;
	outf << setw(20) << "Course" << setw(38) << "Credit" << endl;
	outf << "Dept" << setw(13) << "#" << setw(20) << "Course" << setw(20) <<
		"Hours" << setw(10) << "Grade" << endl;
	for (j = 0; j <80; j++) outf << "=";
	outf << endl;
	for (j = 0; j < numc;j++)
	outf <<left<<setw(15)<< dept[j] << setw(10) << crsnum[j] << setw(30) << course[j] << setw(10)
		<< crshrs[j] << setw(10) << grade[j] << endl;
	for (j = 0; j < 80; j++) outf << "=";
	outf << endl;
	outf << right<< setw(57) << totalcrshrs << setw(10) << totalqualpts << endl;
	outf  << "Student GPA=" << setw(7) << gpa << endl;
}
void sortem(char grade[maxc], string dept[], string course[],
	string crsnum[], int crshrs[], int qualpts[], int gradevalue[], int numc, ofstream & outf)
{
	int i, j;
	for (j = 0; j < numc - 1; j++)
		for (i = 0; i < numc - 1; i++)
			if (crsnum[i] > crsnum[i + 1])
			{
				swapem(grade[i], grade[1 + i]);
				swapem(dept[i], dept[1 + i]);
				swapem(course[i], course[1 + i]);
				swapem(crsnum[i], crsnum[1 + i]);
				swapem(crshrs[i], crshrs[i + 1]);
				swapem(qualpts[i], qualpts[1 + i]);
				swapem(gradevalue[i], gradevalue[1 + i]);
			}
	printem(grade, dept, course, crsnum, crshrs, qualpts, gradevalue, numc, outf);
}
void printem2(char grade[maxc], string dept[], string course[],
	string crsnum[], int crshrs[], int qualpts[], int gradevalue[], int numc, ofstream &outf)
{

	outf << endl;
	int i, senior = 0, junior = 0, sophomore = 0, freshman = 0;
	for (i = 0; i < numc; i++)
		if (crsnum[i] >= "400")
			senior++;
		else if (crsnum[i] <= "300")
			junior++;
		else if (crsnum[i] <= "200")
			sophomore++;
		else
			freshman++;
		for (i = 0; i < 38; i++) outf << '_';
		outf << endl<< "Freshman" << setw(11) << "Sophomore" << setw(8) << "Junior" << setw(8) << "Senior" << endl;
		outf << setw(4) << freshman << setw(11) << sophomore << setw(8) << junior << setw(8) << senior << endl;
		for (i = 0; i < 38; i++) outf << '_';
}
void getupper(int numc, string crsnum[], ofstream &outf)
{
	int i, sr=0;
	for (i = 0; i < numc; i++)
	{
		if (crsnum[i] >= "300")
			sr++;
	}
	outf <<endl<< endl << "The amount of upper class courses are " << sr << "!" << endl;
}
void main()
{
	char grade[maxc];
	string dept[maxc], course[maxc], crsnum[maxc];
	int crshrs[maxc], qualpts[maxc], gradevalue[maxc], numc = 0;
	ofstream outf;
	outf.open("stuffers.ot");
	outf.setf(ios::fixed);
	outf.precision(2);
	initthem(grade, dept, course, crsnum, crshrs, qualpts, gradevalue, numc);
	readem(dept, crsnum, course, crshrs, grade, numc);
	calcpts(grade, qualpts, crshrs, numc, gradevalue,outf);
	printem(grade, dept, course, crsnum, crshrs, qualpts, gradevalue, numc, outf);
	sortem(grade, dept, course, crsnum, crshrs, qualpts, gradevalue, numc, outf);
	printem2(grade, dept, course, crsnum, crshrs, qualpts, gradevalue, numc, outf);
	getupper(numc, crsnum, outf);
}
