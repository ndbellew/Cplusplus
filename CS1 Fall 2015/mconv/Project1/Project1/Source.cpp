/* Nathan Bellew
8/28/2015
CS1
Centimeters to Yards, Feet, and Inches.*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
void main()
{
	// int i, is always necesarry.
	int i, yards=0;
	int in=0, in2=0;
	// we needed two integers for both inches and feet, in order to take the total inches and feet into yards, and the remainder into the final product.
	int ft=0, ft2=0;
	int cm=0;
	// inf and outf, so it will pull information for our .dat, and place the output in our .ot.
	ifstream inf;
	ofstream outf;
	inf.open("mconv.dat");
	outf.open("mconv.ot");
	for (i = 1; i <= 10; i++)
	{
		// here you see the inf is pulling information from .dat and for cm
		inf >> cm;
			in = 1.0*(cm / 2.54) + .5;
			ft = in / 12;
			in2 = in % 12;
			yards = ft / 3;
			ft2 = ft % 3;
	  
	   outf << cm << " cm, when converted to Imperial Units, is " << in << " in, which after being converted to standard (yd, ft, and in) is: " << yards << " yd, " << ft2 << " ft, " << in2 << " in.\n" << endl;
	}
	}
	
    
 


