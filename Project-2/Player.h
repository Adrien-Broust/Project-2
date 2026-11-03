#pragma once
#include "Entity.h"
class Player : public Entity
{
public:

	// Hérité via Entity
	vector2 getDirection() override;

	bool move() override;

	bool canMove() override;

	void onCollision() override;

	void damaged() override;

	bool isAlive() override;

};

