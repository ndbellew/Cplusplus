/*Nathan Bellew
Definite Integral
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const int n=4;
const int a=0;
const int b=1;
const double e=2.71828;
void initem()
{

}
void readem()
{

}
void printem()
{

}
void inscrectang()
{
double h=0, w=0;
for (x=a; x<1;x++)
{
h[x]= power(e,[x])
}
w=a+b;
y=h[x]*w;

}
void trapezoids()
{
	for (x = 0; x < 1; x++)
	{
		y[x] = (b - a) / n;
		y += y[x];
	}
	outf << y << endl;
}
void simpson()
{
	int i;
	x = (b - a) / n;
	
		for (i = b; i < a; i++)
		{
			y[i] = power(e, x[i]);
			y = (x / 3)*(y[0] + (4 * y[1]));
		}
}
void main()
{

double y=0, x=0;
ofstream outf;
outf.open("defint.ot");
outf.setf(ios::fixed);
initem();
readem();
inscrectang();

}