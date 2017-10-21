#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Interface
{
public:
	 void getID(int id)
	{
		switch (id)
		{
		case 1:
			cout << "Введiть '1' для роботи з калькулятором,\n'2' для роботи з матрицями,";
			cout << "\n'0' для завершення програми.\n";
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
			cout << "\nВведiть розмiр матрицi: ";
			break;
		case 13:
			cout << "Введiть елементи матрицi:\n";
			break;
		case 14:
			cout << "\n\nВведiть '1' для додавання матриць";
			cout << "\n'2' для вiднiмання матриць\n'3' для множення матриць";
			cout << "\n'4' для дiлення матриць\n'5' для зберiгання матрицi\n'6' для зчитування матрицi";
			cout << "\n'7' для виводу матрицi\n'0' для виходу\n";
			break;
		case 15:
			cout << "\nВведiть елементи другої матрицi:\n";
			break;
		case 16:
			cout << "Файл не може бути вiдкритим або створеним\n";
			break;
		case 17:
			cout << "Неможливо виконати приведення типiв!\n\n";
			break;
		case 18:
			cout << "Вихiд за границю дiапазона типу даних!\n\n";
			break;
		case 19:
			cout << "\nФайл збережено!\n";
			break;
		case 20:
			cout << "\nФайл зчитано!\n";
			break;
		case 21:
			cout << "\nЗчитування неможливе, оскiльки файл пустий!\n\n";
			break;
		case 22:
			cout << "\nПомилка вiдкривання файла!\n\n";
			break;
		case 23:
			cout << "\nПеред дужкою немає оператора або пiсля вiдкритої дужки немає операнда!\n\n";
			break;
		case 24:
			cout << "\nПеред закритою дужкою не може бути оператор!\n\n";
			break;
		case 25:
			cout << "\nВираз не може починатись закритою дужкою!\n\n";
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
		cout << result << endl << endl;
	}

	static void inputSize(int& size)
	{
		cin >> size;
	}

	static void inputElement(double& element, int line, int column)
	{
		cout << "Element [" << line << ", " << column << "] = ";
		cin >> element;

	}

	static void outputElement(double element, int line, int column)
	{
		cout << "Element [" << line << ", " << column << "] = ";
		cout << element << endl;
	}

	static void inputCharacter(char& character)
	{
		cin >> character;
		cin.ignore();
	}

	static void memory(int memory1, int memory2)
	{
		cout << "Пам'ять, яку займає вектор - " << memory1 << " байт(а)." << endl;
		cout << "Пам'ять, яку займає файл - " << memory2 << " байт(а)." << endl;
	}

	static void executionTime(unsigned int time)
	{
		cout << "Час виконання функцiї: " << time << " мс" << endl;
	}
};