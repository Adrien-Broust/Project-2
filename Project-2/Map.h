#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include "Entity.h"

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
	int readMap(int map[10][20], int niveau, std::vector<Entity*>& perso);
	int createMap(int map[10][20], int niveau, std::vector<Entity*>& perso);
	void showMap(int map[10][20], std::vector<Entity*>& perso);
};

