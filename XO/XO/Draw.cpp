#include "pch.h"
#include "Draw.h"

Draw::Draw()
{
	position.X = 0;
	position.Y = 0;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Draw::color()
{
	system("color 1B");
}

void Draw::set_cursor(int x, int y)
{
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(hConsole, position);
}

void Draw::rules()
{
	set_cursor(9, 5);
	cout << "Выбирайте поля цифрами на клавиатуре в соответсвии со схемой";
	set_cursor(37, 8);
	cout << "1|2|3";
	set_cursor(37, 9);
	cout << "—————";
	set_cursor(37, 10);
	cout << "4|5|6";
	set_cursor(37, 11);
	cout << "—————";
	set_cursor(37, 12);
	cout << "7|8|9";
	set_cursor(22, 15);

	system("pause");
}

void Draw::map() // выводит все на экран
{
	system("cls");
	set_cursor(37, 8);
	cout << logic.get_info(0, 0) << "|" << logic.get_info(0, 1) << "|" << logic.get_info(0, 2);
	set_cursor(37, 9);
	cout << "—————";
	set_cursor(37, 10);
	cout << logic.get_info(1, 0) << "|" << logic.get_info(1, 1) << "|" << logic.get_info(1, 2);
	set_cursor(37, 11);
	cout << "—————";
	set_cursor(37, 12);
	cout << logic.get_info(2, 0) << "|" << logic.get_info(2, 1) << "|" << logic.get_info(2, 2);
	set_cursor(0, 0);
}

void Draw::final_map() // выводит все на экран
{
	system("cls");
	set_cursor(37, 4);
	cout << logic.get_info(0, 0) << "|" << logic.get_info(0, 1) << "|" << logic.get_info(0, 2);
	set_cursor(37, 5);
	cout << "—————";
	set_cursor(37, 6);
	cout << logic.get_info(1, 0) << "|" << logic.get_info(1, 1) << "|" << logic.get_info(1, 2);
	set_cursor(37, 7);
	cout << "—————";
	set_cursor(37, 8);
	cout << logic.get_info(2, 0) << "|" << logic.get_info(2, 1) << "|" << logic.get_info(2, 2);
}

int Draw::start_menu()
{
	string choice;
	bool error;

	system("cls");

	do
	{
		error = false;

		set_cursor(27, 10);
		cout << "Вы можете:\n";
		set_cursor(27, 11);
		cout << "1. Играть с компьютером\n";
		set_cursor(27, 12);
		cout << "2. Играть вдвоем\n";
		set_cursor(27, 13);
		cout << "Выберете желаемый вариант: ";
		cin >> choice;

		if (choice == "1")
			return 1;
		else if (choice == "2")
			return 2;

		error = true;

		system("cls");

		set_cursor(30, 7);
		cout << "Ошбика при выборе!\n" << endl;

	} while (error);
}

int Draw::move_menu()
{
	string choice;
	bool error;

	system("cls");
	do
	{
		error = false;

		set_cursor(28, 8);
		cout << "Крестики ходят первыми!";
		set_cursor(27, 11);
		cout << "Вы можете:";
		set_cursor(27, 12);
		cout << "1. Играть крестиками";
		set_cursor(27, 13);
		cout << "2. Играть ноликами";
		set_cursor(27, 14);
		cout << "Выберете желаемый вариант: ";
		cin >> choice;

		if (choice == "1")
			return 1;
		else if (choice == "2")
			return 2;

		error = true;

		system("cls");

		set_cursor(30, 17);
		cout << "Ошбика при выборе!\n" << endl;

	} while (error);
}

int Draw::final_menu()
{
	string choice;
	bool error;

	do
	{
		error = false;
		set_cursor(32, 14);
		cout << "Вы можете:";
		set_cursor(32, 15);
		cout << "1. Играть еще раз";
		set_cursor(32, 16);
		cout << "2. Перейти в меню";
		set_cursor(32, 17);
		cout << "3. Завершить игру";
		set_cursor(28, 19);
		cout << "Выберете желаемый вариант: ";
		cin >> choice;

		if (choice == "1")
			return 1;
		else if (choice == "2")
			return 2;
		else if (choice == "3")
			return 3;

		error = true;

		system("cls");

		set_cursor(31, 9);
		cout << "Ошбика при выборе!\n" << endl;

	} while (error);
}

void Draw::result_info(char* result)
{
	final_map();
	switch (*result)
	{
	case 'N':
	{
		set_cursor(37, 11);
		cout << "Ничья!" << endl;
		break;
	}
	case 'X':
	{
		set_cursor(30, 11);
		cout << "Победили крестики - X!" << endl;
		break;
	}
	case 'O':
	{
		set_cursor(31, 11);
		cout << "Победили нолики - O!" << endl;
		break;
	}
	}
}