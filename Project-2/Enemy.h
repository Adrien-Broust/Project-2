#pragma once
#include "Entity.h"
class Enemy : public Entity 
{
public:
	void deplacer() override;

	void collision() override;

	virtual void deplacerEnemy() = 0;
private:
	int PV = 1;
	int x;
	int y;

};

