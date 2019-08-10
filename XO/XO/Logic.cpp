#include "pch.h"
#include "Logic.h"


void Logic::move_O() // делает рандомный ход ноликом
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

void Logic::move_X() // делает рандомный ход крестиком
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

bool Logic::full(char *result)
{

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (arr[i][j] == ' ')
				return false;
	*result = 'N';

	return true;
}

bool Logic::win(char *result)
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

int Logic::attack_O()
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

int Logic::defense_O()
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

int Logic::attack_X()
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

int Logic::defense_X()
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
