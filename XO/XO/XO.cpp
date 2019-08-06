#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <ctime>

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
		bool complete = false;

		while (!complete)
		{
			switch (_getch()) // возвращает нажатую клавишу
			{
			case '1':
				if (arr[0][0] == ' ')
				{
					arr[0][0] = 'X';
					complete = true;
				}
				break;
			case '2':
				if (arr[0][1] == ' ')
				{
					arr[0][1] = 'X';
					complete = true;
				}
				break;
			case '3':
				if (arr[0][2] == ' ')
				{
					arr[0][2] = 'X';
					complete = true;
				}
				break;
			case '4':
				if (arr[1][0] == ' ')
				{
					arr[1][0] = 'X';
					complete = true;
				}
				break;
			case '5':
				if (arr[1][1] == ' ')
				{
					arr[1][1] = 'X';
					complete = true;
				}
				break;
			case '6':
				if (arr[1][2] == ' ')
				{
					arr[1][2] = 'X';
					complete = true;
				}
				break;
			case '7':
				if (arr[2][0] == ' ')
				{
					arr[2][0] = 'X';
					complete = true;
				}
				break;
			case '8':
				if (arr[2][1] == ' ')
				{
					arr[2][1] = 'X';
					complete = true;
				}
				break;
			case '9':
				if (arr[2][2] == ' ')
				{
					arr[2][2] = 'X';
					complete = true;
				}
				break;
			default:
				break;
			}
		}
	}
};

class Logic : public Data // логика
{
public:
	void move() // делает рандомный ход
	{
		srand(time(NULL));
		int i, j;
		bool complete = false;
		while (!complete)
		{
			i = rand() % 3;
			j = rand() % 3;

			if (arr[i][j] == ' ')
			{
				arr[i][j] = 'O';
				complete = true;
			}
		}
	}

	bool full()
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] == ' ')
					return false;
			}
		return true;
	}

	bool win()
	{
		bool complete = false;
		if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][0] != ' ')
			complete = true;
		if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][0] != ' ')
			complete = true;
		if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][0] != ' ')
			complete = true;

		if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[0][0] != ' ')
			complete = true;
		if (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[0][1] != ' ')
			complete = true;
		if (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[0][2] != ' ')
			complete = true;

		if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
			complete = true;
		if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ')
			complete = true;

		return complete;
	}

	int defense()
	{
		int bufer_i = -1, bufer_j = -1; // для хранения соседнего элемента
		for (int i = 0; i < 3; i++) // ищем Х
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] == 'X')
				{
					if (i == 1 && j == 1) // если он в центре то ищем "Соседа", пропуская центр
					{
						center:
						for (int q = 0; q < 3; q++)
						{
							for (int p = 0; p < 3; p++)
							{
								if (!(q == 1 && p == 1) && arr[q][p] == 'X')
								{
									bufer_i = q; //запоминаем индексы "Соседа"
									bufer_j = p;

									bufer_i = 1 - bufer_i; //находим "шаг"
									bufer_j = 1 - bufer_j;
									bufer_i = 1 + bufer_i; //находим индексы "недостоющей до тройки" ячейки
									bufer_j = 1 + bufer_j;
									if (arr[bufer_i][bufer_j] == ' ')//если эта ячейка пустая, то запоняем
									{
										arr[bufer_i][bufer_j] = 'O';
										return 1;
									}
								}
							}
						}
					}

					if (arr[1][1] == 'X') //если не в центре, но есть центральный элемент, по переводим на ситуацию "центр"
						goto center;

					srand(time(NULL)); //если не в рассматриваемой ситуации, то рандомно
					bool complete = false;
					while (!complete)
					{
						bufer_i = rand() % 3;
						bufer_j = rand() % 3;

						if (arr[bufer_i][bufer_j] == ' ')
						{
							arr[bufer_i][bufer_j] = 'O';
							complete = true;
						}
					}
					return 1;
				}
			}
		}
	}
};


class Draw //рисовалка
{
public:
	Logic logic;

	void map() // выводит все на экран
	{
		system("cls");
		cout << logic.get_info(0, 0) << "|" << logic.get_info(0, 1) << "|" << logic.get_info(0, 2) << endl;
		cout << "—————" << endl;
		cout << logic.get_info(1, 0) << "|" << logic.get_info(1, 1) << "|" << logic.get_info(1, 2) << endl;
		cout << "—————" << endl;
		cout << logic.get_info(2, 0) << "|" << logic.get_info(2, 1) << "|" << logic.get_info(2, 2) << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Draw game;
	game.map();
	while (!game.logic.win()) // пока "не победа"
	{
		game.logic.Enter();
		game.map();
		Sleep(500);
		if (!game.logic.full() && !game.logic.win())
		{
			game.logic.defense();
			//game.logic.move();
			game.map();
		}
	}
};