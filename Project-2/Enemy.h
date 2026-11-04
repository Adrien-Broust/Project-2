#pragma once
#include "Entity.h"
class Enemy : public Entity 
{
public:
	virtual void moveEnemy(vector2& character, int map[10][20], std::vector<Entity*>& perso);
	bool test();
};


