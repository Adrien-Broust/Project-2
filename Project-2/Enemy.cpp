#include "Enemy.h"

bool Enemy::test()
{
	return true;
}

void Enemy::moveEnemy(vector2& character, int map[10][20], std::vector<Entity*>& perso)
{
	int distancex = perso[0]->pos.x - character.x;
	int distancey = perso[0]->pos.y - character.y;
	int dir = -1;
	if (distancex < distancey && distancex < 0){
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