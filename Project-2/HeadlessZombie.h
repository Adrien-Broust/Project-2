#pragma once
#include "Enemy.h"
class HeadlessZombie : public Enemy
{
public:
	virtual void moveEnemy(Enemy& character, int map[10][20]);
};


