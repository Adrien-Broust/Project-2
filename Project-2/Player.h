#pragma once
#include "Entity.h"

class Enemy;

class Player : public Entity
{
private:
    bool isPositionValid(int x, int y);
    bool isTerrainAccessible(int x, int y, int map[10][20]);

public:
    int getDirectionFromKey(char key);
    virtual int movePlayer(int map[10][20], std::vector<Enemy*> perso);
    void move(Entity& character, int dir, int map[10][20]);
    void OnCollision(std::vector<Enemy*> target);
	virtual void OnUpdate(int map[10][20], std::vector<Enemy*> enemies);
    int PlayerHp = 1;
};

