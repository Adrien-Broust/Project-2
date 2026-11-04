#include "Enemy.h"

bool Enemy::test()
{
	return true;
}

void Enemy::moveEnemy(Enemy& character, int map[10][20], Player& player)
{
	int distancex = player.pos.x - character.pos.x;
	int distancey = player.pos.y - character.pos.y;
	int dir = -1;
	if (distancex < distancey && distancex < 0) {
		dir = 3;
	}
	else if (distancex < distancey && distancex > 0) {
		dir = 2;
	}
	else if (distancey < distancex && distancey < 0) {
		dir = 0;
	}
	else if (distancey < distancex && distancey > 0) {
		dir = 1;
	}
	if (dir != -1)
	{
		move(character, dir, map);
	}
}