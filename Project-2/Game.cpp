#include "Game.h"
#include <vector>

void Game::spell(std::vector<Enemy*> perso, Player& player)
{
	for (auto i = perso.begin(); i != perso.end(); i++)
	{
		if ((*i)->pos.x == player.pos.x - 1 && (*i)->pos.y == player.pos.y)
		{
			(*i)->hp--;
		}
		else if ((*i)->pos.x == player.pos.x + 1 && (*i)->pos.y == player.pos.y)
		{
			(*i)->hp--;
		}
		else if ((*i)->pos.x == player.pos.x && (*i)->pos.y == player.pos.y - 1)
		{
			(*i)->hp--;
		}
		else if ((*i)->pos.x == player.pos.x && (*i)->pos.y == player.pos.y + 1)
		{
			(*i)->hp--;
		}
	}
}
int Game::showMap(int map[10][20], std::vector<Enemy*>& perso, Player& player) {
	if (map[player.pos.y][player.pos.x] == 3)
	{
		return 1;
	}
	for (int y = 0; y < 10; ++y) {
		for (int x = 0; x < 20; ++x) {
			bool find = false;
			if (y == player.pos.y && x == player.pos.x) {
				std::cout << player.pos.name;
				find = true;
			}
			else
			{
				for (int a = 0; a < 5; ++a) {
					if (y == perso[a]->pos.y && x == perso[a]->pos.x && perso[a]->hp > 0) {
						std::cout << perso[a]->pos.name;
						find = true;
						break;
					}
				}
				if (find)
					continue;
				else if (map[y][x] == 0) {
					std::cout << '.';
				}
				else if (map[y][x] == 1) {
					std::cout << '~';
				}
				else if (map[y][x] == 2) {
					std::cout << 'A';
				}
				else if (map[y][x] == 3) {
					std::cout << 'E';
				}
			}
		}
		std::cout << '\n';
	}
	return 0;
}

void Game::run() {
	Map maps;
	int map[10][20] = {};
	Mage player;
	int victories = 0;
	std::vector<Enemy*> perso(5);
	for (int niveau = 1; niveau < 4; ++niveau) {
		int niveauinvalide = maps.createMap(map, niveau, perso, player);

		if (niveauinvalide == 1)
			break;

		while (player.PlayerHp > 0)
		{
			system("cls");

			std::cout << "Niveau " << niveau << " :\n\n" << "PV" << " :" << player.PlayerHp << "\n\n";

			int isExit = showMap(map, perso, player);
			if (isExit == 1)
			{
				victories += 1;
				break;
			}
			int movevalide = player.movePlayer(map);
			if (movevalide == 1)
			{
				player.PlayerHp = 0;
			}
			if (movevalide == 2)
			{
				spell(perso,player);
			}
			for (int i = 0; i < 5; i++)
			{
				if (perso[i]->hp > 0)
				{
				perso[i]->moveEnemy(*perso[i], map, player);
				}
			}
			player.OnCollision(perso);
		}
		if(player.PlayerHp <= 0)
		{
			std::cout << "\n" << "\n" << "VOUS AVEZ PERDU !!!!";
			break;
		}
	}
	if (victories == 3)
	{
		std::cout << "\n" << "\n" << "FELICITATION !!!! VOUS AVEZ GAGNE !!!!";
	}
}