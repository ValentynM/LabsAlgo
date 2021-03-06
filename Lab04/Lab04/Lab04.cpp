#include <iostream>

#include "stdafx.h"
#include "MyDeque.h"
#include "UInterface.h"

using namespace std;

int sizeDeque(UInterface myInterface)
{
	int size;
	myInterface.getID(11);
	myInterface.setSize(size);
	return size;
}




void main()
{
	UInterface myInterface;
	char ch;
	MyDeque <int> myDeque(sizeDeque(myInterface));
	myInterface.getID(1);
	myInterface.inputCharacter(ch);

	do
	{
		switch (ch)
		{
		case '1':
			myDeque.inputElements();
			break;
		case '2':
			myDeque.outputElements();
			break;
		case '3':
			myDeque.sizeD();
			break;
		case '4':
			myDeque.clear();
			break;
		case '5':
			myDeque.popBackElement();
			break;
		case '6':
			myDeque.popFrontElement();
			break;
		case '7':
			myDeque.pushBackElement();
			break;
		case '8':
			myDeque.pushFrontElement();
			break;
		case '9':
			myDeque.empty();
			break;
		default:
			break;
		}

		myInterface.getID(1);
		myInterface.inputCharacter(ch);
	} while (ch > 48 && ch < 58);

	system("pause");
}

