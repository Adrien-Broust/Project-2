#pragma once
class Entity
{
public:
	virtual void deplacer() = 0;

	virtual void collision() = 0;

	virtual ~Entity() = default;

};

