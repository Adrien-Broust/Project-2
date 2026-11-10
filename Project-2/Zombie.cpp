#include "Zombie.h"
#include "Player.h"

void Zombie::moveEnemy(Enemy& character, int map[10][20], Player& player) {
	int distancex = player.pos.x - character.pos.x;
	int distancey = player.pos.y - character.pos.y;
	int movement = -1;
	if (distancey > 0 && abs(distancey) >= abs(distancex)) {
		movement = 0;
	}
	else if (distancey < 0 && abs(distancey) >= abs(distancex)) {
		movement = 1;
	}
	else if (distancex < 0 && abs(distancex) >= abs(distancey)) {
		movement = 3;
	}
	else if (distancex > 0 && abs(distancex) >= abs(distancey)) {
		movement = 2;
	}
    int dir = -1;
    if (movement == 1) {
        dir = 0;
    }
    else if (movement == 2) {
        dir = 1;
    }
    else if (movement == 3) {
        dir = 2;
    }
    else if (movement == 4) {
        dir = 3;
    }
    if (dir != -1)
    {
        move(character, dir, map);
    }
}