#include "Game.h"
#include <vector>

void Game::run() {
	Map maps;
	int map[10][20] = {};
	Player player;
	std::vector<Enemy*> perso(5);
	for (int a = 0; a < 5; ++a) {
		perso[a] = new Enemy();
	}
	for (int niveau = 1; niveau < 4; ++niveau) {
		while (player.pv) {
			std::cout << "Niveau " << niveau << " :" << "\n" << "\n";
			int niveauinvalide = maps.createMap(map, niveau, perso, player);
			if (niveauinvalide == 1) {
				break;
			}
			maps.showMap(map, perso, player);
			player.movePlayer(player, map);
		}
	}
	std::cout << "\n" << "\n" << "FELICITATION !!!! VOUS AVEZ GAGNE !!!!";
}