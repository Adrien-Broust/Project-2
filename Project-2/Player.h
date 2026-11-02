#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	virtual bool move() = 0;
	virtual bool canMove() = 0;

	virtual void damaged() = 0;
	virtual bool isAlive() = 0;

	virtual void movePlayer() = 0;

private:
	int x;
	int y;

};

