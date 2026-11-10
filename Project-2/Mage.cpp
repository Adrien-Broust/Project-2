#include "Mage.h"
#include "Enemy.h"
#include "Map.h"

int Mage::movePlayer(int map[10][20])
{
	char key = _getch();
	int direction = getDirectionFromKey(key);
	if (key == 'x' || key == 'X')
	{
		return 1;
	}
	if (key == ' ')
	{
		return 2;
	}
	if (direction != -1)
	{
		move(*this, direction, map);
		return 0;
	}
}