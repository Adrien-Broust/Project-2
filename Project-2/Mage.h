#pragma once
#include "Player.h"
#include <conio.h>

class Enemy;

class Mage : public Player
{
public:
	int movePlayer(int map[10][20], std::vector<Enemy*> perso) override;
	void spell(std::vector<Enemy*> perso);	
	void OnUpdate(int map[10][20], std::vector<Enemy*> enemies) override;
};

