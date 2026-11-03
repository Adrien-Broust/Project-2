#include "Player.h"
<<<<<<< Updated upstream

vector2 Player::getDirection()
{
    return vector2();
}

bool Player::move()
{
    return false;
}

bool Player::canMove()
{
    return false;
}

void Player::onCollision()
{
}

void Player::damaged()
{
}

bool Player::isAlive()
{
    return false;
=======
#include <Windows.h>
#include <conio.h>
#include "Map.h"

bool Player::canMove(Player& player, int map[10][20])
{
    vector2 savePos = player.posPlayer;
    if (savePos.x < 0 || savePos.x >= 20 ||savePos.y < 0 || savePos.y >= 10)
    {
        return false;
    }
    if (map[savePos.y * 20 + savePos.x] == Montagne)
    {
        return false;
    }
}

void Player::movePlayer(int map[10][20])
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
    canMove(map);
    getDirection(dir);
>>>>>>> Stashed changes
}
