#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Line
{
private:
	string s;
	string s1;
public:
	Line()
	{
	}

	void LineGenerator()
	{
		ofstream myfile1, myfile2;
		myfile1.open("string1.txt", ios_base::out | ios_base::trunc);
		if (!myfile1.is_open())
		{
			return;
		}

		while (myfile1.tellp() < 104857600)
		{
			myfile1 << (char) rand() % 127;
		}

		myfile1.close();
		
		myfile2.open("string2.txt", ios_base::out | ios_base::trunc);
		if (!myfile2.is_open())
		{
			return;
		}

		while (myfile2.tellp() < 104857600)
		{
			myfile2 << (char) rand() % 127;
		}

		myfile2.close();
	}
};