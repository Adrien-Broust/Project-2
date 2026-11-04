#pragma once
#include "Entity.h"
class Enemy : public Entity 
{
public:

	// Hérité via Entity
	vector2 getDirection() override;

	bool move() override;

	bool canMove() override;

	void onCollision() override;

	void damaged() override;

	bool isAlive() override;

	vector2 getxenemy();
	vector2 getYenemy();
private:
	vector2 posEnemy;
};


