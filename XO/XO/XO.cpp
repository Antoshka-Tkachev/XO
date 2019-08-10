#include "pch.h"
#include <iostream>
#include <string>
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

	void zeroing()
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				arr[i][j] = ' ';
	}

	void Enter_X() // фунция для ввода
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

	void Enter_O() // фунция для ввода
	{
		bool complete = false;

		while (!complete)
		{
			switch (_getch()) // возвращает нажатую клавишу
			{
			case '1':
				if (arr[0][0] == ' ')
				{
					arr[0][0] = 'O';
					complete = true;
				}
				break;
			case '2':
				if (arr[0][1] == ' ')
				{
					arr[0][1] = 'O';
					complete = true;
				}
				break;
			case '3':
				if (arr[0][2] == ' ')
				{
					arr[0][2] = 'O';
					complete = true;
				}
				break;
			case '4':
				if (arr[1][0] == ' ')
				{
					arr[1][0] = 'O';
					complete = true;
				}
				break;
			case '5':
				if (arr[1][1] == ' ')
				{
					arr[1][1] = 'O';
					complete = true;
				}
				break;
			case '6':
				if (arr[1][2] == ' ')
				{
					arr[1][2] = 'O';
					complete = true;
				}
				break;
			case '7':
				if (arr[2][0] == ' ')
				{
					arr[2][0] = 'O';
					complete = true;
				}
				break;
			case '8':
				if (arr[2][1] == ' ')
				{
					arr[2][1] = 'O';
					complete = true;
				}
				break;
			case '9':
				if (arr[2][2] == ' ')
				{
					arr[2][2] = 'O';
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

	void move_O() // делает рандомный ход ноликом
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

	void move_X() // делает рандомный ход крестиком
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
				arr[i][j] = 'X';
				complete = true;
			}
		}
	}

	bool full(char *result)
	{

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (arr[i][j] == ' ')
					return false;
		*result = 'N';

		return true;
	}

	bool win(char *result)
	{
		bool complete = false;

		if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][0] != ' ')
		{
			complete = true;
			*result = arr[0][0];
		}
		if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][0] != ' ')
		{
			complete = true;
			*result = arr[1][0];
		}
		if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][0] != ' ')
		{
			complete = true;
			*result = arr[2][0];
		}
		if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[0][0] != ' ')
		{
			complete = true;
			*result = arr[0][0];
		}
		if (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[0][1] != ' ')
		{
			complete = true;
			*result = arr[0][1];
		}
		if (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[0][2] != ' ')
		{
			complete = true;
			*result = arr[0][2];
		}

		if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
		{
			complete = true;
			*result = arr[0][0];
		}
		if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ')
		{
			complete = true;
			*result = arr[0][2];
		}
		
		return complete;
	}

	int attack_O()
	{
		int bufer_i = -1, bufer_j = -1; // для хранения соседнего элемента
		for (int i = 0; i < 3; i++) // ищем O
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] == 'O')
				{

					if (!(i == 1 && j == 1) && arr[1][1] == 'O') //если не в центре, но есть центральный элемент, по переводим на ситуацию "центр"
						goto center;

					if (i == 1 && j == 1) // если он в центре то ищем "Соседа", пропуская центр
					{
					center:
						for (int q = 0; q < 3; q++)
						{
							for (int p = 0; p < 3; p++)
							{
								if (!(q == 1 && p == 1) && arr[q][p] == 'O')
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

					if (i != 1 && j != 1 && arr[i][j] == 'O') //если Х в углу, то ищем пару
					{
						int count = 0; //cчетчик кол-ва угловых элементов

						for (int q = 0; q < 3; q += 2) //считаем кол-во угловых элементов
							for (int p = 0; p < 3; p += 2)
								if (arr[q][p] == 'O')
									count++;

						if (count > 1) // если элементов 2 и больше, то ищем пары
						{
							if ((arr[0][0] == 'O' && arr[2][2] == 'O') || (arr[0][2] == 'O' && arr[2][0] == 'O')) //если пара диагональна
							{
								if (arr[1][1] == ' ') // и центр свободен, то ставим в центр
								{
									arr[1][1] = 'O';
									return 1;
								}
							}

							//4 варианта соседих углов
							// если есть пара и элемент между ними свободен, то делаем этот ход
							if (arr[0][0] == 'O' && arr[0][2] == 'O' && arr[0][1] == ' ')
							{
								arr[0][1] = 'O';
								return 1;
							}
							if (arr[0][0] == 'O' && arr[2][0] == 'O' && arr[1][0] == ' ')
							{
								arr[1][0] = 'O';
								return 1;
							}
							if (arr[2][0] == 'O' && arr[2][2] == 'O' && arr[2][1] == ' ')
							{
								arr[2][1] = 'O';
								return 1;
							}
							if (arr[0][2] == 'O' && arr[2][2] == 'O' && arr[1][2] == ' ')
							{
								arr[1][2] = 'O';
								return 1;
							}
						}
					}

					if ((arr[1][0] == 'O' && arr[1][2] == 'O') || (arr[0][1] == 'O' && arr[2][1] == 'O')) //если пара противоположная
					{
						if (arr[1][1] == ' ') // и центр свободен, то ставим в центр
						{
							arr[1][1] = 'O';
							return 1;
						}
					}

					//8 ситуаций на соседние элементы
					if (arr[0][0] == 'O' && arr[0][1] == 'O' &&  arr[0][2] == ' ')
					{
						arr[0][2] = 'O';
						return 1;
					}
					if (arr[0][1] == 'O' && arr[0][2] == 'O' &&  arr[0][0] == ' ')
					{
						arr[0][0] = 'O';
						return 1;
					}
					if (arr[0][2] == 'O' && arr[1][2] == 'O' &&  arr[2][2] == ' ')
					{
						arr[2][2] = 'O';
						return 1;
					}
					if (arr[1][2] == 'O' && arr[2][2] == 'O' &&  arr[0][2] == ' ')
					{
						arr[0][2] = 'O';
						return 1;
					}
					if (arr[2][2] == 'O' && arr[2][1] == 'O' &&  arr[2][0] == ' ')
					{
						arr[2][0] = 'O';
						return 1;
					}
					if (arr[2][0] == 'O' && arr[2][1] == 'O' &&  arr[2][2] == ' ')
					{
						arr[2][2] = 'O';
						return 1;
					}
					if (arr[0][0] == 'O' && arr[1][0] == 'O' &&  arr[2][0] == ' ')
					{
						arr[2][0] = 'O';
						return 1;
					}
					if (arr[1][0] == 'O' && arr[2][0] == 'O' &&  arr[0][0] == ' ')
					{
						arr[0][0] = 'O';
						return 1;
					}

					return 2;
				}
			}
		}
		return 2;
	}

	int defense_O()
	{
		int bufer_i = -1, bufer_j = -1; // для хранения соседнего элемента
		for (int i = 0; i < 3; i++) // ищем Х
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] == 'X')
				{

					if (!(i == 1 && j == 1) && arr[1][1] == 'X') //если не в центре, но есть центральный элемент, по переводим на ситуацию "центр"
						goto center;

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

					if (i != 1 && j != 1 && arr[i][j] == 'X') //если Х в углу, то ищем пару
					{
						int count = 0; //cчетчик кол-ва угловых элементов

						for (int q = 0; q < 3; q += 2) //считаем кол-во угловых элементов
							for (int p = 0; p < 3; p += 2)
								if (arr[q][p] == 'X')
									count++;

						if (count > 1) // если элементов 2 и больше, то ищем пары
						{
							if ((arr[0][0] == 'X' && arr[2][2] == 'X') || (arr[0][2] == 'X' && arr[2][0] == 'X')) //если пара диагональна
							{
								if (arr[1][1] == ' ') // и центр свободен, то ставим в центр
								{
									arr[1][1] = 'O';
									return 1;
								}
							}

							//4 варианта соседих углов
							// если есть пара и элемент между ними свободен, то делаем этот ход
							if (arr[0][0] == 'X' && arr[0][2] == 'X' && arr[0][1] == ' ')
							{
								arr[0][1] = 'O';
								return 1;
							}
							if (arr[0][0] == 'X' && arr[2][0] == 'X' && arr[1][0] == ' ')
							{
								arr[1][0] = 'O';
								return 1;
							}
							if (arr[2][0] == 'X' && arr[2][2] == 'X' && arr[2][1] == ' ')
							{
								arr[2][1] = 'O';
								return 1;
							}
							if (arr[0][2] == 'X' && arr[2][2] == 'X' && arr[1][2] == ' ')
							{
								arr[1][2] = 'O';
								return 1;
							}
						}
					}

					if ((arr[1][0] == 'X' && arr[1][2] == 'X') || (arr[0][1] == 'X' && arr[2][1] == 'X')) //если пара противоположная
					{
						if (arr[1][1] == ' ') // и центр свободен, то ставим в центр
						{
							arr[1][1] = 'O';
							return 1;
						}
					}

					//8 ситуаций на соседние элементы
					if (arr[0][0] == 'X' && arr[0][1] == 'X' &&  arr[0][2] == ' ')
					{
						arr[0][2] = 'O';
						return 1;
					}
					if (arr[0][1] == 'X' && arr[0][2] == 'X' &&  arr[0][0] == ' ')
					{
						arr[0][0] = 'O';
						return 1;
					}
					if (arr[0][2] == 'X' && arr[1][2] == 'X' &&  arr[2][2] == ' ')
					{
						arr[2][2] = 'O';
						return 1;
					}
					if (arr[1][2] == 'X' && arr[2][2] == 'X' &&  arr[0][2] == ' ')
					{
						arr[0][2] = 'O';
						return 1;
					}
					if (arr[2][2] == 'X' && arr[2][1] == 'X' &&  arr[2][0] == ' ')
					{
						arr[2][0] = 'O';
						return 1;
					}
					if (arr[2][0] == 'X' && arr[2][1] == 'X' &&  arr[2][2] == ' ')
					{
						arr[2][2] = 'O';
						return 1;
					}
					if (arr[0][0] == 'X' && arr[1][0] == 'X' &&  arr[2][0] == ' ')
					{
						arr[2][0] = 'O';
						return 1;
					}
					if (arr[1][0] == 'X' && arr[2][0] == 'X' &&  arr[0][0] == ' ')
					{
						arr[0][0] = 'O';
						return 1;
					}

					move_O(); //если не в рассматриваемой ситуации, то рандомно
					return 1;
				}
			}
		}

		move_O();//если не в рассматриваемой ситуации, то рандомно
		return 1;
	}

	int attack_X()
	{
		int bufer_i = -1, bufer_j = -1; // для хранения соседнего элемента
		for (int i = 0; i < 3; i++) // ищем Х
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] == 'X')
				{

					if (!(i == 1 && j == 1) && arr[1][1] == 'X') //если не в центре, но есть центральный элемент, по переводим на ситуацию "центр"
						goto center;

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
										arr[bufer_i][bufer_j] = 'X';
										return 1;
									}
								}
							}
						}
					}

					if (i != 1 && j != 1 && arr[i][j] == 'X') //если Х в углу, то ищем пару
					{
						int count = 0; //cчетчик кол-ва угловых элементов

						for (int q = 0; q < 3; q += 2) //считаем кол-во угловых элементов
							for (int p = 0; p < 3; p += 2)
								if (arr[q][p] == 'X')
									count++;

						if (count > 1) // если элементов 2 и больше, то ищем пары
						{
							if ((arr[0][0] == 'X' && arr[2][2] == 'X') || (arr[0][2] == 'X' && arr[2][0] == 'X')) //если пара диагональна
							{
								if (arr[1][1] == ' ') // и центр свободен, то ставим в центр
								{
									arr[1][1] = 'X';
									return 1;
								}
							}

							//4 варианта соседих углов
							// если есть пара и элемент между ними свободен, то делаем этот ход
							if (arr[0][0] == 'X' && arr[0][2] == 'X' && arr[0][1] == ' ')
							{
								arr[0][1] = 'X';
								return 1;
							}
							if (arr[0][0] == 'X' && arr[2][0] == 'X' && arr[1][0] == ' ')
							{
								arr[1][0] = 'X';
								return 1;
							}
							if (arr[2][0] == 'X' && arr[2][2] == 'X' && arr[2][1] == ' ')
							{
								arr[2][1] = 'X';
								return 1;
							}
							if (arr[0][2] == 'X' && arr[2][2] == 'X' && arr[1][2] == ' ')
							{
								arr[1][2] = 'X';
								return 1;
							}
						}
					}

					if ((arr[1][0] == 'X' && arr[1][2] == 'X') || (arr[0][1] == 'X' && arr[2][1] == 'X')) //если пара противоположная
					{
						if (arr[1][1] == ' ') // и центр свободен, то ставим в центр
						{
							arr[1][1] = 'X';
							return 1;
						}
					}

					//8 ситуаций на соседние элементы
					if (arr[0][0] == 'X' && arr[0][1] == 'X' &&  arr[0][2] == ' ')
					{
						arr[0][2] = 'X';
						return 1;
					}
					if (arr[0][1] == 'X' && arr[0][2] == 'X' &&  arr[0][0] == ' ')
					{
						arr[0][0] = 'X';
						return 1;
					}
					if (arr[0][2] == 'X' && arr[1][2] == 'X' &&  arr[2][2] == ' ')
					{
						arr[2][2] = 'X';
						return 1;
					}
					if (arr[1][2] == 'X' && arr[2][2] == 'X' &&  arr[0][2] == ' ')
					{
						arr[0][2] = 'X';
						return 1;
					}
					if (arr[2][2] == 'X' && arr[2][1] == 'X' &&  arr[2][0] == ' ')
					{
						arr[2][0] = 'X';
						return 1;
					}
					if (arr[2][0] == 'X' && arr[2][1] == 'X' &&  arr[2][2] == ' ')
					{
						arr[2][2] = 'X';
						return 1;
					}
					if (arr[0][0] == 'X' && arr[1][0] == 'X' &&  arr[2][0] == ' ')
					{
						arr[2][0] = 'X';
						return 1;
					}
					if (arr[1][0] == 'X' && arr[2][0] == 'X' &&  arr[0][0] == ' ')
					{
						arr[0][0] = 'X';
						return 1;
					}

					return 2;
				}
			}
		}
		return 2;
	}

	int defense_X()
	{
		int bufer_i = -1, bufer_j = -1; // для хранения соседнего элемента
		for (int i = 0; i < 3; i++) // ищем O
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] == 'O')
				{

					if (!(i == 1 && j == 1) && arr[1][1] == 'O') //если не в центре, но есть центральный элемент, по переводим на ситуацию "центр"
						goto center;

					if (i == 1 && j == 1) // если он в центре то ищем "Соседа", пропуская центр
					{
					center:
						for (int q = 0; q < 3; q++)
						{
							for (int p = 0; p < 3; p++)
							{
								if (!(q == 1 && p == 1) && arr[q][p] == 'O')
								{
									bufer_i = q; //запоминаем индексы "Соседа"
									bufer_j = p;

									bufer_i = 1 - bufer_i; //находим "шаг"
									bufer_j = 1 - bufer_j;
									bufer_i = 1 + bufer_i; //находим индексы "недостоющей до тройки" ячейки
									bufer_j = 1 + bufer_j;
									if (arr[bufer_i][bufer_j] == ' ')//если эта ячейка пустая, то запоняем
									{
										arr[bufer_i][bufer_j] = 'X';
										return 1;
									}
								}
							}
						}
					}

					if (i != 1 && j != 1 && arr[i][j] == 'O') //если Х в углу, то ищем пару
					{
						int count = 0; //cчетчик кол-ва угловых элементов

						for (int q = 0; q < 3; q += 2) //считаем кол-во угловых элементов
							for (int p = 0; p < 3; p += 2)
								if (arr[q][p] == 'O')
									count++;

						if (count > 1) // если элементов 2 и больше, то ищем пары
						{
							if ((arr[0][0] == 'O' && arr[2][2] == 'O') || (arr[0][2] == 'O' && arr[2][0] == 'O')) //если пара диагональна
							{
								if (arr[1][1] == ' ') // и центр свободен, то ставим в центр
								{
									arr[1][1] = 'X';
									return 1;
								}
							}

							//4 варианта соседих углов
							// если есть пара и элемент между ними свободен, то делаем этот ход
							if (arr[0][0] == 'O' && arr[0][2] == 'O' && arr[0][1] == ' ')
							{
								arr[0][1] = 'X';
								return 1;
							}
							if (arr[0][0] == 'O' && arr[2][0] == 'O' && arr[1][0] == ' ')
							{
								arr[1][0] = 'X';
								return 1;
							}
							if (arr[2][0] == 'O' && arr[2][2] == 'O' && arr[2][1] == ' ')
							{
								arr[2][1] = 'X';
								return 1;
							}
							if (arr[0][2] == 'O' && arr[2][2] == 'O' && arr[1][2] == ' ')
							{
								arr[1][2] = 'X';
								return 1;
							}
						}
					}

					if ((arr[1][0] == 'O' && arr[1][2] == 'O') || (arr[0][1] == 'O' && arr[2][1] == 'O')) //если пара противоположная
					{
						if (arr[1][1] == ' ') // и центр свободен, то ставим в центр
						{
							arr[1][1] = 'X';
							return 1;
						}
					}

					//8 ситуаций на соседние элементы
					if (arr[0][0] == 'O' && arr[0][1] == 'O' &&  arr[0][2] == ' ')
					{
						arr[0][2] = 'X';
						return 1;
					}
					if (arr[0][1] == 'O' && arr[0][2] == 'O' &&  arr[0][0] == ' ')
					{
						arr[0][0] = 'X';
						return 1;
					}
					if (arr[0][2] == 'O' && arr[1][2] == 'O' &&  arr[2][2] == ' ')
					{
						arr[2][2] = 'X';
						return 1;
					}
					if (arr[1][2] == 'O' && arr[2][2] == 'O' &&  arr[0][2] == ' ')
					{
						arr[0][2] = 'X';
						return 1;
					}
					if (arr[2][2] == 'O' && arr[2][1] == 'O' &&  arr[2][0] == ' ')
					{
						arr[2][0] = 'X';
						return 1;
					}
					if (arr[2][0] == 'O' && arr[2][1] == 'O' &&  arr[2][2] == ' ')
					{
						arr[2][2] = 'X';
						return 1;
					}
					if (arr[0][0] == 'O' && arr[1][0] == 'O' &&  arr[2][0] == ' ')
					{
						arr[2][0] = 'X';
						return 1;
					}
					if (arr[1][0] == 'O' && arr[2][0] == 'O' &&  arr[0][0] == ' ')
					{
						arr[0][0] = 'X';
						return 1;
					}

					move_X(); //если не в рассматриваемой ситуации, то рандомно
					return 1;
				}
			}
		}

		move_X(); //если не в рассматриваемой ситуации, то рандомно
		return 1;
	}

};


class Draw //рисовалка
{
private:
	COORD position;
	HANDLE hConsole;

public:
	Logic logic;

	Draw()
	{
		position.X = 0;
		position.Y = 0;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	void color()
	{
		system("color 1B");
	}

	void set_cursor(int x, int y)
	{
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(hConsole, position);
	}

	void rules()
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

	void map() // выводит все на экран
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

	void final_map() // выводит все на экран
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

	int start_menu()
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

	int move_menu()
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

	int final_menu()
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

	void result_info(char* result)
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

};

int main()
{
	setlocale(LC_ALL, "Russian");
	Draw game;
	char* result = new char; // победа/поражение/ничья
	int game_mode = 0;		 // режим игры
	int game_mode_copy = 0;	 //копия режима игры

	game.color();
	game.rules();

	do
	{
		game.logic.zeroing(); // обнуляем массив
		
		if(game_mode == 0)
			game_mode = game.start_menu(); //открываем меню

		if (game_mode == 1)// если игра с компьютером
		{
			if (game.move_menu() == 1) // если ходишь первым
			{
				game.map();
				while (!game.logic.full(result) && !game.logic.win(result)) // пока "не победа" и есть ячейки
				{
					game.logic.Enter_X();
					game.map();
					Sleep(500);
					if (!game.logic.full(result) && !game.logic.win(result)) // если не победа" и есть ячейки
					{
						if (game.logic.attack_O() == 2)// если атака не выполнилась, то выполняем защиту
							game.logic.defense_O();
						game.map();
					}
				}
			}
			else //если ходишь 2ым
			{
				game.map();
				while (!game.logic.full(result) && !game.logic.win(result)) // пока "не победа" и есть ячейки
				{
					Sleep(500);
					if (game.logic.attack_X() == 2)// если атака не выполнилась, то выполняем защиту
						game.logic.defense_X();
					game.map();

					if (!game.logic.full(result) && !game.logic.win(result)) // если "не победа" и есть ячейки
					{
						game.logic.Enter_O();
						game.map();
					}
				}
			}
		}
		else// с человеком
		{
			game.map();
			while (!game.logic.full(result) && !game.logic.win(result)) // пока "не победа" и есть ячейки
			{
				game.logic.Enter_X();
				game.map();

				if (!game.logic.full(result) && !game.logic.win(result)) // если "не победа" и есть ячейки
				{
					game.logic.Enter_O();
					game.map();
				}
			}
		}
		game.result_info(result);

		game_mode_copy = game.final_menu();
		if (game_mode_copy == 2) // если выбрали "меню", то обнулить режим игры
			game_mode = 0;

	} while (game_mode_copy != 3);

	delete result;
	return 0;
};