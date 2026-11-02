#pragma once
class Map
{
public:
	void createMap();
private:
	static const int longueur = 20;
	static const int largeur = 10;
	int dataMap[longueur][largeur];
	
	enum Terrains
	{
		Sol,
		Montagne,
		Eau,
		Sortie,
	};

};

