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
			cout << "\nInput adjacency matrix (elements equal to 0 or 1)." << endl;
			break;
		case 2:
			cout << "\nInput count of nodes: ";
			break;
		case 3:
			cout << "Input error! Try again." << endl;
			break;
		case 4:
			cout << "\nInput '1' if you want to continue, else '0': ";
			break;
		case 5:
			cout << "Uncorrect count of nodes! Try again." << endl;
			break;
		case 6:
			cout << "Input initial vertex error! Try again." << endl;
			break;
		case 7:
			cout << "Input initial vertex: ";
			break;
		case 8:
			cout << "There isn't any path!" << endl;
			break;
		case 9:
			cout << "Path: ";
			break;
		case 10:
			cout << "Initial vertex input error!" << endl;
			break;
		default:
			break;
		}
	}

	bool graphMatrixElementInput(int& x)
	{
		cin >> x;
		if (x == 0 || x == 1)
			return true;
		return false;
	}

	int countOfNodesInput(int& n)
	{
		cin >> n;
		return n;
	}

	int initialVertexInput(int& initialVertex)
	{
		cin >> initialVertex;
		return initialVertex;
	}

	void outputWay(int& road)
	{
		cout << road << " ";
	}
};
