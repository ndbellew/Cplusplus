/*nathan bellew
november 9 2015
cs1*/
#include <iomanip>
#include <iostream>
#include<string>
#include <fstream>
using namespace std;
void main()
{
	string str1, str2, str3;
	fstream inf;
	fstream outf;
	inf.open("stringtheory.dat");
	outf.open("stringtheory.ot");
	//step1
	getline(inf, str1);
	getline(inf, str2);
	getline(inf, str3);
	outf << "Step 1: Declare The Strings" <<endl<<"Use getline"<<
		endl << str1 << endl << str2 << endl << str3 << endl;
	//step2
	int len1, len2, len3;
	len1 = str1.length();
	len2 = str2.length();
	len3 = str3.length();
	outf << "Step 2: Finding the Lengths of each line"<<endl<<
		"Using str.length()" << endl << "length = " << len1 << endl <<
		"length = " << len2 << endl << "length = " << len3 << endl;
	//step3
	int comma1, comma2, comma3;
	comma1 = str1.find(",");
	comma2 = str2.find(",");
	comma3 = str3.find(",");
	outf << "Step 3: Find the position of a specific character"<<endl<<
		"Using str.find(str)" << endl << "comma1= " << comma1 << endl <<
		"comma2= " << comma2 << endl << "comma3= " << comma3 << endl;
	//step4
	char ch1, ch2, ch3;
	ch1 = str1[comma1 - 2];
	ch2 = str2[comma2 - 2];
	ch3 = str3[comma3 - 2];
	outf << "Step 4: Finding a specific Character"<<endl<<"Using an array"
		<< endl << "ch1= " << ch1 << endl << "ch2= " << ch2 <<
		endl << "ch3= " << ch3 << endl;
	//step5
	string sub1, sub2, sub3;
	sub1 = str1.substr(comma1 + 2, str1.length());
	sub2 = str2.substr(comma2 + 2, str2.length());
	sub3 = str3.substr(comma3 + 2, str3.length());
	outf << "Step 5: Getting the substring from a specific location." <<
		endl <<"Using str.substr(pos,len)"<<endl << "substring one = " <<
		sub1<<endl << "substring two= " << sub2 <<endl<< "substring three="
		<< sub3 << endl;
	//step6
	str1.erase(comma1, 1);
	str2.erase(comma2, 1);
	str3.erase(comma3, 1);
	outf << "step 6: Deleting Characters > based on position" << endl<<
		"Using str.erase(pos,n)"<<endl<< str1 << endl << str2 << endl <<
		str3 << endl;
	//step7
	str1.insert(comma1, "TGIT");
	str2.insert(comma2, "TGIT");
	str3.insert(comma3, "TGIT");
	outf << "Step 7: Inserting Silly Messages." << endl <<
		"Using str.insert(pos,str)"<< endl << str1 << endl << str2 <<
		endl << str3 << endl;
}