#pragma once
#include "Entity.h"

class Player;

class Enemy : public Entity 
{
public:
	virtual void moveEnemy(Enemy& character, int map[10][20], Player& player);
	virtual int getDirection(Enemy& character, int map[10][20], Player& player);
	int move(Entity& character, int dir, int map[10][20]);
	std::string nom = "X";
};


