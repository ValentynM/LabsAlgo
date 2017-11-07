#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "UInterface.h"
using namespace std;

class MyClass
{
private:

	static void lineGenerator(UInterface myInterface)
	{
		ofstream myInputFile;
		myInputFile.open("string.txt", ios_base::out | ios_base::trunc);
		if (!myInputFile.is_open())
		{
			myInterface.getID(8);
			return;
		}

		while (myInputFile.tellp() < 104857600)
		{
			myInputFile << (char)(97 + rand() % 26);
		}
		myInputFile.close();

		myInterface.getID(2);
	}

	void lineReader(string& s, UInterface myInterface)
	{
		ifstream myInputFile;
		myInputFile.open("string.txt");

		try 
		{
			while (getline(myInputFile, s, '\n'));
		}
		catch (out_of_range)
		{
			myInterface.getID(10);
			return;
		}

		myInputFile.close();

		myInterface.getID(3);
	}

	void strAdd(string s, string s1, int n)
	{
		UInterface myInterface;
		int iterations = 0;

		if (s1.empty())
		{
			myInterface.getID(6);
			return;
		}

		if (n < 1 || n > s.length())
		{
			myInterface.getID(7);
			return;
		}

		ofstream myOutputFile;
		myOutputFile.open("Result.txt", ios_base::out | ios_base::trunc);
		if (!myOutputFile.is_open())
		{
			myInterface.getID(8);
			return;
		}

		for (int i = 0; i < s.length(); i++)
		{
			while (i == n - 1 && iterations != s1.length())
			{
				myOutputFile << s1.at(iterations);
				iterations++;
			}
			myOutputFile << s.at(i);
		}

		myOutputFile.close();

		myInterface.getID(9);
	}

public:

	void mainFunction(UInterface myInterface)
	{
		string s, s1;
		int n;
		
		lineGenerator(myInterface);
		lineReader(s, myInterface);

		myInterface.getID(4);
		myInterface.getString(s1);

		myInterface.getID(5);
		myInterface.getNumber(n);

		strAdd(s, s1, n);
	}
};
