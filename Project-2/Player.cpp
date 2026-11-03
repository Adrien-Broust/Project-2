#include "Player.h"
#include <Windows.h>
#include <conio.h>
#include "Map.h"

void Player::movePlayer(vector2& character, int map[10][20])
{
    char key = getch();
    int dir = -1;
    if (key == 'z' || key == 'Z') {
        dir = 0;
    }
    else if (key == 's' || key == 'S') {
        dir = 1;
    }
    else if (key == 'q' || key == 'Q') {
        dir = 2;
    }
    else if (key == 'd' || key == 'D') {
        dir = 3;
    }
    if (dir != -1)
    {
        move(character, dir, map);
    }
}
