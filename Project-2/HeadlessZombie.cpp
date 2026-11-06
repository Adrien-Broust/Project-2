#include "HeadlessZombie.h"
#include "Player.h"

int HeadlessZombie::getDirection(Enemy& character, int map[10][20], Player& player) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 4);
    int movement = distrib(gen);
    if (movement == 1) {
        return 0;
    }
    else if (movement == 2) {
        return 1;
    }
    else if (movement == 3) {
        return 2;
    }
    else if (movement == 4) {
        return 3;
    }
}


