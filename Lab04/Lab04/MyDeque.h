#pragma once
#include <iostream>
#include <list>
#include <string>

#include "UInterface.h"
using namespace std;

template <class type> class MyDeque
{
private:
	list <type> myList;
	int size;
	UInterface myInterface;
public:

	MyDeque(int n1)
	{
		size = n1;
		myList.resize(size);
	}

	void inputElements()
	{
		myInterface.getID(2);
		for (list <type> ::iterator myIterator = myList.begin(); myIterator != myList.end(); myIterator++)
			myInterface.inputDeque(myIterator);
	}

	void outputElements()
	{
		myInterface.getID(3);
		for (list <type> ::iterator myIterator = myList.begin(); myIterator != myList.end(); myIterator++)
			myInterface.outputDeque(myIterator);
	}

	type frontElement()
	{
		myInterface.getID(4);
		return myList.front();
	}

	type backElement()
	{
		myInterface.getID(5);
		return myList.back();
	}

	void popBackElement()
	{
		myList.pop_back();
		size--;
	}

	void popFrontElement()
	{
		myList.pop_front();
		size--;
	}

	void pushBackElement()
	{
		myInterface.getID(10);
		myList.push_back(myInterface.inputNewDequeElement(myList));
		size++;
	}

	void pushFrontElement()
	{
		myInterface.getID(10);
		myList.push_front(myInterface.inputNewDequeElement(myList));
		size++;
	}

	bool empty()
	{
		if (myList.empty())
		{
			myInterface.getID(6);
			return true;
		}
		myInterface.getID(7);
		return false;
	}

	void clear()
	{
		myInterface.getID(8);
		myList.clear();
		size = 0;
	}

	int sizeD()
	{
		myInterface.getID(9);
		myInterface.getSize(size);
		return size;
	}
};
