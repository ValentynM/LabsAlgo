#include <iostream>

#include "stdafx.h"
#include "MyClass.h"
#include "Interface.h"

using namespace std;

void main()
{
	Interface myInterface;
	MyClass myObject;
	char ch = '1';

	setlocale(LC_ALL, "ukr");

	do
	{
		myObject.mainFunction(myInterface);

		myInterface.getID(1);
		myInterface.inputCharacter(ch);

	} while (ch == '1');

	system("pause");
}

