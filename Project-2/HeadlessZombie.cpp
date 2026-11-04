#include "HeadlessZombie.h"
#include "Map.h"

void HeadlessZombie::moveEnemy(Enemy& character, int map[10][20]) {
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
