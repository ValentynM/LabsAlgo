#pragma once
#include<iostream>

using namespace std;

class UInterface
{
public:

	void getID(int id)
	{
		switch (id)
		{
		case 1:
			cout << "Red Black Tree painting program\n" << endl;
			break;
		case 2:
			cout << "Tree height = ";
			break;
		default:
			break;
		}
	}

	bool inputCount(int& n)
	{
		cout << "Input count of nodes you want to input: ";
		cin >> n;
		if (n < 1)
		{ 
			cout << "Input error!" << endl;
			return false;
		}
		return true;
	}

	template <class T>
	void inputElement(T& element)
	{
		cout << "Input element: ";
		cin >> element;
	}

	template <class T>
	void outputData(T& data)
	{
		cout << data << " ";
	}

	template <class T>
	void outputLeftSonData(T& data)
	{
		cout << "(" << data << " , ";
	}

	void outputLeftSonEmpty()
	{
		cout << "( - , ";
	}

	template <class T>
	void outputRightSonData(T& data)
	{
		cout << data << " ); " << endl;
	}

	void outputRightSonEmpty()
	{
		cout << "- ); " << endl;
	}

	void outputColor(bool color)
	{
		if (color)
			cout << " [black] ";
		else
			cout << " [red] ";
	}
};
