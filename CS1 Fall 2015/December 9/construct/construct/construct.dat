/*Natey Bellew
Construct Progrum
19 November 2015*/
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BoxClass
{
private:
	double length, width, height;
public:
	BoxClass();
	BoxClass(double l, double w, double h);
	void printem(ofstream &outf);
	double getlength();
	double getwidth();
	double getheight();
	void setlength(double l);
	void setwidth(double w);
	void setheight(double h);
	double getvolin();
	double getvolft();
	double getsain();
	double getsaft();
};
BoxClass::BoxClass()
{
	length = 0.0;
	width = 0.0;
	height = 0.0;
}
BoxClass::BoxClass(double l, double w, double h)
{
	length = l;
	width = w;
	height = h;
}
void BoxClass::printem(ofstream &outf)
{
	
	outf <<"This object has these dimensions : "<< endl << setw(6) << "Length = " << length << endl << "Width = " << width << endl << "Height = " << height << endl;
	
}
double BoxClass::getlength()
{
	return length;
}
double BoxClass::getwidth()
{
	return width;
}
double BoxClass::getheight()
{
	return height;
}
void BoxClass::setlength(double l)
{
	length = l;
}
void BoxClass::setwidth(double w)
{
	width = w;
}
void BoxClass::setheight(double h)
{
	height = h;
}
double BoxClass::getvolin()
{
	double involume=0, l=length, w=width, h=height;
	involume = l*w*h;
	return involume;
}
double BoxClass::getvolft()
{
	double ftvolume=0, L=0, W=0, H=0, l=length, w=width, h=height;
	L = l / 12;
	W = w / 12;
	H = h / 12;
	ftvolume = L*W*H;
	return ftvolume;
}
double BoxClass::getsain()
{
	double insurfarea = 0, l = length, w = width, h = height;
	insurfarea = 2*l*h + 2*w*h+ 2*l*w;
	return insurfarea;
}
double BoxClass::getsaft()
{
	double ftsurfarea = 0, L = 0, W = 0, H = 0, l = length, w = width, h = height;
	L = l  / 12;
	W = w / 12;
	H = h / 12;;
	ftsurfarea = 2 * L*H + 2 * W*H+ 2*L*W;
	return ftsurfarea;
}
void main()
{
	double involume, ftvolume,  insurfarea, ftsurfarea;
	ofstream outf;
	outf.open("construct.ot");
	//step A Declaring box1 and box2
	BoxClass box1;
	BoxClass box2(15.25, 10.50, 12);
	//Step B Printing box1 and box2
	outf << "//Step B: Printing box1 and box2" << endl;
	outf << "Here is box1." << endl;
	box1.printem(outf);
	outf << endl;
	outf << "HERE IS BOX2!!!" << endl;
	box2.printem(outf);
	outf << endl;
	//Step C Setting Box1 to its new w l and h
	box1.setwidth(24.25);
	box1.setlength(35.506);
	box1.setheight(20.125);
	outf << "//Step C: Set Box1 with new Width, Length, and Height!" << endl;
	box1.printem(outf);
	outf << endl;
	//Step D: Volume of each box
	outf << "//Step D: Volume of each box in Inches" << endl;
	involume = box1.getvolin();
	outf << "Box1 Volume (IN) = "<< involume<<" Cubic Inches" << endl;
	involume = box2.getvolin();
	outf << "Box2 Volume (IN) = " << involume<<" Cubic Inches" << endl;
	outf << endl;
	//Step E: Get Volume in Cubic Feet
	outf << "// Step E: Getting Volume in Cubic Feet" << endl;
	ftvolume = box1.getvolft();
	outf << "Box1 Volume (FT) = " << ftvolume << " Cubic Feet" << endl;
	ftvolume = box2.getvolft();
	outf << "Box2 Volume (FT) = " << ftvolume << " Cubic Feet" << endl;
	outf << endl;
	//Step F: Get Surface Area in Inches
	outf << "//Step F: Getting Surface Area in Inches" << endl;
	insurfarea = box1.getsain();
	outf << "Box1 Surface Area (IN) = " << insurfarea << " Sqaure Inches" << endl;
	insurfarea = box2.getsain();
	outf << "Box2 Surface Area (IN) = " << insurfarea << " Sqaure Inches" << endl;
	outf << endl;
	//Step G: Get Surface Area in Feet
	outf << "//Step G: Getting Surface Area of Each Box in Feet!" << endl;
	ftsurfarea = box1.getsaft();
	outf << "Box1 Surface Area (FT) = " << ftsurfarea << " Sqaure Inches" << endl;
	ftsurfarea = box2.getsaft();
	outf << "Box1 Surface Area (FT) = " << ftsurfarea << " Sqaure Inches" << endl;
	outf << endl;
	//Step H: Two Boxes For Christmas
	outf << "//Step H : Totals of Surface Areas for Presents" << endl;
	double totalsurfarea;
	totalsurfarea = box1.getsaft() + box2.getsaft();
	outf << "The total amount of wrapping paper needed is " << totalsurfarea << " Sq. Ft." << endl;
	outf << endl;
	//Step I: Two Planters
	outf << "//Step I: Adding Two Boxes together" << endl;
	double totalvolft;
	totalvolft = box1.getvolft() + box2.getvolft();
	outf << "The total Volume of both planters is " << totalvolft << " Cubic Feet!" << endl;

}