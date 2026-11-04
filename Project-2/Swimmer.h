#pragma once
#include "Utilities.h"
#include "Entity.h"
#include "Map.h"

class Swimmer
{
public:
	virtual void move(vector2& character, int dir, int map[10][20]);
	int o2 = 4;
	int o2max = 4;
};

