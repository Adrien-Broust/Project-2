#pragma once
#include "Player.h"

class Warrior : public Player
{
public:
	void Collision(std::vector<Entity*>& target);
	int getPv();
	void setPv(int value);
	int hp = 4;
	int pv = 4;
};

