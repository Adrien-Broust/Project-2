#include "Enemy.h"
#include "Player.h"


void Enemy::moveEnemy(Enemy& character, int map[10][20], Player& player)
{

	int direction = getDirection(character,map,player);

	if (direction != -1)
	{
		move(*this, direction, map);
	}
}

int Enemy::getDirection(Enemy& character, int map[10][20], Player& player)
{
	int distancex = player.pos.x - character.pos.x;
	int distancey = player.pos.y - character.pos.y;
	if (distancex < distancey && distancex < 0) {
		return 3;
	}
	else if (distancex < distancey && distancex > 0) {
		return 2;
	}
	else if (distancey < distancex && distancey < 0) {
		return 1;
	}
	else if (distancey < distancex && distancey > 0) {
		return 0;
	}
}

int Enemy::move(Entity& character, int dir, int map[10][20]) 
{
	int newX = character.pos.x;
	int newY = character.pos.y;

	switch (dir)
	{
	case 0: newY--; break;
	case 1: newY++; break;
	case 2: newX--; break;
	case 3: newX++; break;
	default: return 0;
	}

	if (!isPositionValid(newX, newY))
	{
		return 2;
	}

	if (!isTerrainAccessible(newX, newY, map))
	{
		return 2;
	}

	character.pos.x = newX;
	character.pos.y = newY;
}