#include "Player.h"
#include "Map.h"
#include <conio.h>

int Player::getDirectionFromKey(char key)
{
    switch (key)
    {
    case 'z': case 'Z': return 0;
    case 's': case 'S': return 1;
    case 'q': case 'Q': return 2;
    case 'd': case 'D': return 3;
    default: return -1;
    }
}

int Player::movePlayer(int map[10][20])
{
    char key = _getch();

    if (key == 'x' || key == 'X')
    {
        return 1;
    }

    int direction = getDirectionFromKey(key);

    if (direction != -1)
    {
		int Exit = move(*this, direction, map);
        if (Exit == 1)
        {
			return 0;

		}
    }
}

bool Player::isExit(int x, int y, int map[10][20])
{
    return map[y][x] != Map::Sortie;
}

int Player::move(Entity& character, int dir, int map[10][20])
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

    if (!isExit(newX, newY, map))
    {
        return 1;
    }

    character.pos.x = newX;
    character.pos.y = newY;
}