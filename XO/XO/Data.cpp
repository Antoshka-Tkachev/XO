#include "pch.h"
#include "Data.h"

Data :: Data() // конструктор
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			arr[i][j] = ' ';
}

char Data::get_info(int i, int j) // возвращает состояние клетки
{
	return arr[i][j];
}

void Data::zeroing()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			arr[i][j] = ' ';
}

void Data::Enter_X() // фунция для ввода
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

void Data::Enter_O() // фунция для ввода
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