#include "stdafx.h"
#include <iostream>

#include "RedBlackTree.h"
#include "UInterface.h"

using namespace std;

void main()
{
	RedBlackTree <int> rbt;
	UInterface myInterface;
	char ch;
	int n;
	int element;

	myInterface.getID(1);
	myInterface.inputCharacter(ch);

	while (ch == '1' || ch == '2' || ch == '3')
	{
		switch (ch)
		{
		case '1':
			if (!myInterface.inputCount(n))
				return;
			for (int i = 0; i < n; i++)
			{
				myInterface.inputElement(element);
				rbt.add(element, rbt.root);
			}
			break;
		case '2':
			rbt.print(rbt.root);
			break;
		case '3':
			rbt.deleteSubtree(rbt.root);
			break;
		default:
			break;
		}

		myInterface.getID(1);
		myInterface.inputCharacter(ch);
	}

	system("pause");
}

