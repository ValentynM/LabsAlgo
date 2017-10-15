#include <iostream>

#include "stdafx.h"
#include "Calculator.h"
#include "Matrix.h"
#include "Interface.h"

using namespace std;

void calculatorMain();
void matrixMain();
void getID(int id);
void inputCharacter(char& ch);

int main()
{
	setlocale(LC_ALL, "ukr");
	char character;

	do
	{
		getID(1);
		inputCharacter(character);

		switch (character)
		{
		case '1':
			calculatorMain();
			break;
		case '2':
			matrixMain();
			break;
		default:
			break;
		}

	} while (character == 49 || character == 50);

	system("pause");
}