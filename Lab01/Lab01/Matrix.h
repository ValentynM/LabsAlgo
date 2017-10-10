#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Interface.h"

using namespace std;

void GetID(int id);
void InputSize(int & n);
void InputMatrixElement(double & element, int i, int j);
void OutputMatrixElement(double element, int i, int j);
void InputCharacter(char & ch);
void Memory(int memory1, int memory2);

void InputMainMatrix(vector < vector <double> > & vct, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (j > i)
				 InputMatrixElement(vct[i][j], i, j);
			else
			{
				vct[i][j] = 0;
				OutputMatrixElement(vct[i][j], i, j);
			}
}

void InputAdditionalMatrix(vector < vector <double> > & tmp, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			InputMatrixElement(tmp[i][j], i, j);
}

void OutputMatrix(vector < vector <double> > vct, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			OutputMatrixElement(vct[i][j], i, j);
}

void AdditionMatrix(vector < vector <double> > & vct, int n)
{
	vector < vector <double> > tmp(n, vector<double>(n));
	GetID(15);
	InputAdditionalMatrix(tmp, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			vct[i][j] += tmp[i][j];
}

void SubtractionMatrix(vector < vector <double> > & vct, int n)
{
	vector < vector <double> > tmp(n, vector<double>(n));
	GetID(15);
	InputAdditionalMatrix(tmp, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			vct[i][j] -= tmp[i][j];
}

void MultiplicationMatrix(vector < vector <double> > & vct, int n)
{
	vector < vector <double> > tmp1(n, vector<double>(n)), tmp2(n, vector<double>(n));
	GetID(15);
	InputAdditionalMatrix(tmp2, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			tmp1[i][j] = vct[i][j];
			vct[i][j] = 0;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				vct[i][j] += tmp1[i][k] * tmp2[k][j];
}

void DivisionMatrix(vector < vector <double> > & vct, int n)
{
	vector < vector <double> > tmp1(n, vector<double>(n)), tmp2(n, vector<double>(n)), E(n, vector<double>(n));
	double dtmp;
	GetID(15);
	InputAdditionalMatrix(tmp2, n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			tmp1[i][j] = vct[i][j];
			vct[i][j] = 0;
			if (i == j)
				E[i][j] = 1;
			else
				E[i][j] = 0;
		}

	for (int i = 0; i < n; i++)
	{
		dtmp = tmp2[i][i];

		for (int j = 0; j < n; j++)
		{
			tmp2[i][j] /= dtmp;
			E[i][j] /= dtmp;
		}

		for (int k = i + 1; k < n; k++)
		{
			dtmp = tmp2[k][i];

			for (int j = 0; j < n; j++)
			{
				tmp2[k][j] -= tmp2[i][j] * dtmp;
				E[k][j] -= E[i][j] * dtmp;
			}
		}
	}

	for (int i = n - 1; i > 0; i--)
	{
		for (int k = i - 1; k >= 0; k--)
		{
			dtmp = tmp2[k][i];

			for (int j = 0; j < n; j++)
			{
				tmp2[k][j] -= tmp2[i][j] * dtmp;
				E[k][j] -= E[i][j] * dtmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				vct[i][j] += tmp1[i][k] * tmp2[k][j];
}

void SaveMatrix(vector < vector <double> > vct, int n)
{
	ofstream myfile;
	myfile.open("MyFile.csv", ios_base::out | ios_base::trunc);
	if (!myfile.is_open())
	{
		GetID(16);
		return;
	}

	myfile << n;
	myfile << "\n";

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (vct[i][j] != 0)
			{
				myfile << vct[i][j];
				myfile << ';';
				myfile << i;
				myfile << ';';
				myfile << j;
				myfile << "\n";
			}

	GetID(19);
	Memory(sizeof(vct) * pow(n, 2), myfile.tellp());

	myfile.close();
}

bool LoadMatrix(vector < vector <double> > & vct, int & n)
{
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
				GetID(21);
				return false;
			}

			k = stoi(element);

			if (k != n)
			{
				vct.resize(k);
				for (int i = 0; i < k; ++i)
					vct[i].resize(k);
				
				if (k > n)
					for (int i = 0; i < n; i++)
						for (int j = 0; j < n; j++)
						{
							if (vct[i][j] == NULL)
								vct[i][j] = 0;
						}
				n = k;
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

			GetID(20);
			myfile.close();
		}
		else
		{
			GetID(22);
			return false;
		}
	}
	catch (invalid_argument)
	{
		GetID(17);
		return false;
	}
	catch (out_of_range)
	{
		GetID(18);
		return false;
	}

	return true;
}

void MatrixMain()
{
	int n;
	GetID(12);
	InputSize(n);
	vector < vector <double> > vct(n, vector<double>(n));
	char ch = '1';
	GetID(13);
	InputMainMatrix(vct, n);

	do
	{
		GetID(14);
		InputCharacter(ch);

		switch (ch)
		{
		case '1':
			AdditionMatrix(vct, n);
			break;
		case '2':
			SubtractionMatrix(vct, n);
			break;
		case '3':
			MultiplicationMatrix(vct, n);
			break;
		case '4':
			DivisionMatrix(vct, n);
			break;
		case '5':
			SaveMatrix(vct, n);
			break;
		case '6':
			if (!LoadMatrix(vct, n))
				return;
			break;
		case '7':
			OutputMatrix(vct, n);
			break;
		}
	} while (ch >= 49 && ch <= 55);
}