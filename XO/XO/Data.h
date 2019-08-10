#pragma once
#include <conio.h>

class Data //хранит инфо о состянии клеточек
{
protected:
	char arr[3][3];              //поле для игры

public:

	Data();                      //констуктор

	char get_info(int i, int j); //возвращает состояние клетки

	void zeroing();              //обнуляет поле

	void Enter_X();              //ввод Х

	void Enter_O();              //ввод О

};

