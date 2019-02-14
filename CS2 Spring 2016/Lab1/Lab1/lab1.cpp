/*
	lab 1
	CS2
	Updated by: Nathan Bellew
	Date: 1/21/16

	Breakfast billing system for a restaurant

	this program allows restaurant customers to select breafast items and prints in the bill
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//max no. of menu items that can be stored by the program
const int NO_OF_ITEMS = 8;

// data structure to hold each menu item info
struct menuItemType
{
	string itemName;
	double itemPrice;
};

//initialize menu list with some default values
void initMenuList(menuItemType menuList[], int menuListSize);
// function that reads menu data into menuList array
void readMenuData(ifstream& inf, menuItemType menuList[], int menuListSize);
// function that displays menu
void showMenu(menuItemType menuList[], int menuListSize);
// function to print check after menu items are selected
void printCheck(menuItemType menuList[], int menuListSize, int selectedList[], int selectedListLength);
//finction to select items from menu list
void makeSelection(menuItemType menuList[], int menuListSize, int selectedList[], int& selectedListLength);
// function that returns true fi the itemNo is in the selectedList otherwise false.
// this function avoids user repeating the menu item
bool isItemSelected(int selectedList[], int selectedListLenghth, int itemNo);

int main()
{
	menuItemType menuList[NO_OF_ITEMS];
	int choiceList[NO_OF_ITEMS]; // array to keep track of choices based on item number
	int choiceListLength=NO_OF_ITEMS; // variable to keep track of no. of choices
	ifstream inf;
	cout << fixed << showpoint << setprecision(2);
	// open menu.txt file to read menu data from
	inf.open("menu.txt");
	if (!inf)
	{
		cout << "Iput file does not exist. Program Terminates!"
			<< endl;
		cin.get();
		return 1;
	}
	initMenuList(menuList, NO_OF_ITEMS);
	// Run initMenuList to initialize menuList and NO_OF_ITEMS
	// CallreadMenuData function passing proper arguments
	readMenuData(inf, menuList, NO_OF_ITEMS);
	inf.close(); //close input file
	showMenu(menuList, NO_OF_ITEMS);
	makeSelection(menuList, NO_OF_ITEMS, choiceList, choiceListLength);
	printCheck(menuList, NO_OF_ITEMS, choiceList, choiceListLength);
	//pause the program until enter is hit
	cin.get();
	cin.get();
	return 0;
}

void initMenuList(menuItemType menuList[], int menuListSize)
{
	for (int i = 0; i < menuListSize; i++)
	{
		menuList[i]={ "A Tasty Item", 0};
	}
}
void readMenuData(ifstream& inf, menuItemType menuList[], int menuListSize)
{
	char ch;
	for (int i = 0; i < menuListSize; i++)
	{
		if (!inf.eof())
		{
			getline(inf, menuList[i].itemName);
			inf >> menuList[i].itemPrice;
			// 2. Read each item price into itemPrice field of menuList array
			inf.get(ch); // read and ignore \n char
		}
	}
}

void showMenu(menuItemType menuList[], int menuListSize)
{
	cout << "Welcome to Papi Joey's Kitchen\n";
	cout << "----Today's Menu----" << endl;

	for (int i = 0; i < menuListSize; i++)
	{
		cout << i + 1 << ": " << left << setw(15) << menuList[i].itemName
			<< right << " $" << menuList[i].itemPrice << endl;
	}
	cout << endl;
}

void printCheck(menuItemType menuList[], int menuListSize, int selectedList[], int selectedListLength)
{
	int i;
	double salesTax;
	double amountDue = 0;

	cout << "   Papi Joey's Kitchen" << endl;
	cout << "       Guest Check    " << endl;
	cout << setw(25) << setfill('=') << endl;
	cout << setfill(' ') << endl;
	for (i = 0; i < selectedListLength; i++)
	{
		cout << left << setw(15) << menuList[selectedList[i]].itemName << right << "$" << setw(4) << menuList[selectedList[i]].itemPrice << endl;
		amountDue += menuList[selectedList[i]].itemPrice;
	}
	cout << endl;
	salesTax = amountDue * .07;

	cout << left << setw(15) << "Tax" << right << "$" << salesTax << endl;
	amountDue = amountDue + salesTax;
	cout << left << setw(15) << "Amount Due" << right << "$" << amountDue << endl;
	cout << setw(25) << setfill('=') << ' ' << endl;
	cout << setfill(' ') << endl;
	cout << "     Thank you! " << endl;
	cout << "Would you like a reciept? y/n" << endl;
	string ans;
	cin >> ans;
	if (ans == "y" || ans == "Y")\
	{
		cout << "Please enter the filename for you reciept." << endl;
		ofstream outf;
		string guest;
		outf.open("guest");
		cin >> guest;
		outf.setf(ios::fixed);
		outf.precision(2);
		outf << "   Papi Joey's Kitchen" << endl << "      Guest Check     " << endl <<
			setw(25) << setfill('=') << endl << setfill(' ') << endl;
		for (i = 0; i < selectedListLength; i++)
		{
			outf << left << setw(15) << menuList[selectedList[i]].itemName <<
				right << "$" << setw(4) << menuList[selectedList[i]].itemPrice << endl;

		}
		outf << endl;
		outf << left << setw(15) << "Tax" << right << " $" <<
			salesTax << endl;
		outf << left << setw(15) << " AMount Due" << right << " $" << amountDue << endl << endl;
		outf << setw(25) << setfill('=') << ' ' << endl;
		outf << setfill(' ') << endl;
		outf << "     Thank you! " << endl;
		outf.close();
		cout << "Your file has been created and saved Thank you for waiting!" << endl;
	}
	else
		cout << "too bad have a good day prick\n";

}

void makeSelection(menuItemType menuList[], int menuListSize, int selectedList[],
	int& selectedListLength)
{
	int selectionNo = 0;
	int itemNo;
	char response;
	selectedListLength = 0;
	cout << "You can make up to " << menuListSize
		<< " single order selections" << endl;
	cout << "Do you want to make selection Y/y (Yes), or N/n (No): ";
	cin >> response;
	cout << endl;

	while ((response == 'Y' || response == 'y') && selectedListLength < menuListSize)
	{
		cout << "Enter item number: ";
		cin >> itemNo;
		cout << endl;

		if (!isItemSelected(selectedList, selectedListLength, itemNo))
			selectedList[selectedListLength] = itemNo - 1;
		else
			cout << "Item already selected" << endl;

		cout << "Select another item Y/y (Yes), or N/n (No): ";
		cin >> response;
		cout <<endl;
	}
}
 
bool isItemSelected(int selectedList[],
	int selectedListLength, int itemNo)
{

	short i;
	ifstream inf;
	inf.open("menu.txt");
			if (itemNo>selectedListLength||itemNo<0)
				return false;
			else
				return true;
}