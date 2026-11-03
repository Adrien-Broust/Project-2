#pragma once
#include "Enemy.h"
class HeadlessZombie : public Enemy
{
public:
	virtual void moveEnemy(vector2& character, int map[10][20]);
};


