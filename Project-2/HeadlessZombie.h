#pragma once
#include "Enemy.h"
#include "Player.h"

class HeadlessZombie : public Enemy
{
public:
	virtual void moveEnemy(Enemy& character, int map[10][20], Player& player) override;
	void OnUpdate(int map[10][20], Player& player) override;	
};


