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
			cout << "Введiть '1' для обчислення суми,\n        '2' для обчислення добутку,";
			cout << "\n        '0' для завершення програми.\n";
			break;
		case 2:
			cout << "Введiть вираз: ";
			break;
		case 3:
			cout << "Вираз повинен закiнчуватися символом '='!\n\n";
			break;
		case 4:
			cout << "Кiлькiсть операторiв та операндiв не спiвпадають!\n\n";;
			break;
		case 5:
			cout << "Недопустимий символ!\n\n";
			break;
		case 6:
			cout << "Кiлькiсть вiдкритих дужок не вiдповiдає кiлькостi закритих!\n\n";
			break;
		case 7:
			cout << "Не всi числа є простими!\n\n";
			break;
		case 8:
			cout << "Результат: ";
			break;
		case 9:
			cout << "Вираз не повинен починатися/закiнчуватися оператором!\n\n";
			break;
		case 10:
			cout << "Знак '=' в недопустимому мiсцi\n\n";
			break;
		case 11:
			cout << "Дужки пустi!\n\n";
			break;
		case 12:
			cout << "Неможливо виконати приведення типiв!\n\n";
			break;
		case 13:
			cout << "Вихiд за границю дiапазона типу даних!\n\n";
			break;
		case 14:
			cout << "\nПеред дужкою немає оператора або пiсля вiдкритої дужки немає операнда!\n\n";
			break;
		case 15:
			cout << "\nПеред закритою дужкою не може бути оператор!\n\n";
			break;
		case 16:
			cout << "\nВираз не може починатись закритою дужкою!\n\n";
			break;
		case 17:
			cout << "Введiть кiлькiсть повторень: ";
				break;
		case 18:
			cout << "Кiлькiсть повторень повинна бути бiльшою за 0!" << endl;
			break;
		case 19:
			cout << "Помилка введення оператора!" << endl;
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
