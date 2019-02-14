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
//bool isEmpty(doubly *head, doubly *tail);
//void Traversem(doubly *head, doubly *tail);
//void insert(doubly *head, doubly *tail, int d, string nme);
//void readem(doubly *tail, doubly *head);
//void createm(doubly *&head, doubly *&tail);
//void printem(doubly *head, doubly *tail, ofstream &outf);
bool isEmpty(doubly *head, doubly *tail)
{
	return head->linkn == tail;
}
void Traversem(doubly *head, doubly *tail)
{
	doubly *c;
	if (!isEmpty(head, tail))
	{
		c = head->linka;
		while (c != tail)
		c = c->linka;
	}
}
//void deletenode(doubly *&head, doubly *&tail, int &item, string &name)
//{
//	doubly *current;
//	doubly* previous;
//	bool found;
// 	if (isEmpty)
//		cout << "List is empty" << endl;
//	while (item = item)
//		Traversem(head, tail);
//}
void insert(doubly *head, doubly *tail, int d, string nme)
{
	doubly *previous, *next, *knew;
	knew = new doubly;
	knew->id=d;
	knew->name = nme;
	knew->linka = nullptr;
	knew->linkn = nullptr;
	previous = head;
	next = head->linkn;
	while (next != tail && knew->id > next->id)
	{
		previous = next;
		next = next->linkn;
	}
	previous->linkn = knew;
	knew->linkn = next;

	previous = head;
	next = head->linka;
	while (next != tail && knew->name > next->name)
	{
		previous = next;
		next = next->linka;
	}
	previous->linka = knew;
	knew->linka = next;
}
void readem(doubly *tail, doubly *head)
{
	int id=0;
	string name;
	ifstream inf;
	inf.open("list.txt");
	while (!inf.eof())
	{
		inf >> id;
		getline(inf, name);
		insert(head,tail, id, name);
	}
}
void createm(doubly *&head, doubly *&tail)
{
	head = new doubly;
	tail = new doubly;
	head->id = -1;
	tail->id = 9999;
	head->name = "!!";
	tail->name = "$$";
	head->linkn = tail;
	head->linka = tail;
	tail->linkn= nullptr;
	tail->linka =nullptr;

}
void printem(doubly *head, doubly *tail, ofstream &outf)
{
	doubly *c;
	if (!isEmpty(head, tail))
	{
		c = head->linkn;
		while (c != tail)
		{
			outf << c->id << " " << c->name<<endl;
			c = c->linkn;
		}
	}
	else
		outf << "List is empty" << endl;
}
void printemAlpha(doubly *head, doubly *tail, ofstream &outf)
{
	doubly *c;
	if (!isEmpty(head, tail))
	{
		c = head->linka;
		while (c != tail)
		{
			outf << c->id << " " << c->name << endl;
			c = c->linka;
		}
	}
	else
		outf << "List is empty" << endl;
}
void deletem(int id, doubly *tail, doubly *head)
{
	doubly *previous, *current, *next;
	previous = head;
	current = head->linkn;
	next = current->linkn;
	while (next != tail)
	{
		if (next->id == id)
		{
			previous->linka = next->linka;
			previous->linkn = next->linkn;
			delete next;
			return;
		}
		previous = next;
		next = next->linkn;
	}
}
void main()
{
	ofstream outf;
	outf.open("Output.txt");
	doubly *head;
	doubly *tail;
	createm(head, tail);
	readem(tail, head);
	outf << "\n\nSorted by ID.\n";
	printem(head, tail, outf);
	outf << "\n\nSorted by Name.\n";
	printemAlpha(head, tail, outf);
	outf << "\n\n Added Student\n";
	insert(head, tail, 8055, "Payne, L");
	printemAlpha(head, tail, outf);
}