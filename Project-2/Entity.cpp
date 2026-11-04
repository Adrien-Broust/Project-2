#include "Entity.h"
#include "Map.h"

void Entity::move(Entity& character, int dir, int map[10][20])
{
    int coorx = character.pos.x;
    int coory = character.pos.y;
    if (dir == 0)
    {
        character.pos.y--;
    }
    else if (dir == 1)
    {
        character.pos.y++;
    }
    else if (dir == 2)
    {
        character.pos.x--;
    }
    else if (dir == 3)
    {
        character.pos.x++;
    }
    if (character.pos.x < 0 || character.pos.x >= 20 || character.pos.y < 0 || character.pos.y >= 10)
    {
        character.pos.y = coory;
        character.pos.x = coorx;
    }
    if (map[character.pos.y][character.pos.x] == Map::Terrains::Montagne)
    {
        character.pos.y = coory;
        character.pos.x = coorx;
    }
    if (map[character.pos.y][character.pos.x] == Map::Terrains::Eau)
    {
        character.pos.y = coory;
        character.pos.x = coorx;
    }
}
