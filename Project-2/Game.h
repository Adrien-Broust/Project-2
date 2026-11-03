#pragma once
#include "Map.h"
#include "HeadlessZombie.h"
#include "Zombie.h"
#include "ZombieSwimmer.h"
#include "Mage.h"
#include "Warrior.h"

class Game
{
	void run() {
		Map maps;
		int niveau = 1;
		int map[10][20] = {};
		Entity* perso[7];
		for (int n = 1; n < 4; ++n) {
			std::cout << "Niveau " << niveau << " :" << "\n" << "\n";
			int niveauinvalide = maps.createMap(map, niveau, perso);
			if (niveauinvalide == 1) {
				break;
			}
			maps.showMap(map, perso);
		}
		if (niveau == 4) {
			std::cout << "\n" << "\n" << "FELICITATION !!!! VOUS AVEZ GAGNE !!!!";
		}
	}
};