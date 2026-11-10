#pragma once
#include "Enemy.h"
class Zombie : public Enemy
{
	void moveEnemy(Enemy& character, int map[10][20], Player& player) override;
	void OnUpdate(int map[10][20], Player& player) override;
};

