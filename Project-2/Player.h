#pragma once
#include "Entity.h"

class Player : public Entity
{
private:
    int getDirectionFromKey(char key);
    bool isExit(int x, int y, int map[10][20]);

public:
    int movePlayer(int map[10][20]);
    int move(Entity& character, int dir, int map[10][20]);
};

