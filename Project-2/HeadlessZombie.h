#pragma once
#include "Enemy.h"
#include "Player.h"

class HeadlessZombie : public Enemy
{
public:
	virtual void moveEnemy(Enemy& character, int map[10][20], Player& player) override;
	virtual int move(Entity& character, int dir, int map[10][20]) override;
	
};


