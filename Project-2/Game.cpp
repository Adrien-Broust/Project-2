#include "Game.h"
#include "Zombie.h"
#include <vector>
#include <iostream>

Player Game::choosecharacter() {
	std::cout << "Choose your character:\n";
	std::cout << "1. Mage\n";
	std::cout << "2. Warrior\n";
	int choice;
	std::cin >> choice;
	if (choice == 1) {
		return Mage();
	}
	else if (choice == 2) {
		return Warrior();
	}
	else {
		std::cout << "Invalid choice. Defaulting to Mage.\n";
		return Mage();
	}
}

void Game::run() {
	Map maps;
	int map[10][20] = {};
	Player player = choosecharacter();
	std::vector<Enemy*> perso(5);
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
				break;
			}
			else if (result == 1)
			{
				player.hp = 0;
			}
		}
	}
	std::cout << "\n" << "\n" << "FELICITATION !!!! VOUS AVEZ GAGNE !!!!";
}