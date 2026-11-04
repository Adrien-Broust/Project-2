#pragma once
#include "Utilities.h"
#include <iostream>
class Entity
{
public:
	void move(Entity& character, int dir, int map[10][20]);

	virtual ~Entity() = default;
public:
	vector2 pos;
	int pv = 1;
};

