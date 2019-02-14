/*
Nathan Bellew
2/2/2016
CS2 Player Stats Program 2
Dr. Basnet
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
const int maxp = 100;
class StatsType{
public:
	StatsType()//default constructor
	{
		this->name = "Gelford Hughes";
		this->team = "Cloud 9";
		pts = 0;
		reb = 0;
		asst = 0;
	}
	StatsType(string name, string team)
	{
		this->name = name;
		this->team = team;
		pts = 0;
		reb = 0;
		asst = 0;
	}
	void print()
	{
		cout << "name- " << this->name << endl;
		cout << "Team - " << this->team << endl;
		cout << "pts - " << this->pts << endl;
		cout << "reb - " << this->reb << endl;
		cout << "asst - " << this->asst << endl;
	}
	~StatsType()
	{
		cout << "destructor" << endl;
	}
private:
	string name, team;
	double pts, reb, asst;

};

int main()
{

	StatsType p;
	StatsType p2("Stephen Curry","Golden State Warriors");
	p.print();
	p2.print();
	system("pause");
	return 0;
}