#include "Game.h"
#include <vector>

void Game::run() {
	Map maps;
	int map[10][20] = {};
	std::vector<Entity*> perso(6);
	perso[0] = new Player();
	for (int a = 1; a < 6; ++a) {
		perso[a] = new Enemy();
	}
	for (int niveau = 1; niveau < 4; ++niveau) {
		std::cout << "Niveau " << niveau << " :" << "\n" << "\n";
		int niveauinvalide = maps.createMap(map, niveau, perso);
		if (niveauinvalide == 1) {
			break;
		}
		maps.showMap(map, perso);
	}
	std::cout << "\n" << "\n" << "FELICITATION !!!! VOUS AVEZ GAGNE !!!!";
}