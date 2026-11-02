#pragma once
#include "Entity.h"
class Enemy : public Entity 
{
public:
	virtual bool move() = 0;
	virtual bool canMove() = 0;

	void damaged();
	bool isAlive();

	virtual void moveEnemy() = 0;

	
private:
	vector2 pos;
	int pv = 1;
};

