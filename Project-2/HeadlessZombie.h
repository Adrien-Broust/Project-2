#pragma once
#include "Enemy.h"

class Player;

class HeadlessZombie : public Enemy
{
public:
	int getDirection(Enemy& character, int map[10][20], Player& player) override;
};


