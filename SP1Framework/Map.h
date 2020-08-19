#pragma once
#include "Framework\console.h"
class Map
{
	//aaaaaaaaaaaaaaaaaaa
public:
	int i = 0;
	int j = 0;
	char Grid[80][25];
	bool IsActive;
	void initialise();
	void printmap(Console &g_Console);
	void townsquare(Console &g_Console);
	void patharea();
	void insideAbandonedFacility1();
	void insideAbandonedFacility3();
	void insideMedicalFacility();
	void dungeon_stealth1();
	void dungeon_stealth3();

	void orphanage(Console &g_Console);
	void protest_area();
	void outside_abandoned_facility();
	void insideAbandonedFacility2();
	void insideAbandonedFacility4();
	void dungeon_cell();
	void dungeon_stealth2();
	void boss_room();

	void Border(Console &g_Console);

};

