#include <iostream>

#include "stdafx.h"
#include "Calculator.h"
#include "Matrix.h"
#include "UInterface.h"

using namespace std;

void goToMatrix(UInterface myInterface)
{
	int sizeMatrix;
	myInterface.getID(12);
	myInterface.inputSize(sizeMatrix);
	Matrix myMatrix(sizeMatrix);
	myMatrix.matrixMain(myMatrix);
}

void main()
{
	UInterface myInterface;
	Calculator myCalculator;
	setlocale(LC_ALL, "ukr");
	char character;

	do
	{
		myInterface.getID(1);
		myInterface.inputCharacter(character);

		switch (character)
		{
		case '1':
			myCalculator.calculatorMain();
			break;
		case '2':
			goToMatrix(myInterface);
			break;
		default:
			break;
		}

	} while (character == 49 || character == 50);

	system("pause");
}