#pragma once
#include "Utilities.h"
#include <iostream>
class Entity
{
public:
<<<<<<< Updated upstream
	int pv;
	vector2 pos;
public:
	virtual vector2 getDirection() = 0;
=======
	vector2 getDirection(int dir);
>>>>>>> Stashed changes
	virtual bool move() = 0;
	virtual bool canMove() = 0;
	virtual void onCollision() = 0;

	virtual void damaged() = 0;
	bool isAlive();

	virtual ~Entity() = default;
private:
	vector2 pos;
	int pv;
};

