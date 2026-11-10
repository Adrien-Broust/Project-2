#include "Enemy.h"
#include "Map.h"

void Enemy::move(Entity& character, int dir, int map[10][20])
{
    int newX = character.pos.x;
    int newY = character.pos.y;
    switch (dir)
    {
    case 0:
        newY--;
        break;
    case 1:
        newY++;
        break;
    case 2:
        newX--;
        break;
    case 3:
        newX++;
        break;
    default:
        return;
    }
    if (newX >= 0 && newX < 20 && newY >= 0 && newY < 10)
    {
        if (map[newY][newX] != Map::Montagne && map[newY][newX] != Map::Eau)
        {
            character.pos.x = newX;
            character.pos.y = newY;
        }
    }
}
