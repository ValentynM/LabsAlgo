#include "stdafx.h"
#include <iostream>

#include "MyList.h"
#include "myTree.h"
#include "UInterface.h"
using namespace std;

template <class T>
void toList(UInterface myInterface)
{
	myList<int> list, firstPart, secondPart;
	char ch;
	T element;

	myInterface.getID(2);
	myInterface.inputCharacter(ch);

	while (ch >= 49 && ch <= 54)
	{
		switch (ch)
		{
		case '1':
			myInterface.inputElement(element);
			list.push_front(element);
			break;
		case '2':
			myInterface.inputElement(element);
			list.push_back(element);
			break;
		case '3':
			list.pop_front();
			break;
		case '4':
			list.pop_back();
			break;
		case '5':
			list.print(myInterface);
			myInterface.newLine();
			break;
		case '6':
			myInterface.inputElementForDivision(element);
			list.divideByTwo(element, firstPart, secondPart);
			myInterface.getID(3);
			firstPart.print(myInterface);
			myInterface.getID(4);
			secondPart.print(myInterface);
			myInterface.newLine();
			break;
		default:
			break;
		}

		myInterface.inputCharacter(ch);

	}
}

template <class T>
void toTree(UInterface myInterface)
{
	myTree<int> tree, firstPart, secondPart;
	char ch;
	T element;
	int level;

	myInterface.getID(5);
	myInterface.inputCharacter(ch);

	while (ch >= 49 && ch <= 53)
	{
		switch (ch)
		{
		case '1':
			myInterface.inputElement(element);
			tree.addNode(element);
			break;
		case '2':
			tree.print(myInterface);
			myInterface.newLine();
			break;
		case '3':
			myInterface.outputTreeHeight(tree.getTreeHeight());
			break;
		case '4':
			myInterface.inputLevel(level);
			myInterface.nodesOnLevel(level, tree.getTreeNodesOneLevel(level));
			break;
		case '5':
			myInterface.inputElementForDivision(element);
			tree.divideByTwo(element, firstPart, secondPart);
			myInterface.getID(3);
			firstPart.print(myInterface);
			myInterface.getID(4);
			secondPart.print(myInterface);
			myInterface.newLine();
			break;
		default:
			break;
		}

		myInterface.inputCharacter(ch);

	}
}

void main()
{
	UInterface myInterface;
	char ch;

	myInterface.getID(1);
	myInterface.inputCharacter(ch);

	while (ch == 49 || ch == 50)
	{
		switch (ch)
		{
		case '1':
			toList<int> (myInterface);
			break;
		case '2':
			toTree<int> (myInterface);
			break;
		default:
			break;
		}

		myInterface.getID(1);
		myInterface.inputCharacter(ch);

	} 

	system("pause");
}

