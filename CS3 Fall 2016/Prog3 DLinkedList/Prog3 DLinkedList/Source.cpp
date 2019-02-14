#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct doubly
{
	int id;
	string name;
	doubly *linka;
	doubly *linkn;
};
void Traversem(doubly *head)
{
	doubly *currentNode = head;
	while (currentNode != nullptr)
	{

		currentNode = currentNode->linkn;
	}
}
void readem()
{

}
void insert(doubly *&tail, doubly *&head)
{
	//ifstream inf;
	//inf.open("list.txt");
	//doubly *first = nullptr, *last = nullptr;
	//doubly *newNode = nullptr;
	//int num;
	//string sub;
	//while (!inf.eof())
	//{
	//	newNode = new doubly;
	//	newNode->id = num;
	//	newNode->name = sub;
	//	newNode->linkn = nullptr;
	//	newNode->linka = nullptr;
	//	if (first == nullptr)
	//	{
	//		first = newNode;
	//		last = newNode;
	//	}
	//	else
	//	{
	//		last->linka = newNode;
	//		last->linkn = newNode;
	//		last = newNode;
	//	}
	//}
}
bool isEmpty(doubly *&head, doubly *&tail)
{
	return head->linkn = tail;
}
void createm(doubly *&head, doubly *&tail)
{
	head = new doubly;
	tail = new doubly;
	head->name = "!!";
	tail->name = "{}";
	head->id = -1;
	tail->id = 9999;
	head->linkn = tail;
	tail->linkn= NULL;
	tail->linka = head;
	head->linka = NULL;

}
void main()
{
	doubly *head;
	doubly *tail;
	
	createm(head, tail);
	cout << "we work";
}