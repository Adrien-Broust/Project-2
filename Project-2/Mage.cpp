#include "Mage.h"
#include "Enemy.h"
#include "Map.h"

int Mage::movePlayer(int map[10][20], std::vector<Enemy*> perso)
{
	char key = _getch();
	int direction = getDirectionFromKey(key);
	if (key == 'x' || key == 'X')
	{
		return 1;
	}
	if (key == ' ')
	{
		spell(perso);
	}
	if (direction != -1)
	{
		move(*this, direction, map);
		return 0;
	}
}

void Mage::spell(std::vector<Enemy*> perso)
{
	for (auto i = perso.begin(); i != perso.end(); i++)
	{
		if ((*i)->pos.x == pos.x - 1 && (*i)->pos.y == pos.y)
		{
			(*i)->hp--;
		}
		else if ((*i)->pos.x == pos.x + 1 && (*i)->pos.y == pos.y)
		{
			(*i)->hp--;
		}
		else if ((*i)->pos.x == pos.x && (*i)->pos.y == pos.y - 1)
		{
			(*i)->hp--;
		}
		else if ((*i)->pos.x == pos.x && (*i)->pos.y == pos.y + 1)
		{
			(*i)->hp--;
		}
	}
}

void Mage::OnUpdate(int map[10][20], std::vector<Enemy*> enemies)
{
	movePlayer(map, enemies);
	OnCollision(enemies);
}
