#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class UInterface
{
public:
	void getID(int id)
	{
		switch (id)
		{
		case 1:
			cout << "����i�� '1' ��� ���������� ����,\n        '2' ��� ���������� �������,";
			cout << "\n        '0' ��� ���������� ��������.\n";
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
			cout << "��������� �������� ���������� ���i�!\n\n";
			break;
		case 13:
			cout << "���i� �� ������� �i������� ���� �����!\n\n";
			break;
		case 14:
			cout << "\n����� ������ ���� ��������� ��� �i��� �i������ ����� ���� ��������!\n\n";
			break;
		case 15:
			cout << "\n����� �������� ������ �� ���� ���� ��������!\n\n";
			break;
		case 16:
			cout << "\n����� �� ���� ���������� �������� ������!\n\n";
			break;
		case 17:
			cout << "����i�� �i���i��� ���������: ";
				break;
		case 18:
			cout << "�i���i��� ��������� ������� ���� �i����� �� 0!" << endl;
			break;
		case 19:
			cout << "������� �������� ���������!" << endl;
			break;
		default:
			break;
		}
	}

	static void inputString(string& str)
	{
		getline(cin, str);
	}

	static void getResult(double result)
	{
		cout << result << endl;
	}

	static void inputInt(int& n)
	{
		cin >> n;
	}


	static void inputCharacter(char& character)
	{
		cin >> character;
		cin.ignore();
	}

};
