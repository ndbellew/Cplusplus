/*Nathan Bellew
9/16/2015
CS1-111
Main Street Bank Program*/
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void main()
{
	int i, accn;
	double oldbal, minbal, newbal, fee, difference, interest, toldbal, tfee, tinterest, tnewbal;
	char acctype;
	ifstream inf, s, c;
	ofstream outf;
	inf.open("msbi.dat");
	outf.open("msbi.ot");
	outf.setf(ios::fixed);
	outf.precision(2);
	for (i = 1; i <= 67; i++) outf << '-';
	//this next part was honestly the most difficult part.
	outf << endl << setw(41) << "MAIN STREET BANK" << endl << endl << setw(40) << "Account Update" 
		<< endl << endl << setw(15) << "Account"<< setw(9) << "Minimum" << setw(9)<< "Old" << setw(28) 
		<< "New" << endl << "Account" << setw(6) << "Type" << setw(11) << "Balance" << setw(12) <<
		"Balance" << setw(7) <<"Fee" << setw(12) << "Interest" << setw(10) << "Balance" << endl;
	for (i = 1; i <= 67; i++) outf << '-';
	outf << endl;
	toldbal = 0;
	tfee = 0;
	tinterest = 0;
	tnewbal = 0;
	for (i = 1; i <= 10; i++)
	{
		inf >> accn >> acctype >> minbal >> oldbal;
		difference = oldbal - minbal;
		if (acctype == 's')
		{
			if (difference <= 0)
				fee = 50.00;

			else
				fee = 0.00;
			if (difference > 0)
			{
				if (difference <= 2500.00)
					interest = (.015 * oldbal);
				else if (difference > 2500)
					interest = (.02 * oldbal);
			}
			else
				interest = 0.00;
		}
		else
		{
			if (difference <= 0)
				fee = 30.00;
			else
				fee = 0.00;
			if (difference > 0)
			{
				if (difference <= 5000.00)
					interest = (.005 * oldbal);
				else if (difference > 5000)
					interest = (.008 * oldbal);
			}
				else
					interest = 0.00;
			
		}
		newbal = (oldbal - fee) + interest;
		toldbal += oldbal;
		tfee += fee;
		tinterest += interest;
		tnewbal += newbal;
		outf << right << accn << setw(6) << acctype << setw(13) << minbal << setw(12) << oldbal <<
			setw(8) << fee << setw(10) << interest << setw(11) << newbal << endl;
	}
	for (i = 1; i <= 67; i++) outf << '-';
	outf << endl;
	outf << setw(36) << toldbal << setw(8) << tfee << setw(10) << tinterest << setw(11) << tnewbal << endl;
	

}