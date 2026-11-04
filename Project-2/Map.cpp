#include "Map.h"

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
			for (int x = 0; x < ligne.size(); ++x) {
				if (ligne[x] == '.') {
					map[y][x] = 0;
				}
				else if (ligne[x] == 'X') {
					perso[en]->pos.y = y;
					perso[en]->pos.x = x;
					perso[en]->pos.nom = "X";
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
					player.pos.nom = "H";
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
	if (niveau == 1) {
		int lectureinvalide = readMap(map, niveau, perso, player);
		if (lectureinvalide == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (niveau == 2) {
		int lectureinvalide = readMap(map, niveau, perso, player);
		if (lectureinvalide == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (niveau == 3) {
		int lectureinvalide = readMap(map, niveau, perso, player);
		if (lectureinvalide == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	return 0;
}

void Map::showMap(int map[10][20], std::vector<Enemy*>& perso, Player& player) {
	for (int y = 0; y < 10; ++y) {
		for (int x = 0; x < 20; ++x) {
			bool find = false;
			if (y == player.pos.y && x == player.pos.x) {
				std::cout << player.pos.nom;
			}
			else 
			{
			for (int a = 0; a < 5; ++a) {
				if (y == perso[a]->pos.y && x == perso[a]->pos.x) {
					std::cout << perso[a]->pos.nom;
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
}