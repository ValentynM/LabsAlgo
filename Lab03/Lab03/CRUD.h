#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "UInterface.h"
#include "Figure.h"

using namespace std;

enum objectTypes
{
	objectPoint,
	objectCircle,
	objectTriangle,
	objectQuadrilateral
};

class CRUD
{
private:
	Point point;
	Circle circle;
	Triangle triangle;
	Quadrilateral quadrilateral;

	bool Search(int index, string str)
	{
		string tmp;
		double tmp1;
		ifstream myFile;
		myFile.open("MyFile.csv");

		if (!myFile.is_open())
		{
			UInterface::getID(17);
			return false;
		}

		while (!myFile.eof())
		{
			getline(myFile, tmp, ';');
			if (tmp == str)
			{
				try
				{
					switch (index)
					{
					case objectPoint:
						getline(myFile, tmp, ';');
						tmp1 = stod(tmp);
						if (tmp1 != point.getX())
						{
							getline(myFile, tmp, '\n');
							continue;
						}
						getline(myFile, tmp, '\n');
						tmp1 = stod(tmp);
						if (tmp1 != point.getY())
							continue;
						return true;
						break;
					case objectCircle:
						getline(myFile, tmp, ';');
						tmp1 = stod(tmp);
						if (tmp1 != circle.getX())
						{
							getline(myFile, tmp, '\n');
							continue;
						}
						getline(myFile, tmp, ';');
						tmp1 = stod(tmp);
						if (tmp1 != circle.getY())
						{
							getline(myFile, tmp, '\n');
							continue;
						}
						getline(myFile, tmp, '\n');
						tmp1 = stod(tmp);
						if (tmp1 != circle.getRadius())
							continue;
						return true;
						break;
					case objectTriangle:
						getline(myFile, tmp, ';');
						tmp1 = stod(tmp);
						if (tmp1 != triangle.getX())
						{
							getline(myFile, tmp, '\n');
							continue;
						}
						getline(myFile, tmp, ';');
						tmp1 = stod(tmp);
						if (tmp1 != triangle.getY())
						{
							getline(myFile, tmp, '\n');
							continue;
						}
						getline(myFile, tmp, ';');
						tmp1 = stod(tmp);
						if (tmp1 != triangle.getFirstLineSegment())
						{
							getline(myFile, tmp, '\n');
							continue;
						}
						getline(myFile, tmp, ';');
						tmp1 = stod(tmp);
						if (tmp1 != triangle.getSecondLineSegment())
							continue;
						getline(myFile, tmp, '\n');
						tmp1 = stod(tmp);
						if (tmp1 != triangle.getAngle())
							continue;
						return true;
						break;
					case objectQuadrilateral:
						getline(myFile, tmp, ';');
						tmp1 = stod(tmp);
						if (tmp1 != quadrilateral.getX())
						{
							getline(myFile, tmp, '\n');
							continue;
						}
						getline(myFile, tmp, ';');
						tmp1 = stod(tmp);
						if (tmp1 != quadrilateral.getY())
						{
							getline(myFile, tmp, '\n');
							continue;
						}
						getline(myFile, tmp, ';');
						tmp1 = stod(tmp);
						if (tmp1 != quadrilateral.getFirstDiagonal())
						{
							getline(myFile, tmp, '\n');
							continue;
						}
						getline(myFile, tmp, ';');
						tmp1 = stod(tmp);
						if (tmp1 != quadrilateral.getSecondDiagonal())
						{
							getline(myFile, tmp, '\n');
							continue;
						}
						getline(myFile, tmp, '\n');
						tmp1 = stod(tmp);
						if (tmp1 != quadrilateral.getAngle())
							continue;
						return true;
						break;
					default:
						break;
					}
				}
				catch (invalid_argument)
				{
					UInterface::getID(13);
					return false;
				}
				catch (out_of_range)
				{
					UInterface::getID(13);
					return false;
				}
			}
			else
			{
				getline(myFile, tmp, '\n');
				continue;
			}
		}
		

		myFile.close();
		return false;
	}
	
public:

	void addObject()
	{
		int tmp;
		
		ofstream myFile;
		myFile.open("MyFile.csv", ios_base::app);
		UInterface::chooseSomeObject(tmp);

		if (!myFile.is_open())
		{
			UInterface::getID(17);
			return;
		}

		switch (tmp)
		{
		case 1:
			circle.setParameters();
			myFile << "Circle" << ";";
			myFile << circle.getX() << ";";
			myFile << circle.getY() << ";";
			myFile << circle.getRadius() << ";";
			myFile << "\n";
			break;
		case 2:
			triangle.setParameters();
			myFile << "Triangle" << ";";
			myFile << triangle.getX() << ";";
			myFile << triangle.getY() << ";";
			myFile << triangle.getFirstLineSegment() << ";";
			myFile << triangle.getSecondLineSegment() << ";";
			myFile << triangle.getAngle() << ";";
			myFile << "\n";
			break;
		case 3:
			quadrilateral.setParameters();
			myFile << "Quadrilateral" << ";";
			myFile << quadrilateral.getX() << ";";
			myFile << quadrilateral.getY() << ";";
			myFile << quadrilateral.getFirstDiagonal() << ";";
			myFile << quadrilateral.getSecondDiagonal() << ";";
			myFile << quadrilateral.getAngle() << ";";
			myFile << "\n";
			break;
		default:
			point.setParameters();
			myFile << "Point" << ";";
			myFile << point.getX() << ";";
			myFile << point.getY() << ";";
			myFile << "\n";
			break;
		}

		myFile.close();
	}

	void outputData()
	{
		string tmp;
		ifstream myFile;
		myFile.open("MyFile.csv");

		if (!myFile.is_open())
		{
			UInterface::getID(17);
			return;
		}

		while (!myFile.eof())
		{
			getline(myFile, tmp, '\n');
			for (int i = 0; i < tmp.size(); i++)
				if (tmp.at(i) == ';') tmp.at(i) = ' ';
			UInterface::getLine(tmp);
		}

		myFile.close();
	}

	void searchObject()
	{
		int tmp;
		UInterface::chooseSomeObject(tmp);
		UInterface::getID(12);
		string objectType;

		switch (tmp)
		{
		case 1:
			circle.setParameters();
			if (Search(1, "Circle"))
				UInterface::getID(14);
			else
				UInterface::getID(15);
			break;
		case 2:
			triangle.setParameters();
			if (Search(2, "Triangle"))
				UInterface::getID(14);
			else
				UInterface::getID(15);
			break;
		case 3:
			quadrilateral.setParameters();
			if (Search(3, "Quadrilateral"))
				UInterface::getID(14);
			else
				UInterface::getID(15);
			break;
		case 4:
			point.setParameters();
			if (Search(0, "Point"))
				UInterface::getID(14);
			else
				UInterface::getID(15);
			break;
		default:
			break;
		}
	}

	void deleteObject()
	{
		int numberOfLine;
		int iteration = 0;
		int count = 0;
		vector<string> vct;
		string tmp;
		ifstream myFile;
		myFile.open("MyFile.csv");

		if (!myFile.is_open())
		{
			UInterface::getID(17);
			return;
		}

		UInterface::getID(19);
		UInterface::inputIntValue(numberOfLine);
		if (numberOfLine < 1)
		{
			UInterface::getID(18);
			return;
		}

		while (!myFile.eof())
		{
			iteration++;
			if (iteration == numberOfLine)
			{
				getline(myFile, tmp, '\n');
				continue;
			}
			count++;
			vct.resize(count);
			getline(myFile,vct[count-1], '\n');
		}

		myFile.close();

		remove("MyFile.csv");

		ofstream myNewFile;
		myNewFile.open("MyFile.csv", ios_base::trunc);

		if (!myNewFile.is_open())
		{
			UInterface::getID(17);
			return;
		}

		for (int i = 0; i < vct.size(); i++)
			if(vct[i]!= "")
				myNewFile << vct[i] << '\n';
		myNewFile.close();
	}

	void editObject()
	{
		int numberOfLine;
		int iteration = 0;
		vector<string> vct;
		string tmp;

		ifstream myFile;
		myFile.open("MyFile.csv");

		if (!myFile.is_open())
		{
			UInterface::getID(17);
			return;
		}

		UInterface::getID(20);
		UInterface::inputIntValue(numberOfLine);
		if (numberOfLine < 1)
		{
			UInterface::getID(18);
			return;
		}

		while (!myFile.eof())
		{
			iteration++;
			vct.resize(iteration);

			if (iteration == numberOfLine)
			{
				vct[iteration - 1] = "";
				UInterface::getID(21);
				addObject();
				getline(myFile, tmp, '\n');
				continue;
			}

			getline(myFile, vct[iteration - 1], '\n');

		}
		
		myFile.close();
		vct[numberOfLine - 1] = vct[iteration - 2];

		remove("MyFile.csv");

		ofstream myNewFile;
		myNewFile.open("MyFile.csv", ios_base::trunc);

		if (!myNewFile.is_open())
		{
			UInterface::getID(17);
			return;
		}

		for (int i = 0; i < vct.size() - 2; i++)
			myNewFile << vct[i] << "\n";
		myNewFile.close();
	}

	void fileSort()
	{
		vector <string> vct;
		int count = 0;
		ifstream myFile;
		myFile.open("MyFile.csv");

		if (!myFile.is_open())
		{
			UInterface::getID(17);
			return;
		}

		while (!myFile.eof())
		{
			vct.resize(++count);
			getline(myFile, vct[count - 1], '\n');
			if (vct[count - 1] == "")
			{
				vct.resize(--count);
			}
		}


		myFile.close();
		sort(vct.begin(), vct.end());

		remove("MyFile.csv");

		ofstream myNewFile;
		myNewFile.open("MyFile.csv", ios_base::trunc);

		if (!myNewFile.is_open())
		{
			UInterface::getID(17);
			return;
		}

		for (int i = 0; i < vct.size(); i++)
			myNewFile << vct[i] << "\n";
		myNewFile.close();
	}

};