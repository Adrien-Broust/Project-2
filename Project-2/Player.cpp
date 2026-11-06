#include "Player.h"
#include <conio.h>
#include "Map.h"


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

void Player::movePlayer(int map[10][20])
{
    char key = _getch();

    if (key == 'x' || key == 'X')
    {
        return;
    }

    int direction = getDirectionFromKey(key);

    if (direction != -1)
    {
		move(*this, direction, map);
    }
}

bool Player::isPositionValid(int x, int y)
{
    return x >= 0 && x < 20 && y >= 0 && y < 10;
}

bool Player::isTerrainAccessible(int x, int y, int map[10][20])
{
    return map[y][x] != Map::Montagne && map[y][x] != Map::Eau;
}

void Player::move(Entity& character, int dir, int map[10][20])
{
    int newX = character.pos.x;
    int newY = character.pos.y;

    switch (dir)
    {
    case 0: newY--; break;
    case 1: newY++; break;
    case 2: newX--; break;
    case 3: newX++; break;
    default: return;
    }

    if (!isPositionValid(newX, newY))
    {
        return;
    }

    if (!isTerrainAccessible(newX, newY, map))
    {
		return;
    }
        

    character.pos.x = newX;
    character.pos.y = newY;
}

void Player::OnCollision(std::vector<Enemy*> target)
{
    size_t size = target.size();
    for (int i = 0; i < size; i++) {
        if (target[i]->pos.x == pos.x && target[i]->pos.y == pos.y) {
            PlayerHp--;
            break;
        }
    }
}
