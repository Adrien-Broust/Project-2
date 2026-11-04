#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	void movePlayer(Player& character, int map[10][20]);
};


