#pragma once
#include <iostream>

using namespace std;

class UInterface
{
public:
	
	static void getID(int id)
	{
		switch (id)
		{
		case 1:
			cout << "Point: ";
			break;
		case 2:
			cout << "Circle center: ";
			break;
		case 3:
			cout << "Radius: ";
			break;
		case 4:
			cout << "First point: ";
			break;
		case 5:
			cout << "Second point: ";
			break;
		case 6:
			cout << "Third point: ";
			break;
		case 7:
			cout << "Fourth point: ";
			break;
		default:
			break;
		}
	}

	static void getPoint(double x, double y)
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}

	static void getRadius(double r)
	{
		cout << r << endl;
	}
};
