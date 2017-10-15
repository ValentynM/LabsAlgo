#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

#include "Interface.h"

using namespace std;

void getID(int id);
void inputSize(int& size);
void inputElement(double& element, int line, int column);
void outputElement(double element, int line, int column);
void inputCharacter(char& character);
void memory(int memory1, int memory2);
void executionTime(unsigned int time);

void inputMainMatrix(vector < vector <double> >& vct, int sizeMatrix)
{
	for (int i = 0; i < sizeMatrix; i++)
		for (int j = 0; j < sizeMatrix; j++)
			if (j > i)
				 inputElement(vct[i][j], i, j);
			else
			{
				vct[i][j] = 0;
				outputElement(vct[i][j], i, j);
			}
}

void inputAdditionalMatrix(vector < vector <double> >& tmp, int sizeMatrix)
{
	for (int i = 0; i < sizeMatrix; i++)
		for (int j = 0; j < sizeMatrix; j++)
			inputElement(tmp[i][j], i, j);
}

void outputMatrix(vector < vector <double> > vct, int sizeMatrix)
{
	for (int i = 0; i < sizeMatrix; i++)
		for (int j = 0; j < sizeMatrix; j++)
			outputElement(vct[i][j], i, j);
}

void additionMatrix(vector < vector <double> >& vct, int sizeMatrix)
{
	vector < vector <double> > tmp(sizeMatrix, vector<double>(sizeMatrix));
	getID(15);
	inputAdditionalMatrix(tmp, sizeMatrix);
	for (int i = 0; i < sizeMatrix; i++)
		for (int j = 0; j < sizeMatrix; j++)
			vct[i][j] += tmp[i][j];
}

void subtractionMatrix(vector < vector <double> >& vct, int sizeMatrix)
{
	vector < vector <double> > tmp(sizeMatrix, vector<double>(sizeMatrix));
	getID(15);
	inputAdditionalMatrix(tmp, sizeMatrix);
	for (int i = 0; i < sizeMatrix; i++)
		for (int j = 0; j < sizeMatrix; j++)
			vct[i][j] -= tmp[i][j];
}

void multiplicationMatrix(vector < vector <double> >& vct, int sizeMatrix)
{
	vector < vector <double> > tmp1(sizeMatrix, vector<double>(sizeMatrix)), tmp2(sizeMatrix, vector<double>(sizeMatrix));
	getID(15);
	inputAdditionalMatrix(tmp2, sizeMatrix);
	for (int i = 0; i < sizeMatrix; i++)
		for (int j = 0; j < sizeMatrix; j++)
		{
			tmp1[i][j] = vct[i][j];
			vct[i][j] = 0;
		}

	for (int i = 0; i < sizeMatrix; i++)
		for (int j = 0; j < sizeMatrix; j++)
			for (int k = 0; k < sizeMatrix; k++)
				vct[i][j] += tmp1[i][k] * tmp2[k][j];
}

void divisionMatrix(vector < vector <double> >& vct, int sizeMatrix)
{
	vector < vector <double> > tmp1(sizeMatrix, vector<double>(sizeMatrix)), tmp2(sizeMatrix, vector<double>(sizeMatrix)), E(sizeMatrix, vector<double>(sizeMatrix));
	double dtmp;
	getID(15);
	inputAdditionalMatrix(tmp2, sizeMatrix);

	for (int i = 0; i < sizeMatrix; i++)
		for (int j = 0; j < sizeMatrix; j++)
		{
			tmp1[i][j] = vct[i][j];
			vct[i][j] = 0;
			if (i == j)
				E[i][j] = 1;
			else
				E[i][j] = 0;
		}

	for (int i = 0; i < sizeMatrix; i++)
	{
		dtmp = tmp2[i][i];

		for (int j = 0; j < sizeMatrix; j++)
		{
			tmp2[i][j] /= dtmp;
			E[i][j] /= dtmp;
		}

		for (int k = i + 1; k < sizeMatrix; k++)
		{
			dtmp = tmp2[k][i];

			for (int j = 0; j < sizeMatrix; j++)
			{
				tmp2[k][j] -= tmp2[i][j] * dtmp;
				E[k][j] -= E[i][j] * dtmp;
			}
		}
	}

	for (int i = sizeMatrix - 1; i > 0; i--)
	{
		for (int k = i - 1; k >= 0; k--)
		{
			dtmp = tmp2[k][i];

			for (int j = 0; j < sizeMatrix; j++)
			{
				tmp2[k][j] -= tmp2[i][j] * dtmp;
				E[k][j] -= E[i][j] * dtmp;
			}
		}
	}

	for (int i = 0; i < sizeMatrix; i++)
		for (int j = 0; j < sizeMatrix; j++)
			for (int k = 0; k < sizeMatrix; k++)
				vct[i][j] += tmp1[i][k] * tmp2[k][j];
}

void saveMatrix(vector < vector <double> > vct, int sizeMatrix)
{
	unsigned int start = clock(), finish;
	ofstream myfile;
	myfile.open("MyFile.csv", ios_base::out | ios_base::trunc);
	if (!myfile.is_open())
	{
		getID(16);
		return;
	}

	myfile << sizeMatrix;
	myfile << "\n";

	for (int i = 0; i < sizeMatrix; i++)
		for (int j = 0; j < sizeMatrix; j++)
			if (vct[i][j] != 0)
			{
				myfile << vct[i][j];
				myfile << ';';
				myfile << i;
				myfile << ';';
				myfile << j;
				myfile << "\n";
			}

	getID(19);
	memory(sizeof(vector<double>) * pow(sizeMatrix, 2), myfile.tellp());
	myfile.close();

	finish = clock();
	executionTime(finish - start);
}

bool loadMatrix(vector < vector <double> >& vct, int & sizeMatrix)
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
				getID(21);
				return false;
			}

			k = stoi(element);

			if (k != sizeMatrix)
			{
				vct.resize(k);
				for (int i = 0; i < k; ++i)
					vct[i].resize(k);
				
				if (k > sizeMatrix)
					for (int i = 0; i < sizeMatrix; i++)
						for (int j = 0; j < sizeMatrix; j++)
						{
							if (vct[i][j] == NULL)
								vct[i][j] = 0;
						}
				sizeMatrix = k;
			}

			while (getline(myfile, element, ';'))
			{
				getline(myfile, raw, ';');
				getline(myfile, column, '\n');
				iRaw = stoi(raw);
				iCol = stoi(column);
				dElement = stod(element);

				vct[iRaw][iCol] = dElement;
			}

			getID(20);
			myfile.close();
		}
		else
		{
			getID(22);
			return false;
		}
	}
	catch (invalid_argument)
	{
		getID(17);
		return false;
	}
	catch (out_of_range)
	{
		getID(18);
		return false;
	}

	finish = clock();
	executionTime(finish - start);

	return true;
}

void matrixMain()
{
	int sizeMatrix;
	getID(12);
	inputSize(sizeMatrix);
	vector < vector <double> > vct(sizeMatrix, vector<double>(sizeMatrix));
	char ch = '1';
	getID(13);
	inputMainMatrix(vct, sizeMatrix);

	do
	{
		getID(14);
		inputCharacter(ch);

		switch (ch)
		{
		case '1':
			additionMatrix(vct, sizeMatrix);
			break;
		case '2':
			subtractionMatrix(vct, sizeMatrix);
			break;
		case '3':
			multiplicationMatrix(vct, sizeMatrix);
			break;
		case '4':
			divisionMatrix(vct, sizeMatrix);
			break;
		case '5':
			saveMatrix(vct, sizeMatrix);
			break;
		case '6':
			if (!loadMatrix(vct, sizeMatrix))
				return;
			break;
		case '7':
			outputMatrix(vct, sizeMatrix);
			break;
		}
	} while (ch >= 49 && ch <= 55);
}