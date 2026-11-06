#include "Game.h"
#include "Zombie.h"
#include <vector>
#include <iostream>

void Game::run() {
	Map maps;
	int map[10][20] = {};
	Player player;
	std::vector<Enemy*> perso(5);
	for (int a = 0; a < 5; ++a) {
		perso[a] = new HeadlessZombie();
	}
	for (int niveau = 1; niveau < 4; ++niveau) {
		int niveauinvalide = maps.createMap(map, niveau, perso, player);

		if (niveauinvalide == 1)
			break;

		while (player.hp)
		{
			system("cls");

			std::cout << "Niveau " << niveau << " :\n\n";

			maps.showMap(map, perso, player);
			int result = player.movePlayer(map);
			for (int a = 0; a < 5; ++a) {
				perso[a]->moveEnemy(*perso[a], map, player);
			}
			if (result == 0)
			{
				std::cout << "Bravo";
				break;
			}
			else if (result == 1)
			{
				std::cout << "Nul";
				player.hp = 0;
			}
		}
	}
	std::cout << "\n" << "\n" << "FELICITATION !!!! VOUS AVEZ GAGNE !!!!";
}