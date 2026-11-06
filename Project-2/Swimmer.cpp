#include "Swimmer.h"
#include "Map.h"
#include "Enemy.h"

//bool Swimmer::isTerrainAccessible(int x, int y, int map[10][20])
//{
//	return map[y][x] != Map::Montagne;
//}
//
//void Swimmer::drowning(int x, int y, int map[10][20], Enemy& character)
//{
//	if (map[y][x] == Map::Eau)
//	{
//		o2 -= 1;
//		if (o2 == 0)
//		{
//			character.hp -= 1;
//		}
//	}
//	else
//	{
//		if (o2 < o2max)
//		{
//			o2 += 1;
//		}
//	}
//}
//
//int Swimmer::move(Enemy& character, int dir, int map[10][20])
//{
//	int newX = character.pos.x;
//	int newY = character.pos.y;
//
//	switch (dir)
//	{
//	case 0: newY--; break;
//	case 1: newY++; break;
//	case 2: newX--; break;
//	case 3: newX++; break;
//	default: return 0;
//	}
//
//	if (!isPositionValid(newX, newY))
//	{
//		return 2;
//	}
//
//	if (!isTerrainAccessible(newX, newY, map))
//	{
//		return 2;
//	}
//
//	drowning(newX, newY, map, character);
//
//	character.pos.x = newX;
//	character.pos.y = newY;
//}