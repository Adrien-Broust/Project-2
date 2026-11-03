#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	void movePlayer(vector2& character, int map[10][20]);

private:
	vector2 posPlayer;
};


