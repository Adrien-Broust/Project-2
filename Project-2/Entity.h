#pragma once
#include "Utilities.h"
#include <iostream>
class Entity
{
public:
	virtual void move(vector2& character, int dir, int map[10][20]);

	virtual ~Entity() = default;
};

