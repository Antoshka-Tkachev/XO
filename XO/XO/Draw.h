#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include "Logic.h"

using namespace std;

class Draw //интерфейс
{
private:
	COORD position;  //координаты курсора
	HANDLE hConsole;

public:
	Logic logic; //обьект логики

	Draw();                           //конструктор

	void color();                     // задает цвет консоли

	void set_cursor(int x, int y);    //устанавливает курсор

	void rules();                     // выводит начальный правила

	void map();                       // выводит карту

	void final_map();                 // выводит карту после конца игры

	int start_menu();                 // выводит стартовое меню (выбор режима игры)

	int move_menu();                  // меню выбора хода

	int final_menu();                 // финальное меню

	void result_info(char* result);   // выводит результат игры(Победа и тд)

};

