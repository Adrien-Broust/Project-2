#include "Map.h"
#include "Zombie.h"
#include "HeadlessZombie.h"
#include "ZombieSwimmer.h"
#include <iostream>

using namespace std;

int Map::readMap(int map[10][20], int niveau, std::vector<Enemy*>& perso, Player& player) {
	string file;
	if (niveau == 1) {
		file = "Maps/Niveau1.txt";
	}
	if (niveau == 2) {
		file = "Maps/Niveau2.txt";
	}
	if (niveau == 3) {
		file = "Maps/Niveau3.txt";
	}
	ifstream fichier(file);
	if (fichier)
	{
		//switch
		string ligne;
		int en = 0;
		for (int y = 0; y < 10; ++y) {
			getline(fichier, ligne);
			for (int x = 0; x < ligne.size() && x < 20; ++x) {
				if (ligne[x] == '.') {
					map[y][x] = 0;
				}
				else if (ligne[x] == 'X') {
					perso[en] = new HeadlessZombie();
					perso[en]->pos.y = y;
					perso[en]->pos.x = x;
					perso[en]->pos.name = "X";
					en++;
				}
				else if (ligne[x] == 'Z') {
					perso[en] = new Zombie();
					perso[en]->pos.y = y;
					perso[en]->pos.x = x;
					perso[en]->pos.name = "X";
					en++;
				}
				else if (ligne[x] == '~') {
					map[y][x] = 1;
				}
				else if (ligne[x] == 'A') {
					map[y][x] = 2;
				}
				else if (ligne[x] == 'E') {
					map[y][x] = 3;
				}
				else if (ligne[x] == 'H') {
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

int Map::createMap(int map[10][20], int niveau, std::vector<Enemy*>& perso, Player& player)
{
	int lectureinvalide = readMap(map, niveau, perso, player);
	if (lectureinvalide == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

