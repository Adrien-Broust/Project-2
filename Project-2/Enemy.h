#pragma once
#include "Entity.h"

class Player;

class Enemy : public Entity 
{
public:
	virtual void moveEnemy(Enemy& character, int map[10][20], Player& player) = 0;
	virtual void move(Entity& character, int dir, int map[10][20]) override;
	void OnCollision(Player& target);
	virtual void OnUpdate(int map[10][20], Player& player) = 0;
	std::string nom = "X";
	int hp = 1;
};


