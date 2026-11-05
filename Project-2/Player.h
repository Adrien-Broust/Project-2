#pragma once
#include "Entity.h"

class Player : public Entity
{
private:
    int getDirectionFromKey(char key);
    bool isPositionValid(int x, int y);
    bool isTerrainAccessible(int x, int y, int map[10][20]);
    bool isExit(int x, int y, int map[10][20]);

public:
    int movePlayer(int map[10][20]);
    int move(Entity& character, int dir, int map[10][20]) override;

    int hp = 1;
};

