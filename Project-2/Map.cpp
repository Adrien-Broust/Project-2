#include "Map.h"
#include "Zombie.h"
#include "ZombieSwimmer.h"
#include "HeadlessZombie.h"
#include <iostream>

using namespace std;

void chooseZombie(std::vector<Enemy*>& perso, int en, int y, int x)
{
	perso[en] = new Zombie();
	perso[en]->pos.y = y;
	perso[en]->pos.x = x;
	perso[en]->pos.name = "X";
	en++;
}

void chooseHeadlessZombie(std::vector<Enemy*>& perso, int en, int y, int x)
{
	perso[en] = new HeadlessZombie();
	perso[en]->pos.y = y;
	perso[en]->pos.x = x;
	perso[en]->pos.name = "O";
	en++;
}

void chooseZombieSwimmer(std::vector<Enemy*>& perso, int en, int y, int x)
{
	perso[en] = new ZombieSwimmer();
	perso[en]->pos.y = y;
	perso[en]->pos.x = x;
	perso[en]->pos.name = "S";
	en++;
}

void chooseTiles(int map[10][20], int en, int y, int x, int ligne[], Player& player, std::vector<Enemy*>& perso)
{
	if (ligne[x] == '.') 
	{
		map[y][x] = 0;
	}
	else if (ligne[x] == 'X') 
	{
		chooseZombie(perso, en, y, x);
	}
	else if (ligne[x] == 'O') 
	{
		chooseHeadlessZombie(perso, en, y, x);
	}
	else if (ligne[x] == 'S') 
	{
		chooseZombieSwimmer(perso, en, y, x);
	}
	else if (ligne[x] == '~') 
	{
		map[y][x] = 1;
	}
	else if (ligne[x] == 'A') 
	{
		map[y][x] = 2;
	}
	else if (ligne[x] == 'E') 
	{
		map[y][x] = 3;
	}
	else if (ligne[x] == 'H') 
	{
		player.pos.y = y;
		player.pos.x = x;
		player.pos.name = "H";
	}
}

int Map::readMap(int map[10][20], int niveau, std::vector<Enemy*>& perso, Player& player) 
{
	string file;
	if (niveau == 1) 
	{
		file = "Maps/Niveau1.txt";
	}
	if (niveau == 2) 
	{
		file = "Maps/Niveau2.txt";
	}
	if (niveau == 3) 
	{
		file = "Maps/Niveau3.txt";
	}
	ifstream fichier(file);
	if (fichier)
	{
		string ligne;
		int en = 0;
		for (int y = 0; y < 10; ++y) 
		{
			getline(fichier, ligne);
			for (int x = 0; x < ligne.size() && x < 20; ++x) 
			{
				if (ligne[x] == '.')
				{
					map[y][x] = 0;
				}
				else if (ligne[x] == 'X')
				{
					perso[en] = new Zombie();
					perso[en]->pos.y = y;
					perso[en]->pos.x = x;
					perso[en]->pos.name = "X";
					en++;
				}
				else if (ligne[x] == 'O')
				{
					perso[en] = new HeadlessZombie();
					perso[en]->pos.y = y;
					perso[en]->pos.x = x;
					perso[en]->pos.name = "O";
					en++;
				}
				else if (ligne[x] == 'S')
				{
					perso[en] = new ZombieSwimmer();
					perso[en]->pos.y = y;
					perso[en]->pos.x = x;
					perso[en]->pos.name = "S";
					en++;
				}
				else if (ligne[x] == '~')
				{
					map[y][x] = 1;
				}
				else if (ligne[x] == 'A')
				{
					map[y][x] = 2;
				}
				else if (ligne[x] == 'E')
				{
					map[y][x] = 3;
				}
				else if (ligne[x] == 'H')
				{
					player.pos.y = y;
					player.pos.x = x;
					player.pos.name = "H";
				}
			}
		}
	}
	else
	{
		std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
		return 1;
	}
	return 0;
}

int Map::createMap(int map[10][20], int niveau, std::vector<Enemy*>& perso, Player& player) {
	int lectureinvalide = readMap(map, niveau, perso, player);
	if (lectureinvalide == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void Map::showMap(int map[10][20], std::vector<Enemy*>& perso, Player& player) 
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
					if (y == perso[a]->pos.y && x == perso[a]->pos.x)
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