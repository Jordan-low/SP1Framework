#pragma once
#include "Framework\console.h"
class Map
{

public:
	int i = 0;
	int j = 0;
	char Grid[80][25];
	bool IsActive;
	void initialise();
	void printmap(Console &g_Cosole);
	void townsquare();
	void patharea();
	void insideAbandonedFacility1();
	void insideAbandonedFacility3();
	void insideMedicalFacility();
	void dungeon_stealth1();
	void dungeon_stealth3();

	void orphanage();
	void protest_area();
	void outside_abandoned_facility();
	void insideAbandonedFacility2();
	void insideAbandonedFacility4();
	void dungeon_cell();
	void dungeon_stealth2();
	void boss_room();

};

