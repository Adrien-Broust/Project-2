#pragma once
#include "Map.h"
#include "HeadlessZombie.h"
#include "Zombie.h"
#include "ZombieSwimmer.h"
#include "Mage.h"
#include "Warrior.h"

class Game
{
public:
	void showMap(int map[10][20], std::vector<Enemy*>& perso, Player& player);
	void run();
};