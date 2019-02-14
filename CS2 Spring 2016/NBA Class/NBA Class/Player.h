#pragma once
#include <string>
#include <iomanip>
#include<iostream>
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
private:
	string name, team;
	double pts, reb, asst;

};