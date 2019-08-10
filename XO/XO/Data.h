#pragma once
#include <conio.h>

class Data //хранит инфо о состянии клеточек
{
protected:
	char arr[3][3];

public:

	Data();

	char get_info(int i, int j);

	void zeroing();

	void Enter_X();

	void Enter_O();

};

