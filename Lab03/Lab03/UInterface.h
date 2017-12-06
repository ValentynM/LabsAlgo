#pragma once
#include <iostream>
#include <string>
using namespace std;

class UInterface
{
public:
	
	static void getID(int id)
	{
		switch (id)
		{
		case 1:
			cout << "\nPoint:\n";
			break;
		case 2:
			cout << "\nCircle center:\n";
			break;
		case 3:
			cout << "Radius:\n";
			break;
		case 4:
			cout << "First edge:\n";
			break;
		case 5:
			cout << "Second edge:\n";
			break;
		case 6:
			cout << "Angle between this edges:\n";
			break;
		case 7:
			cout << "First diagonal:\n";
			break;
		case 8:
			cout << "Second diagonal:\n";
			break;
		case 9:
			cout << "Angle between this diagonals:\n";
			break;
		case 10:
			cout << "\nEnter '1' to continue, '0' to end program executing: ";
			break;
		case 11:
			cout << "1 - Add\n";
			cout << "2 - Search\n";
			cout << "3 - List All \n";
			cout << "4 - Edit\n";
			cout << "5 - Delete\n";
			cout << "6 - Sort\n";
			break;
		case 12:
			cout << "Enter object you need to search:\n";
			break;
		case 13:
			cout << "Error of types converting!\n";
			break;
		case 14:
			cout << "Object exist!\n";
			break;
		case 15:
			cout << "Object isn't exist!\n";
			break;
		case 16:
			cout << "Choose number of line: ";
			break;
		case 17:
			cout << "File isn't open!\n";
			break;
		case 18:
			cout << "Number of line isn't correct!\n";
			break;
		case 19:
			cout << "Choose number of line, you want to delete: ";
			break;
		case 20:
			cout << "Choose number of line, you want to edit: ";
			break;
		case 21: 
			cout << "Choose object you want to insert in this line." << endl;
			break;
		default:
			break;
		}
	}

	static void getLine(string line)
	{
		cout << line << endl;
	}

	static void getPoint(double x, double y)
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}

	static void setPoint(double& x, double& y)
	{
		cin >> x;
		cin >> y;
	}

	static void getRadius(double r)
	{
		cout << r << endl;
	}

	static void setRadius(double& r)
	{
		cin >> r;
	}

	static void getLineSegment(double x)
	{
		cout << x << endl;
	}

	static void setLineSegment(double& x)
	{
		cin >> x;
	}

	static void getAngle(double x)
	{
		cout << x <<  " rad" << endl;
	}

	static void setAngle(double& x)
	{
		cin >> x;
	}

	static void inputCharacter(char& ch)
	{
		cin >> ch;
	}

	static void inputIntValue(int& x)
	{
		cin >> x;
	}

	static void chooseSomeObject(int& x)
	{
		cout << "'1' -> Circle" << endl;
		cout << "'2' -> Triangle" << endl;
		cout << "'3' -> Quadrilateral" << endl;
		cout << "'4' -> Point" << endl;
		inputIntValue(x);
	}
};
