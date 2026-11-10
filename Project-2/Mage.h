#pragma once
#include "Player.h"
#include <conio.h>

class Enemy;

class Mage : public Player
{
public:
	/*void spell(std::vector<Enemy*> perso);*/
	int movePlayer(int map[10][20]) override;
};

