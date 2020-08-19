#pragma once
#include "Framework\console.h"
class Map
{
	//aaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbb
public:
	int i = 0;
	int j = 0;
	char Grid[80][25];
	bool IsActive;
	void initialise();
	void printmap(Console &g_Console);
	void townsquare(Console &g_Console);
	void patharea(Console& g_Console);
	void insideAbandonedFacility1(Console& g_Console);
	void insideAbandonedFacility3(Console& g_Console);
	void insideMedicalFacility(Console& g_Console);
	void dungeon_stealth1(Console& g_Console);
	void dungeon_stealth3(Console& g_Console);

	void orphanage(Console &g_Console);
	void protest_area(Console& g_Console);
	void outside_abandoned_facility(Console& g_Console);
	void insideAbandonedFacility2(Console& g_Console);
	void insideAbandonedFacility4(Console& g_Console);
	void dungeon_cell(Console& g_Console);
	void dungeon_stealth2(Console& g_Console);
	void boss_room(Console& g_Console);

	void Border(Console &g_Console);
	void House(Console& g_Console, int x, int y);
	void House2(Console& g_Console, int x, int y);
	void Road(Console& g_Console, int x, int y, int count);
	void Road2(Console& g_Console, int x, int y, int count);
	void Road3(Console& g_Console, int x, int y, int count);


	void Box(Console& g_Console, int x, int y);

	void Barrel(Console& g_Console, int x, int y);

};

