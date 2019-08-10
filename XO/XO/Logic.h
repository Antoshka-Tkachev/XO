#pragma once
#include "Data.h"
#include <Windows.h>
#include <ctime>

class Logic : public Data    //логика игры
{
public:

	void move_O();           //рандомный ход О

	void move_X();           //рандомный ход Х

	bool full(char *result); //проверка на заполенность поля

	bool win(char *result);  //проверка на победу

	int attack_O();          //атака О

	int defense_O();         //защита О

	int attack_X();          //атака Х

	int defense_X();         //защита Х

};

