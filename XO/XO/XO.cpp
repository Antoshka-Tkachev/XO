#include "pch.h"
#include <iostream>
#include <Windows.h>
#include "Data.h"
#include "Logic.h"
#include "Draw.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Draw game;               //обект класса интерфейса
	char* result = new char; // хранит результат (победа/поражение/ничья)
	int game_mode = 0;		 // режим игры
	int game_mode_copy = 0;	 //копия режима игры

	game.color(); //меняет цвет консоли
	game.rules(); //выводит начальные правила

	do
	{
		game.logic.zeroing(); // обнуляем массив
		
		if(game_mode == 0)	  //если режим игры не выбран (равен 0)
			game_mode = game.start_menu(); //открываем меню

		if (game_mode == 1)// если игра с компьютером
		{
			if (game.move_menu() == 1) // если ходишь первым
			{
				game.map(); //рисуем карту
				while (!game.logic.full(result) && !game.logic.win(result)) // пока "не победа" и есть ячейки
				{
					game.logic.Enter_X(); // ждет ввода хода
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
				while (!game.logic.full(result) && !game.logic.win(result))  // пока "не победа" и есть ячейки
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
			while (!game.logic.full(result) && !game.logic.win(result))  // пока "не победа" и есть ячейки
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
		game.result_info(result);           //выводим результат игры

		game_mode_copy = game.final_menu(); // сохраняет выбор в "финальном меню"
		if (game_mode_copy == 2)            // если выбрали "вернуться в меню", то обнуляем режим игры
			game_mode = 0;

	} while (game_mode_copy != 3); //пока не выбрали "завершить игру"

	delete result;
	return 0;
};