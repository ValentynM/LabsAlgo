#include "stdafx.h"
#include <iostream>
#include "Calculator.h"
#include "Matrix.h"
#include "Interface.h"

using namespace std;

void CalculatorMain();
void MatrixMain();
void GetID(int id);

int main()
{
	setlocale(LC_ALL, "ukr");
	char ch;

	do
	{
		GetID(1);
		cin >> ch;
		cin.ignore();

		switch (ch)
		{
		case '1':
			CalculatorMain();
			break;
		case '2':
			MatrixMain();
			break;
		default:
			break;
		}

	} while (ch == 49 || ch == 50);

	system("pause");
}