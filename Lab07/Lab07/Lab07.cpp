#include "stdafx.h"
#include <iostream>

#include "RedBlackTree.h"
#include "UInterface.h"

using namespace std;

int findColor(int count)
{
	int n = -1;
	int sum = 0;

	do
	{
		n++;
		sum += pow(2, n);
	} while (count >= sum);

	return (sum - pow(2, n) - 1);
}

void main()
{
	RedBlackTree <int> rbt;
	UInterface myInterface;
	int n;
	int element;
	int firstRedIndex;

	myInterface.getID(1);

	if (!myInterface.inputCount(n))
		return;
	firstRedIndex = findColor(n);
	for (int i = 0; i < n; i++)
	{
		myInterface.inputElement(element);
		if(i <= firstRedIndex)
			rbt.add(element, rbt.root);
		else
			rbt.add(element, rbt.root, false);
	}

	rbt.print(rbt.root);

	rbt.deleteSubtree(rbt.root);
	system("pause");
}

