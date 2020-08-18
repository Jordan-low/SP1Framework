#pragma once
class Map
{
private:
	
public:
	int i = 0;
	int j = 0;
	char Grid[80][25];
	void initialise();
	void printmap();
	void townsquare();
	void patharea();
	void insideAbandonedFacility1();
	void insideAbandonedFacility3();
	void insideMedicalFacility();

	char map[27][83];
	void orphanage();
	void protest_area();
	void insideAbandonedFacility2();

};

