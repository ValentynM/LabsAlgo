#include <iostream>

#include "stdafx.h"
#include "UInterface.h"
#include "CRUD.h"

using namespace std;

void main()
{
	char ch = '1';
	UInterface myInterface;
	CRUD crud;
	int menupoint = 0;

	while (ch == '1')
	{
		myInterface.getID(11);
		myInterface.inputIntValue(menupoint);
		switch (menupoint)
		{
		case 1:
			crud.addObject();
			break;
		case 2:
			crud.searchObject();
			break;
		case 3:
			crud.outputData();
			break;
		case 4:
			crud.editObject();
			break;
		case 5:
			crud.deleteObject();
			break;
		case 6:
			crud.fileSort();
			break;
		default:
			break;
		}

		myInterface.getID(10);
		myInterface.inputCharacter(ch);
	}

	system("pause");
}

