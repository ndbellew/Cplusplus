/*
Nathan Bellew
4/4/2016
CS2
Homework 7
infix converter to postfix/Polish Notation.
*/

#include <iomanip>
#include <iostream>

#include <string>
#include "LinkedStack.h"
using namespace std;
string InfixtoPostfix(string equation);
int Operator(char op);
//void evaluateExpression()

bool Operators(char Operator)
{
	switch (Operator)
	{
	case '+':
	case '-':
	case '/':
	case '*':
		return true;
	default:
		return false;
	}

}
int getOperatorPrec(char op)
{
	int precedence = -1;
	switch (op)
	{
	case '+':
	case '-':
		precedence = 2;
		break;
	case '*':
	case '/':
		precedence = 3;
		break;
	}
	return precedence;
}

bool values(char op)
{
	if (op >= 'a' && op <= 'z')
		return true;
	else if (op >= 'A' && op <= 'Z')
		return true;
	else
		return false;
}
string prefixtopostfix(string &prefix, string &postfix)
{
	//charStack.push('(');
	LinkedStack<char> charStack;
	if (!charStack.isEmpty())
		charStack.clear();
	int length;
	length = prefix.size();
	for (int i = 0; i <prefix.size(); i++)
	{
		const char op = prefix[i];

		if (op=='(')
			charStack.push(op);
		else if (values(op))
		{
			postfix.push_back(op);
		}
		else if (Operators(op))
		{
			if (charStack.isEmpty())
				charStack.push(op);
			//while (!charStack.isEmpty())
			else
			{
			
				int op1, op2;
				op1 = getOperatorPrec(op);
				op2 = getOperatorPrec(charStack.top());
				if (op1 > op2)
					charStack.push(op);
				else if (op1 < op2)
				{
					while (!charStack.isEmpty())
					{
						postfix.push_back(charStack.top());
						charStack.pop();
						if (!charStack.isEmpty())
							op2 = getOperatorPrec(charStack.top());
					}
					if (op2==1)
					{
						postfix.push_back(charStack.top());
						charStack.pop();
					}
					charStack.push(op);

				}
				else 
				{
					postfix.push_back(charStack.top());
					charStack.pop();
					charStack.push(op);
				}
				
			}
		}

		else
			break;
	}
	while (!charStack.isEmpty())
	{
		postfix.push_back(charStack.top());
		charStack.pop();
	}
	return postfix;
}
int main()
{
	int i;
	LinkedStack<char> charStack;
	if (!charStack.isEmpty())
		charStack.clear();
	string prefix, postfix;
	prefix.empty();
	int ans = 1;
	string answer;
	char op;
	do
	{
			postfix = "";
			cout << "Please enter a prefix notation. \n (i.e.) a+b-c\n" << endl;
			//evaluateExpression(cin, charStack, ch)
			cin >> prefix;
			cout << "Postfix: " << prefixtopostfix(prefix, postfix) << "\n";
	} while (ans == 1);
	system("pause");
	return 0;
}
