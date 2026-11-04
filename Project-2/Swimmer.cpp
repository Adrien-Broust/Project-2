#include "Swimmer.h"

void Swimmer::move(vector2& character, int dir, int map[10][20])
{
    int newx = character.x;
    int newy = character.y;

    if (dir == 0)
    {
        newy--;
    }
    else if (dir == 1)
    {
        newy++;
    }
    else if (dir == 2)
    {
        newx--;
    }
    else if (dir == 3)
    {
        newx++;
    }
    if (newx < 0 || newx >= 20 || newy < 0 || newy >= 10)
    {
        return;
    }
    if (map[newy][newx] == Map::Terrains::Montagne)
    {
        return;
    }
    if (map[newy][newx] == Map::Terrains::Eau)
    {
        o2 -= 1;
    }
    character.x = newx;
    character.y = newy;
}
