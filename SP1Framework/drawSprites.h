#pragma once
#include "Map.h"
#include "Framework\console.h"

class drawSprites :
    public Map
{
public:
	void drawGuard(Console& g_Console, int k);
	void drawRobert(Console& g_Console, int k);
	void Battle_Wasp(Console& g_Console, int k);
	void Battle_Raymond(Console& g_Console, int k);
	void pig(Console& g_Console, int k);
};

