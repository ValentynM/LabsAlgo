#pragma once
#include <iostream>
#include <string>
#include <stack>

#include "UInterface.h"

using namespace std;

class Calculator
{
private:
	/*static bool isPrimeNumber(int number, UInterface myInterface)
	{
		if (number < 2)
		{
			myInterface.getID(7);
			return false;
		}
		for (int i = 2; pow(i, 2) <= number; i++)
			if (number % i == 0)
			{
				myInterface.getID(7);
				return false;
			}
		return true;
	}*/

	static int priority(char operation)
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

	static void calculation(stack <double>& stk1, stack <char>& stk2)
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

	static bool checkStr(string str, int sizestr, UInterface myInterface)
	{
		int openBrackets = 0, closedBrackets = 0;
		int operands = -1, operators = 0;
		bool p = true;

		if (str.at(sizestr - 1) != '=')
		{
			myInterface.getID(3);
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
					myInterface.getID(9);
					return false;
				}
				break;
			case '(':
				if (i > 0)
				{
					if (isdigit(str.at(i - 1)) || !isdigit(str.at(i + 1)))
					{
						myInterface.getID(14);
						return false;
					}
				}
				openBrackets++;
				break;
			case ')':

				if (i == 1)
				{
					myInterface.getID(16);
					return false;
				}

				closedBrackets++;

				if (str.at(i - 1) == '(')
				{
					myInterface.getID(11);
					return false;
				}

				if (!isdigit(str.at(i - 1)))
				{
					myInterface.getID(15);
					return false;
				}
				break;
			case '=':
				if (i != sizestr - 1)
				{
					myInterface.getID(10);
					return false;
				}
				break;
			case 'x':
				if (p)
					if (!isdigit(str.at(i + 1)))
					{
						operands++;
						p = false;
					}
					else;
				else
				{
					myInterface.getID(19);
					return false;
				}

				break;
			default:
				myInterface.getID(5);
				return false;
				break;
			}

		}

		if (operands != operators)
		{
			myInterface.getID(4);
			return false;
		}

		if (openBrackets != closedBrackets)
		{
			myInterface.getID(6);
			return false;
		}

		return true;
	}

	static bool pushNumberToStack(stack <double>& stk1, string& tmp, UInterface myInterface)
	{
		try
		{
			stk1.push(stod(tmp));
			//if (!isPrimeNumber(stoi(tmp), myInterface))
			//	return false;
			tmp = "\0";
		}
		catch (invalid_argument)
		{
			myInterface.getID(12);
			return false;
		}
		catch (out_of_range)
		{
			myInterface.getID(13);
			return false;
		}

		return true;
	}

	static double polandForm(string str, int& x)
	{
		stack <double> stk1;
		stack <char> stk2;
		string tmp = "\0";
		string arg = "\0";
		string xValue = "\0";
		int dynamicBrackets = 0;
		unsigned int sizeStr = str.size(), sizeStk2;
		UInterface myInterface;

		if (!checkStr(str, sizeStr, myInterface))
		{
			system("pause");
			exit(-1);
		}

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
					if (!pushNumberToStack(stk1, tmp, myInterface))
					{
						system("pause");
						exit(-1);
					}

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
					if (!pushNumberToStack(stk1, tmp, myInterface))
					{
						system("pause");
						exit(-1);
					}

				while (stk2.top() != '(')
					calculation(stk1, stk2);
				stk2.pop();
				dynamicBrackets--;
				break;
			case '=':
				if (!tmp.empty())
					if (!pushNumberToStack(stk1, tmp, myInterface))
					{
						system("pause");
						exit(-1);
					}
				break;
			case 'x':
				str.erase(i, i + 1);
				xValue = to_string(x);
				str.insert(i, xValue);
				sizeStr = str.size();
				i = i + xValue.size() - 1;
				tmp += xValue;
				break;
			default:
				break;
			}
		}

		while (stk1.size() != 1 && !stk2.empty())
			calculation(stk1, stk2);

		myInterface.getResult(stk1.top());
		x--;
		return stk1.top();
	}

public:

	double recursionSum(string str, double& result, int x)
	{
		if (x == 0)
			return 0.0;
		result += polandForm(str, x);
		return result + recursionSum(str, result, x);
	}

	double recursionProd(string str, double& result, int x)
	{
		if (x == 0)
			return 1.0;
		result *= polandForm(str, x);
		return recursionProd(str, result, x);
	}
	
};