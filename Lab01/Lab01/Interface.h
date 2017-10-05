#pragma once
#include <iostream>

using namespace std;

void GetID(int id)
{
	switch (id)
	{
	case 1:
		cout << "Введiть '1' для роботи з калькулятором,\n'2' для роботи з матрицями,\n'0' для завершення програми.\n";
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
		cout << "Введiть кiлькiсть рядкiв та стовпцiв: ";
		break;
	case 13:
		cout << "Введiть елементи матрицi:\n";
		break;
	case 14:
		cout << "\n\nВведiть '1' для додавання матриць,\n'2' для вiднiмання матриць,\n'3' для множення матриць,";
		cout << "\n'4' для дiлення матриць,\n'5' для зберiгання матрицi\n'6' для зчитування матрицi,\n'7' для виводу матрицi";
		cout << "\n'0' для виходу\n";
		break;
	case 15:
		cout << "Введiть елементи другої матрицi:\n";
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
	default:
		break;
	}
}

void ForMatrix(char ch, int i, int j)
{
	cout << ch << "[" << i << ", " << j << "] = ";
}