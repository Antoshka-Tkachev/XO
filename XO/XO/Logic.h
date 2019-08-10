#pragma once
#include "Data.h"
#include <Windows.h>
#include <ctime>

class Logic : public Data
{
public:

	void move_O();

	void move_X();

	bool full(char *result);

	bool win(char *result);

	int attack_O();

	int defense_O();

	int attack_X();

	int defense_X();

};

