/* Nathan Bellew
1/20/2016
CS1 Player Stats Program
Dr. Basnet*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
const int maxp = 100;
struct StatsType {
	string name, team;
	double pts, rebound, asst;
};
void initstats(StatsType plyrs[], int maxp)
{
	for (int i = 0; i < maxp; i++)
	{
		plyrs[i].name = "Gelford Hughes";
		plyrs[i].team = "Team";
		plyrs[i].pts = 0;
		plyrs[i].rebound = 0;
		plyrs[i].asst = 0;
	}
}
void readem(StatsType plyrs[], int maxp, int& nump, int i)
{
	ifstream inf;
	inf.open("players.txt");
	int test = 0;
	while (!inf.eof())
	{
		
		inf >> plyrs[i].name >> plyrs[i].team >> plyrs[i].pts >> plyrs[i].rebound
			>> plyrs[i].asst;
		test++;
		i++;
	}
	nump = test;
}
void playermenu(StatsType plyrs[], int maxp, int& nump)
{
	cout << "Player Menu Options" << endl << "View" << "Shows all players." << endl << "View Player"<<endl <<
		"-Type vp to view specific player" <<	endl << "All Player Stats" <<endl<<
		"-Type aps to veiw all player stats" <<endl << "Stats" <<endl<<
		"-Type stats to select specific player stats" << endl;
	string answer;
	cin >> answer;
	if (answer == "vp")
	{
		for (int i = 0; i < nump; i++)
		{
			cout << i + 1 << ": " << plyrs[i].name << endl;
		}
	}
}
void selectinformation(StatsType plyrs[], int maxp, int& nump)
{
	//Let them search for what they want to find
	int i, plyrnumber;
	cout << "Input players assigned number." << endl;
	cin >> plyrnumber;
	
	
}
int main()
{
	int nump = 0, i = 0;
	StatsType plyrs[maxp];
	initstats(plyrs, maxp);
	readem(plyrs, maxp, nump, i);
	playermenu(plyrs, maxp, nump);
	//selectinformation(plyrs, maxp, nump);
	cout << "Thank You for Stopping by!" << endl;
	cin.get();
	cin.get();
	return 0;
}
