#pragma once
class Map
{
public:
	void createMap();
private:
	int longueur = 20;
	int largeur = 10;
	
	enum Terrain
	{
		Sol,
		Montagne,
		Eau,
		Sortie,
	};

};

