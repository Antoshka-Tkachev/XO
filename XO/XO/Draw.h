#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include "Logic.h"

using namespace std;

class Draw //рисовалка
{
private:
	COORD position;
	HANDLE hConsole;

public:
	Logic logic;

	Draw();

	void color();

	void set_cursor(int x, int y);

	void rules();

	void map();

	void final_map();

	int start_menu();

	int move_menu();

	int final_menu();

	void result_info(char* result);

};

