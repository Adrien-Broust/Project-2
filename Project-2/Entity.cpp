#include "Entity.h"
#include "Map.h"

bool Entity::isAlive(Entity& character) 
{
	return character.hp > 0;
}

bool Entity::isPositionValid(int x, int y)
{
    return x >= 0 && x < 20 && y >= 0 && y < 10;
}

bool Entity::isTerrainAccessible(int x, int y, int map[10][20])
{
    return map[y][x] != Map::Montagne && map[y][x] != Map::Eau;
}