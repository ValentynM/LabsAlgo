#pragma once
#include <iostream>

using namespace std;

class UInterface
{
public:
	static void getID (int id)
	{
		switch (id)
		{
		case 1:
			cout << "\n����i�� '1' ��� �����������, '0' ��� ���������� ��������.\n";
			break;
		case 2:
			cout << "\n���� �����������!\n";
			break;
		case 3:
			cout << "\n����� �������� � �����!\n";
			break;
		case 4:
			cout << "\n����i�� ����� ���i���: ";
			break;
		case 5:
			cout << "\n����i�� �����i� ��� ������� ���i��� 2 � ���i��� 1: ";
			break;
		case 6:
			cout << "\n���i��� 2 �����!\n\n";
			break;
		case 7:
			cout << "\n����������� �������� �����i� ��� ������������ ���i���!\n";
			break;
		case 8:
			cout << "\n���� �� �i������!\n";
			break;
		case 9:
			cout << "\n���i��� ��������� ��������!\n";
			break;
		case 10:
			cout << "\n���i� �� ��� ���i���!\n";
			break;
		default:
			break;
		}
	}

	static void inputCharacter(char& ch)
	{
		cin >> ch;
		cin.ignore();
	}

	static void getString(string& str)
	{
		getline(cin, str);
	}

	static void getNumber(int& Number)
	{
		cin >> Number;
	}
};
