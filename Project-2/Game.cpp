#include "Game.h"
#include "Zombie.h"
#include <vector>
#include <iostream>

void Game::showMap(int map[10][20], std::vector<Enemy*>& perso, Player& player)
{
	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 20; ++x)
		{
			bool find = false;
			if (y == player.pos.y && x == player.pos.x)
			{
				std::cout << player.pos.name;
				find = true;
			}
			else
			{
				for (int a = 0; a < 5; ++a)
				{
					if (y == perso[a]->pos.y && x == perso[a]->pos.x && perso[a]->hp > 0)
					{
						std::cout << perso[a]->pos.name;
						find = true;
						break;
					}
				}
				if (find)
					continue;
				else if (map[y][x] == 0)
				{
					std::cout << '.';
				}
				else if (map[y][x] == 1)
				{
					std::cout << '~';
				}
				else if (map[y][x] == 2)
				{
					std::cout << 'A';
				}
				else if (map[y][x] == 3)
				{
					std::cout << 'E';
				}
			}
		}
		std::cout << '\n';
	}
}

Player Game::choosecharacter() {
	std::cout << "Choose your character:\n";
	std::cout << "1. Mage\n";
	std::cout << "2. Warrior\n";
	int choice;
	std::cin >> choice;
	if (choice == 1) {
		Mage player;
	}
	else if (choice == 2) {
		Warrior player;
	}
	else {
		std::cout << "Invalid choice. Defaulting to Mage.\n";
		return Mage();
	}
}

void Game::run() {
	Map maps;
	int map[10][20] = {};
	Warrior player;
	std::vector<Enemy*> perso(5);
	for (int niveau = 1; niveau < 4; ++niveau) {
		int niveauinvalide = maps.createMap(map, niveau, perso, player);
		if (niveauinvalide == 1)
			break;

		while (player.hp)
		{
			system("cls");

			std::cout << "Niveau " << niveau << " :\n\n" << "PV" << " :" << player.hp << "\n\n";

			showMap(map, perso, player);
			int result = player.movePlayer(map);
			maps.OnCollision(perso, player);
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
			if (player.hp <= 0)
			{
				std::cout << "\n" << "\n" << "VOUS AVEZ PERDU !!!!";
				break;
			}
		}
	}
	std::cout << "\n" << "\n" << "FELICITATION !!!! VOUS AVEZ GAGNE !!!!";
}