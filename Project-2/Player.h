#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	void deplacer() override;

	void collision() override;

	virtual void deplacerPlayer() = 0;
private:
	int x;
	int y;

};

