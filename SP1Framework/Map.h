#pragma once
#include "Framework\console.h"
#include <chrono>
#include <thread>
class Map
{
public:
	int i = 0;
	int j = 0;
	int k;
	char Grid[30][80];

	void initialise(Console& g_Console);
	void printmap(Console& g_Console);

	//Functions to make our lives easier
	void orphanageDoor(Console& g_Console);
	void drawChildren(Console& g_Console);
	void House(Console& g_Console, int x, int y);
	void House2(Console& g_Console, int x, int y);
	void Road(Console& g_Console, int x, int y, int count);
	void Road2(Console& g_Console, int x, int y, int count);
	void Road3(Console& g_Console, int x, int y, int count);
	void Road_I(Console& g_Console, int x, int y, int count);
	void Road_Equals(Console& g_Console, int x, int y, int count);
	void Animation(Console& g_Console, int x, int y, char ch);
	void drawAnimation(Console& g_Console, int x, int y, char ch);

	//Drawings of Boxes and Barrels
	void Box(Console& g_Console, int x, int y);
	void Barrel(Console& g_Console, int x, int y);

	//Border of Map Drawings
	void Border(Console& g_Console);

	//Battle Map Drawing
	void Battle_Screen(Console& g_Console);

	//Map Area Drawings
	void orphanage(Console& g_Console);
	void townsquare(Console& g_Console);
	void protest_area(Console& g_Console);
	void patharea(Console& g_Console);
	void outside_abandoned_facility(Console& g_Console);
	void insideAbandonedFacility1(Console& g_Console);
	void insideAbandonedFacility2(Console& g_Console);
	void insideAbandonedFacility3(Console& g_Console);
	void insideAbandonedFacility4(Console& g_Console);
	void insideMedicalFacility(Console& g_Console);
	void dungeon_cell(Console& g_Console);
	void dungeon_stealth1(Console& g_Console);
	void dungeon_stealth2(Console& g_Console);
	void dungeon_stealth3(Console& g_Console);
	void boss_room(Console& g_Console);
};

