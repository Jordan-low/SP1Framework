#pragma once

class Map
{
public:
	int i = 0;
	int j = 0;
	char Grid[80][25];
	void initialise();
	void printmap();
	void townsquare();
	void patharea();

	void orphanage();
	void protest_area();
};

