#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
<<<<<<< Updated upstream

	// Hérité via Entity
	vector2 getDirection() override;

	bool move() override;

	bool canMove() override;

	void onCollision() override;

	void damaged() override;

	bool isAlive() override;

=======
	bool move();
	bool canMove(Player& player, int map[10][20]);
	virtual void damaged() = 0;
	void movePlayer(int map[10][20]);

private:
	vector2 posPlayer;
>>>>>>> Stashed changes
};

