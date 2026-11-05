#pragma once
#include "Entity.h"
#include "Player.h"

class Enemy : public Entity 
{
public:
	virtual void moveEnemy(Enemy& character, int map[10][20], Player& player) = 0;
	std::string nom = "X";
};


