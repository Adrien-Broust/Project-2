#include "HeadlessZombie.h"
#include "Map.h"

void HeadlessZombie::moveEnemy(Enemy& character, int map[10][20], Player& player) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 4);
    int movement = distrib(gen);
    int dir = -1;
    if (movement == 1) {
        dir = 0;
    }
    else if (movement == 2) {
        dir = 1;
    }
    else if (movement == 3) {
        dir = 2;
    }
    else if (movement == 4) {
        dir = 3;
    }
    if (dir != -1)
    {
        move(character, dir, map);
    }
}

int HeadlessZombie::move(Entity& character, int dir, int map[10][20])
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
        return 0;
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
