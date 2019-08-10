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