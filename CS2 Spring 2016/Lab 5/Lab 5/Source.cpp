/*
CS 112
Updated By: Nathan Bellew
Date: 3/23/2016

Program that uses forward single linked list to store some unique numbers in order.
program uses menu options to find various operations on the numbers stored in the linked list.

*/
#include <iostream>
#include <iomanip>

using namespace std;

struct numNode
{
	double num;
	numNode *next;
};

numNode *createOrderedLinkedList(numNode *&last);

void printData(numNode *current, bool all = true);

void insertNewNode(numNode * &first, numNode *&last, numNode *newNode);

numNode *getNode(numNode *current);

bool searchList(numNode *current, double num);

void deleteNode(numNode * &first, numNode *&last, double num);

void showMenu();

double findAverage(numNode *current);

int main(int argc, char* argv[])
{
	int choice;

	numNode *first = nullptr;
	numNode *last = nullptr;
	numNode *node = nullptr;
	numNode *newNode = nullptr;
	double num;
	bool found;

	first = createOrderedLinkedList(last);

	do
	{
		showMenu();
		std::cin >> choice;
		std::cout << endl;
		std::cin.ignore(100, '\n');
		switch (choice)
		{
		case 1:
			system("cls");
			printData(first);
			break;
		case 2:
			system("cls");
			node = getNode(first);
			printData(node, false);
			break;
		case 3:
			system("cls");
			newNode = new numNode;
			newNode->next = nullptr;
			found = false;
			do{
				std::cout << "Enter a new number to add: " << endl;
				cin >> newNode->num;
				found = searchList(first, newNode->num);
				if (found)
					cout << "Node with that value already exists!\n";
			} while (found);
			insertNewNode(first, last, newNode);
			cout << "New number added successfully in the list! Hit ENTER to continue...\n";
			cin.ignore(100, '\n');
			cin.get();
			break;
		case 4:
			cout << "Enter number to be deleted: " << endl;
			cin >> num;
			deleteNode(first, last, num);
			break;
		case 5:
			system("CLS");
			cout << "The average of the current number set is: " <<
				findAverage(first) << endl;
				cout << "Press Enter to continue.\n";
				cin.get();
			break;
		case 6:
			
			system("cls");
			cout << "Smallest number in the list: " << first->num << endl;
			cout << "Enter to continue...";
			cin.get();
			break;
		case 7:
		
			system("cls");
			cout << "Largest number in the list: " << last->num << endl;
			cout << "Enter to continue...";
			cin.get();
			break;
		case 0:
			break;
		default:
			cout << "Invalid selection." << endl;
		}
	} while (choice != 0);
		cout << "Good bye... Enter to exit the program.";
	cin.get();
	return 0;
}

void showMenu()
{
	cout << setw(50) << setfill('=') << ' ' << endl;
	cout << "*** Numbers stored in ordered linked list***" << endl << endl;
	cout << "Select one of the following options:" << endl;
	cout << setw(50) << ' ' << endl << endl;
	cout << setfill(' ');
	cout << "1: Print all Numbers in list" << endl;
	cout << "2: Search a number in list" << endl;
	cout << "3: Add a new number\n";
	cout << "4: Delete a number\n";
	cout << "5: Print average of numbers" << endl;
	cout << "6: Print the min number\n";
	cout << "7: Print the max number \n";
	cout << "0: Quit the program\n";
}

numNode *createOrderedLinkedList(numNode * &last)
{
	numNode *first = nullptr, *newNode = nullptr;
	numNode *current;
	bool done = false;
	double num = 0;
	while (!done)
	{
		newNode = new numNode;
		cout << "Enter a number, or done when done -> ";
		try
		{
			cin >> num;
			if (cin.fail())
				throw "error";
			newNode->num = num;
			newNode->next = nullptr;
			insertNewNode(first, last, newNode);
		}
		catch (const char *err)
		{
			cin.clear();
			cin.ignore(100, '\n');
			done = true;
		}
	}
	return first;
}

void printData(numNode *current, bool all)
{
	if (all)
		cout << setw(30) << right << "All Values in Ordered Linked List" << endl;
	else
		cout << setw(30) << right << "Individual Value Found in Linked List" << endl;
	cout << setw(80) << setfill('=') << ' ' << endl;
	cout << setfill(' ');
	cout << fixed << setprecision(2);
	while (current != nullptr)
	{
		cout << current->num << " ";
		if (all)
			current = current->next;
		else
			break;
	}
	cout << endl;
	cout << setw(80) << setfill('=') << ' ' << endl;
}

numNode *getNode(numNode *current)
{
	double num;
	cout << "Enter a number to search: ";
	cin >> num;
	bool found = false;
	bool again = false;
	do
	{
		while (current != nullptr && !found)
		{
			if (current->num == num)
			{
				found = true;
				again = false;
			}
			else
				current = current->next;
		}
		if (!found)
		{
			cout << "Given number " << num << " not found. Enter another number to search for: ";
			cin >> num;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				again = false;
			}
		}
	} while (again);

	return current;
}

bool searchList(numNode *current, double num)
{
	bool found = false;

	while (current != nullptr &&!found)
	{
		if (current->num == num)
			found = true;
		else if (current->num < num)
			break;
		else
			current = current->next;
	}
	return found;
}

void insertNewNode(numNode * &first, numNode * &last, numNode *newNode)
{
	numNode *current = nullptr;
	numNode *trailCurrent = nullptr;

	bool found;
	if (first == nullptr)
	{
		first = newNode;
		last = newNode;
	}
	else
	{
		current = first;
		found = false;
		while (current != nullptr&&!found)
		{
			if (current->num >= newNode->num)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->next;
			}
		}

		if (current == first)
		{
			newNode->next = first;
			first = newNode;
		}
		else
		{
			trailCurrent->next = newNode;
			newNode->next = current;

			if (current == nullptr)
				last = newNode;
		}
	}
}

void deleteNode(numNode * &first, numNode * &last, double num)
{
	numNode *current;
	numNode *trailCurrent = nullptr;
	bool found;
	if (first == nullptr)
		cout << "Cannot delete from an empty list.\n";
	else
	{
		current = first;
		found = false;
		while (current != nullptr&&!found)
		{
			if (current->num >= num)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->next;
			}
		}
		if (current == nullptr)
		{
			cout << "the item to be deleted is not in the list." << endl;
		}
		else
		{
			if (current->num == num)
			{
				if (current->num == num)
				{
					first = first->next;
					if (first == nullptr)				
						last = nullptr;

					delete current;
				}
				else
				{
					trailCurrent->next = current->next;
					if (current == last)
						last = trailCurrent;
					delete current;
				}
				cout << "Number " << num << " deleted from the list." << endl;
			}
			else
			{
				cout << "the item to be deleted is not in the list.\n";
			}
		}

	}
}
double findAverage(numNode *current)
{
	double average=0;
	int i=0;
	while (current != nullptr)
	{
		average += current->num;
		current = current->next;
		i++;
	}
	average = average /i;
	return average;
}
