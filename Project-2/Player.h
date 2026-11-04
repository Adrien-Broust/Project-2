#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	void movePlayer(vector2& character, int map[10][20]);
	vector2 getXplayer();
	vector2 getYplayer();
private:
	vector2 posPlayer;
};

