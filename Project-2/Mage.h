#pragma once
#include "Player.h"
class Mage : public Player
{
public:
	virtual vector2 getDirection() override; // getch
	void Spell();

	Mage()
	{
		pv = 1;
	}
};
