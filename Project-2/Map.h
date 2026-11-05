#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"

class Map
{
public:
	enum Terrains
	{
		Sol = 0,
		Montagne = 1,
		Eau = 2,
		Sortie = 3,
	};
	int readMap(int map[10][20], int niveau, std::vector<Enemy*>& perso, Player& player);
	int createMap(int map[10][20], int niveau, std::vector<Enemy*>& perso, Player& player);
	void showMap(int map[10][20], std::vector<Enemy*>& perso, Player& player);
};

