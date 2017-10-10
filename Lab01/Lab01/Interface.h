#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void GetID(int id)
{
	switch (id)
	{
	case 1:
		cout << "����i�� '1' ��� ������ � �������������,\n'2' ��� ������ � ���������,\n'0' ��� ���������� ��������.\n";
		break;
	case 2:
		cout << "����i�� �����: ";
		break;
	case 3:
		cout << "����� ������� ���i��������� �������� '='!\n\n";
		break;
	case 4:
		cout << "�i���i��� ��������i� �� �������i� �� ��i��������!\n\n";;
		break;
	case 5:
		cout << "������������ ������!\n\n";
		break;
	case 6:
		cout << "�i���i��� �i������� ����� �� �i����i�� �i������i ��������!\n\n";
		break;
	case 7:
		cout << "�� ��i ����� � ��������!\n\n";
		break;
	case 8:
		cout << "���������: ";
		break;
	case 9:
		cout << "����� �� ������� ����������/���i��������� ����������!\n\n";
		break;
	case 10:
		cout << "���� '=' � ������������� �i��i\n\n";
		break;
	case 11:
		cout << "����� ����i!\n\n";
		break;
	case 12:
		cout << "\n����i�� ����i� ������i: ";
		break;
	case 13:
		cout << "����i�� �������� ������i:\n";
		break;
	case 14:
		cout << "\n\n����i�� '1' ��� ��������� �������";
		cout << "\n'2' ��� �i��i����� �������\n'3' ��� �������� �������";
		cout << "\n'4' ��� �i����� �������\n'5' ��� ����i����� ������i\n'6' ��� ���������� ������i";
		cout << "\n'7' ��� ������ ������i\n'0' ��� ������\n";
		break;
	case 15:
		cout << "\n����i�� �������� ����� ������i:\n";
		break;
	case 16:
		cout << "���� �� ���� ���� �i������� ��� ���������\n";
		break;
	case 17:
		cout << "��������� �������� ���������� ���i�!\n\n";
		break;
	case 18:
		cout << "���i� �� ������� �i������� ���� �����!\n\n";
		break;
	case 19:
		cout << "\n���� ���������!\n";
		break;
	case 20:
		cout << "\n���� �������!\n";
		break;
	case 21:
		cout << "\n���������� ���������, ���i���� ���� ������!\n\n";
		break;
	case 22:
		cout << "\n������� �i��������� �����!\n\n";
		break;
	default:
		break;
	}
}

void InputString(string & str)
{
	getline(cin, str);
}

void GetResult(double result)
{
	cout << result << endl << endl;
}

void InputSize(int & n)
{
	cin >> n;
}

void InputMatrixElement (double & element,int i, int j)
{
	cout << "Element [" << i << ", " << j << "] = ";
	cin >> element;

}

void OutputMatrixElement(double element, int i, int j)
{
		cout << "Element [" << i << ", " << j << "] = ";
		cout << element << endl;
}

void InputCharacter(char & ch)
{
	cin >> ch;
	cin.ignore();
}

void Memory(int memory1, int memory2)
{
	cout << "���'���, ��� ����� ������ - " << memory1 << " ����(�)." << endl;
	cout << "���'���, ��� ����� ���� - " << memory2 << " ����(�)." << endl;
}