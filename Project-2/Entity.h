#pragma once
#include "Utilities.h"
#include <iostream>
class Entity
{
public:
	int pv;
	vector2 pos;
public:
	virtual vector2 getDirection() = 0;
	virtual bool move() = 0;
	virtual bool canMove() = 0;
	virtual void onCollision() = 0;

	virtual void damaged() = 0;
	virtual bool isAlive() = 0;

	virtual ~Entity() = default;
};

