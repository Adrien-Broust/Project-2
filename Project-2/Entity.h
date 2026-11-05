#pragma once
#include "Utilities.h"
#include <iostream>
class Entity
{
public:
	Entity() : pos{"", 0, 0} {}

	virtual int move(Entity& character, int dir, int map[10][20]) = 0;

	virtual ~Entity() = default;
public:
	vector2 pos;
};

