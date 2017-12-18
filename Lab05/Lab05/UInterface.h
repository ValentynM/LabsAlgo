#pragma once

#include <iostream>

using namespace std;

class UInterface
{
public:

	void getID(int id)
	{
		switch (id)
		{
		case 1:
			cout << "Enter '1' to work with list, '2' to work with tree, '0' to exit." << endl;
			break;
		case 2:
			cout << "Enter '1' to push_front, '2' to push_back, '3' to pop_front," << endl;
			cout << "'4' to pop_back, '5' to print, '6' to divide by two lists;" << endl;
			break;
		case 3:
			cout << "First part: ";
			break;
		case 4:
			cout << "Second part: ";
			break;
		case 5:
			cout << "Enter '1' to add node, '2' to print tree, '3' to get tree height," << endl;
			cout << "'4' to get count of elements on some level, '5' to divide tree by two trees," << endl;
			break;
		default:
			break;
		}
	}

	void newLine()
	{
		cout << endl;
	}

	void inputCharacter(char& ch)
	{
		cin >> ch;
	}

	template <class T>
	void inputElement(T& element)
	{
		cout << "Input element you want to push into list: ";
		cin >> element;
	}

	template <class T>
	void inputElementForDivision(T& element)
	{
		cout << "Input element for division: ";
		cin >> element;
	}

	template <class T>
	void outputData(T data)
	{
		cout << data << " ";
	}

	template <class T>
	void outputSon(T son)
	{
		cout << "(" << son << ", ";
	}

	template <class T>
	void outputBrother(T brother)
	{
		cout << brother << "); ";
	}

	void outputTreeHeight(int h)
	{
		cout << "Tree height is " << h << endl;
	}

	void nodesOnLevel(int level, int count)
	{
		cout << "The count of nodes on " << level << " level is" << count << endl;
	}

	void inputLevel(int& level)
	{
		cout << "Input level: ";
		cin >> level;
	}
};
