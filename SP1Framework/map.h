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


	void orphanage();
	void protest_area();
	void insideAbandonedFacility2();
	void insideAbandonedFacility4();
	void dungeon_cell();
	void dungeon_stealth2();

};

