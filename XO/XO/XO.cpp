#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

class Data //хранит инфо о состянии клеточек
{
protected:
	char arr[3][3];
public:
	Data() // конструктор
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				arr[i][j] = ' ';
	}

	char get_info(int i, int j) // возвращает состояние клетки
	{
		return arr[i][j];
	}

	void Enter() // фунция для ввода
	{
		if (_kbhit()) // возвращает true если нажали клавишу
		{
			switch (_getch()) // возвращает нажатую клавишу
			{
			case '1':
				arr[0][0] = 'X';
				break;
			case '2':
				arr[0][1] = 'X';
				break;
			case '3':
				arr[0][2] = 'X';
				break;
			case '4':
				arr[1][0] = 'X';
				break;
			case '5':
				arr[1][1] = 'X';
				break;
			case '6':
				arr[1][2] = 'X';
				break;
			case '7':
				arr[2][0] = 'X';
				break;
			case '8':
				arr[2][1] = 'X';
				break;
			case '9':
				arr[2][2] = 'X';
				break;
			default:
				break;
			}
		}
	}
};

class Logic // логика
{
public:

};


class Draw //рисовалка
{
public:
	Logic logic;
	Data data;

	void start() // выводит все на экран
	{
		system("cls");
		cout << data.get_info(0,0)<< "|" << data.get_info(0, 1) << "|" << data.get_info(0, 2) << endl;
		cout << "—————" << endl;
		cout << data.get_info(1, 0) << "|" << data.get_info(1, 1) << "|" << data.get_info(1, 2) << endl;
		cout << "—————" << endl;
		cout << data.get_info(2, 0) << "|" << data.get_info(2, 1) << "|" << data.get_info(2, 2) << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Draw game;
	while (true)
	{
		game.start();
		game.data.Enter();
	}
};