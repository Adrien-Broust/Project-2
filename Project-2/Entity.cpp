#include "Entity.h"

bool Entity::isAlive()
{
	return pv > 0;
}

vector2 Entity::getDirection(int dir)
{
    int newX = pos.x;
    int newY = pos.y;

    if (dir == 0) {
        newY--;
    }
    else if (dir == 1) {
        newY++;
    }
    else if (dir == 2) {
        newX--;
    }
    else if (dir == 3) {
        newX++;
    }
    pos.x = newX;
    pos.y = newY;
}
