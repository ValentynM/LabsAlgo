#include <iostream>

#include "stdafx.h"
#include "Line.h"
#include "UInterface.h"

using namespace std;

void main()
{
	UInterface myInterface;
	Line myObject;
	char ch = '1';

	setlocale(LC_ALL, "ukr");

	do
	{
		myObject.inputData(myInterface);

		myInterface.getID(1);
		myInterface.inputCharacter(ch);

	} while (ch == '1');

	system("pause");
}

