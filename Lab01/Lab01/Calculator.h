#pragma once
#include <iostream>
#include <string>
#include <stack>
#include "Interface.h"

using namespace std;

void GetID(int id);
void InputString(string & str);
void GetResult(double result);

bool Isprimenumber(int num)
{
	if (num < 2)
	{
		GetID(7);
		return false;
	}
	for (int i = 2; pow(i, 2) <= num; i++)
		if (num % i == 0)
		{
			GetID(7);
			return false;
		}
	return true;
}

int Priority(char a)
{
	switch (a)
	{
	case '+':
	case '-': return 1;
	case '*':
	case '/': return 2;
	case '^': return 3;
	default: system("pause");
	}
}

void Calculation(stack <double> & stk1, stack <char> & stk2)
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

bool CheckStr(string str, int sizestr)
{
	int openbrackets = 0, closedbrackets = 0;
	int operands = -1, operators = 0;
	bool p = true;

	if (str.at(sizestr - 1) != '=')
	{
		GetID(3);
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
				GetID(9);
				return false;
			}
			break;
		case '(':
			openbrackets++;
			break;
		case ')':
			closedbrackets++;
			if (str.at(i - 1) == '(')
			{
				GetID(11);
				return false;
			}
			break;
		case '=':
			if (i != sizestr - 1)
			{
				GetID(10);
				return false;
			}
			break;
		default:
			GetID(5);
			return false;
			break;
		}

	}

	if (operands != operators)
	{
		GetID(4);
		return false;
	}

	if (openbrackets != closedbrackets)
	{
		GetID(6);
		return false;
	}

	return true;
}

bool PushNumberToStack(stack <double> & stk1, string & tmp)
{
	try
	{
		stk1.push(stod(tmp));
		if (!Isprimenumber(stoi(tmp)))
			return false;
		tmp = "\0";
	}
	catch (invalid_argument)
	{
		GetID(17);
		return false;
	}
	catch (out_of_range)
	{
		GetID(18);
		return false;
	}

	return true;
}

void CalculatorMain()
{
	string str;
	stack <double> stk1;
	stack <char> stk2;
	string tmp = "\0";
	int dynamicbrackets = 0;
	unsigned int sizestr, sizestk2;

	GetID(2);
	InputString(str);
	sizestr = str.size();

	if (!CheckStr(str, sizestr))
		return;

	for (unsigned int i = 0; i < sizestr; i++)
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
			sizestk2 = stk2.size();
			if (!tmp.empty())
				if (!PushNumberToStack(stk1, tmp))
					return;

			if (stk2.size() - dynamicbrackets == 0)
				stk2.push(str.at(i));

			else
			{
				for (unsigned int j = sizestk2; j > 0; j--)
				{
					if (stk2.top() == '(') break;
					if (Priority(stk2.top()) >= Priority(str.at(i)))
						Calculation(stk1, stk2);
				}
				stk2.push(str.at(i));
			}
			break;
		case '(':
			dynamicbrackets++;
			stk2.push(str.at(i));
			break;
		case ')':
			if (!tmp.empty())
				if (!PushNumberToStack(stk1, tmp))
					return;

			while (stk2.top() != '(')
				Calculation(stk1, stk2);
			stk2.pop();
			dynamicbrackets--;
			break;
		case '=':
			if (!tmp.empty())
				if (!PushNumberToStack(stk1, tmp))
					return;
			break;
		default:
			break;
		}
	}

	while (stk1.size() != 1 && !stk2.empty())
		Calculation(stk1, stk2);

	GetID(8);
	GetResult(stk1.top());
}