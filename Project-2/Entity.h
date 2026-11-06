#pragma once
#include "Utilities.h"

class Entity
{
public:
	Entity() : pos{"", 0, 0} {}
	virtual bool isPositionValid(int x, int y) ;
	virtual bool isTerrainAccessible(int x, int y, int map[10][20]) ;
	bool isAlive(Entity& character);
	virtual int move(Entity& character, int dir, int map[10][20]) = 0;
	virtual ~Entity() = default;
	vector2 pos;
	int hp = 1;
};

