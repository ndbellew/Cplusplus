/*
Nathan Bellew
April 26, 2016
CS2
Lab 7
*/
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include "BinarySearchTree.h"

using namespace std;
void menu()
{
	cout << "Welcome to Word Sorting Program!\n Menu Options: \n" <<
		"1. Choose a file.\n" <<
		"2. Sort in inorder.\n3. Sort in postorder.\n4. Sort in preorder.\n" <<
		"5. Lookup node.\n6. Delete node.\n7. Exit Program!\n";
}
void main()
{
	ifstream inf;
	ofstream outf;
	string fileName, input, search;
	int answer, i = 0;
	BinarySearchTree<string> tree;
	do{
		system("CLS");
		menu();
		cin >> answer;
		switch (answer)
		{
		case 1://Input file
			system("CLS");
			cout << "1. Enter File Name.\n";
			cout << "-->";
			cin >> fileName;
			inf.open(fileName);
			while (!inf.eof())
			{
				inf >> input >> ws;
				//cout << input.size();
				for (int i = input.size(); i >= 0; i--)
				{
					if (isupper(input[i]))
						input[i] = tolower(input[i]);
					else if (ispunct(input[i]))
						input.erase(i, 1);
				}
				tree.insertNode(input);
			}
			break;
		case 2://display words inorder
			system("CLS");
			tree.inorderTraversal();
			system("pause");
			break;
		case 3://display words postorder
			system("CLS");
			tree.postorderTraversal();
			system("pause");
			break;
		case 4://display words preorder
			system("CLS");
			tree.preorderTraversal();
			system("pause");
			break;
			case 5://lookup
				cout << "Enter word you are looking up.\n"
				<< "-->";
				cin >> search;
					tree.PrintSingleNode(search);
				system("pause");
				break;
			case 6://delete
				cout << "Enter word you want deleted.\n"
				<< "-->";
				cin >> search;
				tree.deleteNode(search);
				system("pause");
				break;
			case 7://exit program
				cout << "Goodbye.\n";
				system("pause");
				break;
				default:
				system("CLS");
				cout << "ERROR CODE 10071823!\nSorry input not found, please try again.\n ";
				system("pause");
		}
		}while (answer != 7);
	}
