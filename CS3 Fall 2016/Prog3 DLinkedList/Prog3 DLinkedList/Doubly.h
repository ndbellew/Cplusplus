
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

struct doubly
{
	int id;
	string name;
	doubly *linka;
	doubly *linkn;
};