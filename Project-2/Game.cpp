#include "Game.h"
#include "HeadlessZombie.h"
#include <vector>

void Game::run() {
	Map maps;
	int map[10][20] = {};
	Warrior player;
	std::vector<Enemy*> perso(5);
	for (int a = 0; a < 5; ++a) {
		perso[a] = new HeadlessZombie();
	}
	for (int niveau = 1; niveau < 4; ++niveau) {
		int niveauinvalide = maps.createMap(map, niveau, perso, player);

		if (niveauinvalide == 1)
			break;

		while (player.PlayerHp > 0)
		{
			system("cls");

			std::cout << "Niveau " << niveau << " :\n\n" << "PV" << " :" << player.PlayerHp << "\n\n";

			maps.showMap(map, perso, player);
			player.movePlayer(map);
			player.OnCollision(perso);
		}
		if(player.PlayerHp <= 0)
		{
			std::cout << "\n" << "\n" << "VOUS AVEZ PERDU !!!!";
			break;
		}
	}
	std::cout << "\n" << "\n" << "FELICITATION !!!! VOUS AVEZ GAGNE !!!!";
}