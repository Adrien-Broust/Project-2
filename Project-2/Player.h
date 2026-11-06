#pragma once
#include "Entity.h"

class Enemy;

class Player : public Entity
{
private:
    int getDirectionFromKey(char key);
    bool isPositionValid(int x, int y);
    bool isTerrainAccessible(int x, int y, int map[10][20]);

public:
    void movePlayer(int map[10][20]);
    void move(Entity& character, int dir, int map[10][20]) override;
    void OnCollision(std::vector<Enemy*> target);
    int PlayerHp = 1;
};

