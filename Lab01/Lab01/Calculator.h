#pragma once
#include <iostream>
#include <string>
#include <stack>

#include "Interface.h"

using namespace std;

void getID(int id);
void inputString(string& str);
void getResult(double result);

bool isPrimeNumber(int number)
{
	if (number < 2)
	{
		getID(7);
		return false;
	}
	for (int i = 2; pow(i, 2) <= number; i++)
		if (number % i == 0)
		{
			getID(7);
			return false;
		}
	return true;
}

int priority(char operation)
{
	switch (operation)
	{
	case '+':
	case '-': return 1;
	case '*':
	case '/': return 2;
	case '^': return 3;
	default: system("pause");
	}
}

void calculation(stack <double>& stk1, stack <char>& stk2)
{
	double num2 = stk1.top();
	stk1.pop();
	double num1 = stk1.top();
	stk1.pop();

	switch (stk2.top())
	{
	case '+':
		stk1.push(num1 + num2);
		break;
	case '-':
		stk1.push(num1 - num2);
		break;
	case '*':
		stk1.push(num1 * num2);
		break;
	case '/':
		stk1.push(num1 / num2);
		break;
	case '^':
		stk1.push(pow(num1, num2));
		break;
	}

	stk2.pop();
}

bool checkStr(string str, int sizestr)
{
	int openBrackets = 0, closedBrackets = 0;
	int operands = -1, operators = 0;
	bool p = true;

	if (str.at(sizestr - 1) != '=')
	{
		getID(3);
		return false;
	}

	for (int i = 0; i < sizestr; i++)
	{

		switch (str.at(i))
		{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
			if (p)
				if (isdigit(str.at(i)))
				{
					operands++;
					p = false;
				}
			break;
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			operators++;
			p = true;
			if (i == 0 || i == sizestr - 2)
			{
				getID(9);
				return false;
			}
			break;
		case '(':
			openBrackets++;
			break;
		case ')':
			closedBrackets++;
			if (str.at(i - 1) == '(')
			{
				getID(11);
				return false;
			}
			break;
		case '=':
			if (i != sizestr - 1)
			{
				getID(10);
				return false;
			}
			break;
		default:
			getID(5);
			return false;
			break;
		}

	}

	if (operands != operators)
	{
		getID(4);
		return false;
	}

	if (openBrackets != closedBrackets)
	{
		getID(6);
		return false;
	}

	return true;
}

bool pushNumberToStack(stack <double>& stk1, string& tmp)
{
	try
	{
		stk1.push(stod(tmp));
		if (!isPrimeNumber(stoi(tmp)))
			return false;
		tmp = "\0";
	}
	catch (invalid_argument)
	{
		getID(17);
		return false;
	}
	catch (out_of_range)
	{
		getID(18);
		return false;
	}

	return true;
}

void calculatorMain()
{
	string str;
	stack <double> stk1;
	stack <char> stk2;
	string tmp = "\0";
	int dynamicBrackets = 0;
	unsigned int sizeStr, sizeStk2;

	getID(2);
	inputString(str);
	sizeStr = str.size();

	if (!checkStr(str, sizeStr))
		return;

	for (unsigned int i = 0; i < sizeStr; i++)
	{
		switch (str.at(i))
		{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
			tmp += str.at(i);
			break;
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			sizeStk2 = stk2.size();
			if (!tmp.empty())
				if (!pushNumberToStack(stk1, tmp))
					return;

			if (stk2.size() - dynamicBrackets == 0)
				stk2.push(str.at(i));

			else
			{
				for (unsigned int j = sizeStk2; j > 0; j--)
				{
					if (stk2.top() == '(') break;
					if (priority(stk2.top()) >= priority(str.at(i)))
						calculation(stk1, stk2);
				}
				stk2.push(str.at(i));
			}
			break;
		case '(':
			dynamicBrackets++;
			stk2.push(str.at(i));
			break;
		case ')':
			if (!tmp.empty())
				if (!pushNumberToStack(stk1, tmp))
					return;

			while (stk2.top() != '(')
				calculation(stk1, stk2);
			stk2.pop();
			dynamicBrackets--;
			break;
		case '=':
			if (!tmp.empty())
				if (!pushNumberToStack(stk1, tmp))
					return;
			break;
		default:
			break;
		}
	}

	while (stk1.size() != 1 && !stk2.empty())
		calculation(stk1, stk2);

	getID(8);
	getResult(stk1.top());
}