#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

#include "Interface.h"

using namespace std;

class Matrix
{
private:
	int size;
	vector<vector<double> > vct;

	static void inputMainMatrix(Matrix &myMatrix, Interface myInterface)
	{
		for (int i = 0; i < myMatrix.size; i++)
			for (int j = 0; j < myMatrix.size; j++)
				if (j > i)
					myInterface.inputElement(myMatrix.vct[i][j], i, j);
				else
				{
					myMatrix.vct[i][j] = 0;
					myInterface.outputElement(myMatrix.vct[i][j], i, j);
				}
	}

	static void inputAdditionalMatrix(Matrix& myAdditionalMatrix, Interface myInterface)
	{
		for (int i = 0; i < myAdditionalMatrix.size; i++)
			for (int j = 0; j < myAdditionalMatrix.size; j++)
				myInterface.inputElement(myAdditionalMatrix.vct[i][j], i, j);
	}

	static void outputMatrix(Matrix myMatrix, Interface myInterface)
	{
		for (int i = 0; i < myMatrix.size; i++)
			for (int j = 0; j < myMatrix.size; j++)
				myInterface.outputElement(myMatrix.vct[i][j], i, j);
	}

	static void additionMatrix(Matrix& myMatrix, Interface myInterface)
	{
		Matrix tmp(myMatrix.size);
		myInterface.getID(15);
		inputAdditionalMatrix(tmp, myInterface);
		for (int i = 0; i < myMatrix.size; i++)
			for (int j = 0; j < myMatrix.size; j++)
				myMatrix.vct[i][j] += tmp.vct[i][j];
	}

	static void subtractionMatrix(Matrix& myMatrix, Interface myInterface)
	{
		Matrix tmp(myMatrix.size);
		myInterface.getID(15);
		inputAdditionalMatrix(tmp, myInterface);
		for (int i = 0; i < myMatrix.size; i++)
			for (int j = 0; j < myMatrix.size; j++)
				myMatrix.vct[i][j] -= tmp.vct[i][j];
	}

	static void multiplicationMatrix(Matrix& myMatrix, Interface myInterface)
	{
		Matrix tmp1(myMatrix.size), tmp2(myMatrix.size);
		myInterface.getID(15);
		inputAdditionalMatrix(tmp2, myInterface);
		for (int i = 0; i < myMatrix.size; i++)
			for (int j = 0; j < myMatrix.size; j++)
			{
				tmp1.vct[i][j] = myMatrix.vct[i][j];
				myMatrix.vct[i][j] = 0;
			}

		for (int i = 0; i < myMatrix.size; i++)
			for (int j = 0; j < myMatrix.size; j++)
				for (int k = 0; k < myMatrix.size; k++)
					myMatrix.vct[i][j] += tmp1.vct[i][k] * tmp2.vct[k][j];
	}

	static void divisionMatrix(Matrix& myMatrix, Interface myInterface)
	{
		Matrix tmp1(myMatrix.size), tmp2(myMatrix.size), E(myMatrix.size);
		double dtmp;
		myInterface.getID(15);
		inputAdditionalMatrix(tmp2, myInterface);

		for (int i = 0; i < myMatrix.size; i++)
			for (int j = 0; j < myMatrix.size; j++)
			{
				tmp1.vct[i][j] = myMatrix.vct[i][j];
				myMatrix.vct[i][j] = 0;
				if (i == j)
					E.vct[i][j] = 1;
				else
					E.vct[i][j] = 0;
			}

		for (int i = 0; i < myMatrix.size; i++)
		{
			dtmp = tmp2.vct[i][i];

			for (int j = 0; j < myMatrix.size; j++)
			{
				tmp2.vct[i][j] /= dtmp;
				E.vct[i][j] /= dtmp;
			}

			for (int k = i + 1; k < myMatrix.size; k++)
			{
				dtmp = tmp2.vct[k][i];

				for (int j = 0; j < myMatrix.size; j++)
				{
					tmp2.vct[k][j] -= tmp2.vct[i][j] * dtmp;
					E.vct[k][j] -= E.vct[i][j] * dtmp;
				}
			}
		}

		for (int i = myMatrix.size - 1; i > 0; i--)
		{
			for (int k = i - 1; k >= 0; k--)
			{
				dtmp = tmp2.vct[k][i];

				for (int j = 0; j < myMatrix.size; j++)
				{
					tmp2.vct[k][j] -= tmp2.vct[i][j] * dtmp;
					E.vct[k][j] -= E.vct[i][j] * dtmp;
				}
			}
		}

		for (int i = 0; i < myMatrix.size; i++)
			for (int j = 0; j < myMatrix.size; j++)
				for (int k = 0; k < myMatrix.size; k++)
					myMatrix.vct[i][j] += tmp1.vct[i][k] * tmp2.vct[k][j];
	}

	static void saveMatrix(Matrix myMatrix, Interface myInterface)
	{
		unsigned int start = clock(), finish;
		ofstream myfile;
		myfile.open("MyFile.csv", ios_base::out | ios_base::trunc);
		if (!myfile.is_open())
		{
			myInterface.getID(16);
			return;
		}

		myfile << myMatrix.size;
		myfile << "\n";

		for (int i = 0; i < myMatrix.size; i++)
			for (int j = 0; j < myMatrix.size; j++)
				if (myMatrix.vct[i][j] != 0)
				{
					myfile << myMatrix.vct[i][j];
					myfile << ';';
					myfile << i;
					myfile << ';';
					myfile << j;
					myfile << "\n";
				}

		myInterface.getID(19);
		myInterface.memory(sizeof(vector<double>) * pow(myMatrix.size, 2), myfile.tellp());
		myfile.close();

		finish = clock();
		myInterface.executionTime(finish - start);
	}

	static bool loadMatrix(Matrix& myMatrix, Interface myInterface)
	{
		unsigned int start = clock(), finish;
		ifstream myfile;
		myfile.open("MyFile.csv");
		string element, raw, column;
		int iRaw, iCol;
		double dElement;
		int k;


		try
		{
			if (myfile.is_open())
			{
				getline(myfile, element, '\n');

				if (element.empty())
				{
					myInterface.getID(21);
					return false;
				}

				k = stoi(element);

				if (k != myMatrix.size)
				{
					myMatrix.vct.resize(k);
					for (int i = 0; i < k; ++i)
						myMatrix.vct[i].resize(k);

					if (k > myMatrix.size)
						for (int i = 0; i < myMatrix.size; i++)
							for (int j = 0; j < myMatrix.size; j++)
							{
								if (myMatrix.vct[i][j] == NULL)
									myMatrix.vct[i][j] = 0;
							}
					myMatrix.size = k;
				}

				while (getline(myfile, element, ';'))
				{
					getline(myfile, raw, ';');
					getline(myfile, column, '\n');
					iRaw = stoi(raw);
					iCol = stoi(column);
					dElement = stod(element);

					myMatrix.vct[iRaw][iCol] = dElement;
				}

				myInterface.getID(20);
				myfile.close();
			}
			else
			{
				myInterface.getID(22);
				return false;
			}
		}
		catch (invalid_argument)
		{
			myInterface.getID(17);
			return false;
		}
		catch (out_of_range)
		{
			myInterface.getID(18);
			return false;
		}

		finish = clock();
		myInterface.executionTime(finish - start);

		return true;
	}

public:

	Matrix(int sizeMatrix)
	{
		size = sizeMatrix;
		vct.resize(size);
		for (int i = 0; i < size; i++)
			vct[i].resize(size);
	}

	 static void matrixMain(Matrix myMatrix)
	{
		Interface myInterface;
		char ch = '1';
		myInterface.getID(13);
		inputMainMatrix(myMatrix, myInterface);

		do
		{
			myInterface.getID(14);
			myInterface.inputCharacter(ch);

			switch (ch)
			{
			case '1':
				additionMatrix(myMatrix, myInterface);
				break;
			case '2':
				subtractionMatrix(myMatrix, myInterface);
				break;
			case '3':
				multiplicationMatrix(myMatrix, myInterface);
				break;
			case '4':
				divisionMatrix(myMatrix, myInterface);
				break;
			case '5':
				saveMatrix(myMatrix, myInterface);
				break;
			case '6':
				if (!loadMatrix(myMatrix, myInterface))
					return;
				break;
			case '7':
				outputMatrix(myMatrix, myInterface);
				break;
			}
		} while (ch >= 49 && ch <= 55);
	}
};