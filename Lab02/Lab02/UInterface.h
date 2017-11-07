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
			cout << "\nВведiть '1' для продовження, '0' для завершення програми.\n";
			break;
		case 2:
			cout << "\nФайл згенеровано!\n";
			break;
		case 3:
			cout << "\nРядок зчитаний з файлу!\n";
			break;
		case 4:
			cout << "\nВведiть другу стрiчку: ";
			break;
		case 5:
			cout << "\nВведiть позицiю для вставки стрiчки 2 в стрiчку 1: ";
			break;
		case 6:
			cout << "\nСтрiчка 2 пуста!\n\n";
			break;
		case 7:
			cout << "\nНедопустиме значення позицiї для встановлення стрiчки!\n";
			break;
		case 8:
			cout << "\nФайл не вiдкрито!\n";
			break;
		case 9:
			cout << "\nУспiшне виконання програми!\n";
			break;
		case 10:
			cout << "\nВихiд за межі стрiчки!\n";
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
