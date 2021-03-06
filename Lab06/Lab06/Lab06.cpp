#include <iostream>

#include "stdafx.h"
#include "Calculator.h"
#include "UInterface.h"

using namespace std;

void main()
{
	UInterface myInterface;
	Calculator myCalculator;
	setlocale(LC_ALL, "ukr");
	char character;
	string str;
	int count = 0;
	double sumValue = 0.0, prodValue = 1.0;

	myInterface.getID(1);
	myInterface.inputCharacter(character);

	while (character == 49 || character == 50)
	{
		myInterface.getID(2);
		myInterface.inputString(str);
		myInterface.getID(17);
		myInterface.inputInt(count);

		if (count < 1)
		{
			myInterface.getID(18);
			continue;
		}

		switch (character)
		{
		case '1':
			myCalculator.recursionSum(str, sumValue, count, myInterface);
			myInterface.getID(8);
			myInterface.getResult(sumValue);
			break;
		case '2':
			myCalculator.recursionProd(str, prodValue, count, myInterface);
			myInterface.getID(8);
			myInterface.getResult(prodValue);
			break;
		default:
			break;
		}

		myInterface.getID(1);
		myInterface.inputCharacter(character);
	}

	system("pause");
}