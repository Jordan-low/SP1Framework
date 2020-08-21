#include "Map.h"
#include <iostream>
//j
using namespace std;

void Map::initialise(Console& g_Console)
{
	//initialise map
	COORD c;
	for (j = 0; j < 25; j++)
	{
		for (i = 0; i < 80; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
		}
	}
}

void Map::printmap(Console& g_Console)
{
	//print first line
	COORD c; COORD d; COORD e;
	j = 1;
	for (i = 1; i < 78; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '#', 0x1A);
	}

	for (int j = 2; j < 23; j++)
	{
		c.X = 1;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '#', 0x1A);
		for (i = 2; i < 78; i++)
		{
			d.X = i;
			d.Y = j;
			g_Console.writeToBuffer(d, Grid[d.Y][d.X], 0x1A);
		}
		for (int k = 1; k < 23; k++)
		{
			e.X = 78;
			e.Y = k;
			g_Console.writeToBuffer(e, Grid[e.Y][e.X] = '#', 0x1A);
		}
		
	}
	j = 23;
	for (i = 1; i < 79; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '#', 0x1A);
	}

	/*
	for (i = 1; i < 79; i++)
	{
		c.X = i;
		c.Y = 1;
		d.X = i;
		d.Y = 23;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '#');
		g_Console.writeToBuffer(d, Grid[d.Y][d.X] = '#');
		for (int j = 1; j < 24; j++)
		{
			c.X = 78;
			c.Y = j;
			d.X = 1;
			d.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][78] = '#');
			g_Console.writeToBuffer(d, Grid[d.Y][1] = '#');
		}

	}
	*/
}

void Map::Border(Console& g_Console)
{
	COORD c; COORD d;
	for (i = 1; i < 79; i++)
	{
		c.X = i;
		c.Y = 1;
		d.X = i;
		d.Y = 23;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '#');
		g_Console.writeToBuffer(d, Grid[d.Y][d.X] = '#');
		for (int j = 1; j < 24; j++)
		{
			c.X = 78;
			c.Y = j;
			d.X = 1;
			d.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][78] = '#');
			g_Console.writeToBuffer(d, Grid[d.Y][1] = '#');
		}

	}

}

void Map::Animation(Console &g_Console, int x, int y, char ch)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ch, 0x1A);
	Border(g_Console);
	orphanage(g_Console);
}

void Map::ClearAnimation(Console &g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
}

void Map::Animate(Console& g_Console)
{
	initialise(g_Console);
	orphanage(g_Console);

	Animation(g_Console, 11, 3, '|');
	std::this_thread::sleep_for(std::chrono::milliseconds(300));

	ClearAnimation(g_Console, 11, 3);

	Animation(g_Console, 11, 5, '|');
	std::this_thread::sleep_for(std::chrono::milliseconds(300));

	ClearAnimation(g_Console, 11, 5);

	Animation(g_Console, 11, 7, '|');
	std::this_thread::sleep_for(std::chrono::milliseconds(300));

	ClearAnimation(g_Console, 11, 7);

	Animation(g_Console, 11, 9, '|');
}
void Map::House(Console& g_Console, int x, int y)
{
	COORD c;
	int xLoc = x;
	int yLoc = y;
	for (i = 0; i < 5; i++)
	{
		c.X = xLoc + i;
		c.Y = yLoc;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	for (i = 0; i < 5; i++)
	{
		c.X = xLoc + i;
		c.Y = yLoc + 2;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	for (i = 0; i < 1; i++)
	{
		c.X = xLoc + 2;
		c.Y = yLoc + 1;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'H', 0x1A);
	}
	for (i = 0; i < 1; i++)
	{
		c.X = xLoc;
		c.Y = yLoc + 1;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (i = 0; i < 1; i++)
	{
		c.X = xLoc + 4;
		c.Y = yLoc + 1;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
}

void Map::House2(Console& g_Console, int x, int y)
{
	COORD c;
	int xLoc = x;
	int yLoc = y;
	for (int i = 0; i < 5; i++)
	{
		c.X = xLoc + i;
		c.Y = yLoc;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	for (int i = 0; i < 5; i++)
	{
		c.X = xLoc + i;
		c.Y = yLoc + 2;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	for (int i = 0; i < 1; i++)
	{
		c.X = xLoc + 2;
		c.Y = yLoc + 1;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'O', 0x1A);
	}
	for (int i = 0; i < 1; i++)
	{
		c.X = xLoc;
		c.Y = yLoc + 1;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (int i = 0; i < 1; i++)
	{
		c.X = xLoc + 4;
		c.Y = yLoc + 1;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
}

void Map::townsquare(Console& g_Console)
{
	Border(g_Console);
	House(g_Console, 5, 3);
	House(g_Console, 5, 7);
	House(g_Console, 5, 11);
	House(g_Console, 5, 15);
	House(g_Console, 5, 19);

	House(g_Console, 70, 3);
	House(g_Console, 70, 7);
	House(g_Console, 70, 11);
	House(g_Console, 70, 15);
	House(g_Console, 70, 19);

	House2(g_Console, 20, 19);
	House(g_Console, 35, 19);
	House(g_Console, 50, 19);

	House(g_Console, 5, 3);
	House(g_Console, 5, 7);
	House(g_Console, 5, 11);

	Road(g_Console, 10, 2, 17);
	Road(g_Console, 69, 2, 17);
	Road(g_Console, 24, 2, 13);
	Road(g_Console, 50, 2, 13);

	Road2(g_Console, 11, 18, 58);
	Road2(g_Console, 25, 14, 25);

	Road_I(g_Console, 17, 4, 1);
	Road_I(g_Console, 17, 9, 1);
	Road_I(g_Console, 17, 14, 1);
	Road_I(g_Console, 59, 4, 1);
	Road_I(g_Console, 59, 9, 1);
	Road_I(g_Console, 59, 14, 1);

	Road_Equals(g_Console, 23, 16, 1);
	Road_Equals(g_Console, 38, 16, 1);
	Road_Equals(g_Console, 53, 16, 1);

	Road3(g_Console, 11, 2, 13);
	Road3(g_Console, 51, 2, 18);
}

void Map::orphanage(Console& g_Console)
{
	COORD c; COORD d; COORD e;
	for (int col = 1; col < 79; col++) // border
	{
		c.X = col;
		c.Y = 1;
		d.X = col;
		d.Y = 23;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '#');
		g_Console.writeToBuffer(d, Grid[d.Y][d.X] = '#');
		for (int row = 1; row < 24; row++)
		{
			c.X = 78;
			c.Y = row;
			d.X = 1;
			d.Y = row;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '#');
			g_Console.writeToBuffer(d, Grid[d.Y][d.X] = '#');
		}

	}
	for (int i = 0; i < 2; i++) // door
	{
		c.X = 76;
		c.Y = 2 + i;
		d.X = 76 + i;
		d.Y = 2;
		e.X = 76 + i;
		e.Y = 2 + i;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@');
		g_Console.writeToBuffer(d, Grid[d.Y][d.X] = '@');
		g_Console.writeToBuffer(e, Grid[e.Y][e.X] = '@');
	}
	c.X = 2;
	c.Y = 22;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x1A);
	c.X = 3;
	c.Y = 21;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x1A);
	c.X = 4;
	c.Y = 20;
	for (int i = 0; i < 4; i++)
	{
		c.X = 4 + i;
		c.Y = 20;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x1A);
	for (int i = 0; i < 5; i++)
	{
		c.X = 8 + i;
		c.Y = 19;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}
	for (int i = 0; i < 2; i++)
	{
		c.X = 13 + i;
		c.Y = 19 - i;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x1A);
	}
	for (int i = 0; i < 6; i++)
	{
		c.X = 15 + i;
		c.Y = 17;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}
	c.X = 21;
	c.Y = 17;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x1A);
	c.X = 22;
	c.Y = 16;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x1A);
	c.X = 23;
	c.Y = 15;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x1A);
	for (int i = 0; i < 10; i++)
	{
		c.X = 24 + i;
		c.Y = 14;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}
	c.X = 34;
	c.Y = 14;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x1A);
	c.X = 35;
	c.Y = 13;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x1A);
	for (int i = 0; i < 15; i++)
	{
		c.X = 36 + i;
		c.Y = 12;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}
	c.X = 51;
	c.Y = 12;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x1A);
	for (int i = 0; i < 7; i++)
	{
		c.X = 52 + i;
		c.Y = 11;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}
	c.X = 59;
	c.Y = 11;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x1A);
	c.X = 60;
	c.Y = 10;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x1A);
	c.X = 61;
	c.Y = 9;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x1A);
	for (int i = 0; i < 15; i++)
	{
		c.X = 62 + i;
		c.Y = 8;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}
	c.X = 77;
	c.Y = 8;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x1A);
}


void Map::outside_abandoned_facility(Console& g_Console)
{
	Border(g_Console);
	COORD c;
	//doors
	for (i = 2; i <= 11; i++)
	{
		c.X = i;
		c.Y = 22;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}
	for (j = 17; j <= 20; j++)
	{
		c.X = 58;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}

	//Building
	for (i = 58; i <= 76; i++)
	{
		c.X = i;
		c.Y = 3;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	for (j = 4; j <= 16; j++)
	{
		c.X = 58;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (j = 4; j <= 20; j++)
	{
		c.X = 76;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (i = 58; i <= 76; i++)
	{
		c.X = i;
		c.Y = 21;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}

	//camera
	for (i = 40; i <= 41; i++)
	{
		c.X = i;
		c.Y = 3;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}
	c.X = 39;
	c.Y = 4;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	c.X = 42;
	c.Y = 4;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	for (i = 40; i <= 41; i++)
	{
		c.X = i;
		c.Y = 4;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}
}

void Map::insideAbandonedFacility2(Console& g_Console)
{
	Border(g_Console);
	COORD c;
	//doors
	for (i = 32; i <= 44; i++)
	{
		c.X = i;
		c.Y = 2;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}
	for (j = 11; j <= 15; j++)
	{
		c.X = 76;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}

	//boxes
	Box(g_Console, 3, 3);
	Box(g_Console, 6, 3);
	Box(g_Console, 5, 4);

	Box(g_Console, 3, 21);
	Box(g_Console, 6, 21);
	Box(g_Console, 5, 20);

	//mess
	for (j = 5; j <= 20; j++)
	{
		for (i = 23; i <= 70; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x1A);
		}
	}
}

void Map::insideAbandonedFacility4(Console& g_Console)
{
	Border(g_Console);
	//door
	COORD c;
	for (j = 11; j <= 14; j++)
	{
		c.X = 2;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}

	//box thing for defense items
	for (i = 34; i <= 46; i++)
	{
		c.X = i;
		c.Y = 4;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	for (j = 5; j <= 7; j++)
	{
		c.X = 34;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (j = 5; j <= 7; j++)
	{
		c.X = 46;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (i = 34; i <= 46; i++)
	{
		c.X = i;
		c.Y = 8;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
}

void Map::dungeon_cell(Console& g_Console)
{
	Border(g_Console);
	COORD c;
	//doors
	for (i = 2; i <= 10; i++)
	{
		c.X = i;
		c.Y = 2;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}

	//cell bars
	for (i = 2; i <= 77; i++)
	{
		c.X = i;
		c.Y = 8;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}

	//locked doors
	for (i = 32; i <= 45; i++)
	{
		c.X = i;
		c.Y = 8;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '&', 0x1A);
	}
}

void Map::dungeon_stealth2(Console& g_Console)
{
	Border(g_Console);
	COORD c;
	//doors
	for (i = 2; i <= 8; i++)
	{
		c.X = i;
		c.Y = 22;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}
	for (i = 17; i <= 25; i++)
	{
		c.X = i;
		c.Y = 18;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}

	//walls
	for (j = 6; j <= 22; j++)
	{
		c.X = 9;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (j = 6; j <= 22; j++)
	{
		c.X = 16;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (j = 6; j <= 17; j++)
	{
		c.X = 69;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (i = 9; i <= 69; i++)
	{
		c.X = i;
		c.Y = 5;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	for (i = 27; i <= 69; i++)
	{
		c.X = i;
		c.Y = 18;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
}

void Map::boss_room(Console& g_Console)
{
	Border(g_Console);
	COORD c;
	//doors (elevator)
	for (i = 37; i <= 43; i++)
	{
		c.X = i;
		c.Y = 22;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}

	//long table
	for (i = 26; i <= 54; i++)
	{
		c.X = i;
		c.Y = 4;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	for (j = 5; j <= 7; j++)
	{
		c.X = 26;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (j = 5; j <= 7; j++)
	{
		c.X = 54;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (i = 26; i <= 54; i++)
	{
		c.X = i;
		c.Y = 8;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}

	//chairs
	for (i = 31; i <= 35; i++)
	{
		c.X = i;
		c.Y = 9;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}
	for (j = 10; j <= 11; j++)
	{
		c.X = 30;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (j = 10; j <= 11; j++)
	{
		c.X = 36;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (i = 31; i <= 35; i++)
	{
		c.X = i;
		c.Y = 11;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}

	for (i = 45; i <= 49; i++)
	{
		c.X = i;
		c.Y = 9;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}
	for (j = 10; j <= 11; j++)
	{
		c.X = 44;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (j = 10; j <= 11; j++)
	{
		c.X = 50;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (i = 45; i <= 49; i++)
	{
		c.X = i;
		c.Y = 11;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}

	//coffee table
	for (i = 33; i <= 47; i++)
	{
		c.X = i;
		c.Y = 13;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	for (j = 14; j <= 15; j++)
	{
		c.X = 33;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (j = 14; j <= 15; j++)
	{
		c.X = 47;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (i = 33; i <= 47; i++)
	{
		c.X = i;
		c.Y = 16;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
}

void Map::Box(Console& g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	c.X = x + 1;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'B', 0x1A);
	c.X = x + 2;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
}

void Map::Barrel(Console& g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '(', 0x1A);
	c.X = x + 1;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'B', 0x1A);
	c.X = x + 2;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ')', 0x1A);
}

void Map::patharea(Console& g_Console)
{
	Border(g_Console);
	COORD c;
	//path lines

	i = 36;
	for (int j = 2; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}

	i = 46;
	for (int j = 2; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}

	j = 10;
	for (int i = 46; i < 78; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}

	j = 15;
	for (int i = 46; i < 78; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-' , 0x1A);
	}

	i = 46;
	for (int j = 11; j < 15; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
	}

	//door
	j = 2;
	for (int i = 37; i < 46; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}
	j = 22;
	for (int i = 37; i < 46; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}
	i = 77;
	for (int j = 11; j < 15; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}
}

void Map::insideAbandonedFacility1(Console& g_Console)
{
	COORD c;
	Border(g_Console);
	j = 22;
	for (int i = 36; i < 46; i++)
	{
		c.X = i;
		c.Y = j;
		//g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}

	//generator vertical
	i = 20; 
	for (int j = 2; j < 16; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	i = 59; 
	for (int j = 2; j < 16; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}

	//generator horizontal
	j = 16; 
	for (int i = 20; i < 60; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	j = 2; 
	for (int i = 20; i < 60; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}

	//opening
	j = 16; 
	for (int i = 36; i < 46; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
	}
	//locked doors
	i = 2; for (int j = 17; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '&', 0x1A);
	}
	i = 77; for (int j = 17; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '&', 0x1A);
	}
	/*
	j = 22; for (int i = 36; i < 46; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '&', 0x1A);
	}
	*/

	//minigame
	c.Y = 4;
	c.X = 55;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	c.X = 56;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '!', 0x1A);
	c.X = 57;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);

	//Control Room
	c.Y = 7;
	c.X = 32;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'C', 0x1A);
	c.X = 33;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'o', 0x1A);
	c.X = 34;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'n', 0x1A);
	c.X = 35;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 't', 0x1A);
	c.X = 36;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'r', 0x1A);
	c.X = 37;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'o', 0x1A);
	c.X = 38;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'l', 0x1A);
	c.X = 42;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'R', 0x1A);
	c.X = 43;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'o', 0x1A);
	c.X = 44;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'o', 0x1A);
	c.X = 45;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'm', 0x1A);


	//barrel locations
	//left side
	Box(g_Console, 2, 2);
	Box(g_Console, 8, 3);
	Box(g_Console, 3, 6);
	Box(g_Console, 17, 2);
	Box(g_Console, 17, 7);
	//right side
	Box(g_Console, 75, 2);
	Box(g_Console, 61, 3);
	Box(g_Console, 62, 6);
	Box(g_Console, 66, 5);
	Box(g_Console, 75, 9);
	Box(g_Console, 66, 13);
}

void Map::Road(Console& g_Console, int x, int y, int count)
{
	COORD c;
	int counts = count;
	int xLoc = x;
	int yLoc = y;
	for (int i = 0; i < count; i++)
	{
		c.X = xLoc;
		c.Y = yLoc + i;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
}

void Map::Road2(Console& g_Console, int x, int y, int count)
{
	COORD c;
	int counts = count;
	int xLoc = x;
	int yLoc = y;
	for (int i = 0; i < count; i++)
	{
		c.X = xLoc + i;
		c.Y = yLoc;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}
}


void Map::Road3(Console& g_Console, int x, int y, int count)
{
	COORD c;
	int counts = count;
	int xLoc = x;
	int yLoc = y;
	for (int i = 0; i < count; i++)
	{
		c.X = xLoc + i;
		c.Y = yLoc;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}
}

void Map::Road_I(Console& g_Console, int x, int y, int count)
{
	COORD c;
	int counts = count;
	int xLoc = x;
	int yLoc = y;
	for (int i = 0; i < count; i++)
	{
		c.X = xLoc;
		c.Y = yLoc + 1;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'I', 0x1A);
	}
}

void Map::Road_Equals(Console& g_Console, int x, int y, int count)
{
	COORD c;
	int counts = count;
	int xLoc = x;
	int yLoc = y;
	for (int i = 0; i < count; i++)
	{
		c.X = xLoc + 1;
		c.Y = yLoc;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '=', 0x1A);
	}
}
void Map::insideAbandonedFacility3(Console& g_Console)
{
	Border(g_Console);
	COORD c;
	//small box
	j = 2; for (i = 30; i < 50; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	j = 10; for (i = 30; i < 50; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	j = 10; for (i = 39; i < 42; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
	}
	i = 30; for (j = 3; j < 10; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	i = 49; for (j = 3; j < 10; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	i = 38; for (j = 11; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	i = 42; for (j = 11; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	//door
	j = 22; for (i = 39; i < 42; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}
}

void Map::insideMedicalFacility(Console& g_Console)
{
	Border(g_Console);
	COORD c;
	//door
	i = 2; for (int j = 10; j < 15; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}

	//beds
	//vertical
	i = 75;
	for (int j = 2; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (int j = 8; j < 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
	}
	i = 65;
	for (int j = 2; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (int j = 8; j < 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
	}
	i = 60; for (int j = 2; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (int j = 8; j < 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
	}
	i = 50; for (int j = 2; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (int j = 8; j < 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
	}
	i = 45; for (int j = 2; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (int j = 8; j < 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
	}
	i = 35; for (int j = 2; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (int j = 8; j < 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
	}
	//horizontal
	j = 2; for (i = 35; i < 76; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	j = 4; for (i = 35; i < 76; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	j = 8; for (i = 35; i < 76; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	j = 16; for (i = 35; i < 76; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	j = 20; for (i = 35; i < 76; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	j = 22; for (i = 35; i < 76; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	for (j = 2; j < 23; j++)
	{
		for (i = 61; i < 65; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
		}
	}
	for (j = 2; j < 23; j++)
	{
		for (i = 46; i < 50; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
		}
	}
	//front desk
	i = 20; for (int j = 8; j < 18; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	i = 23; for (int j = 4; j < 21; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	for (j = 8; j < 18; j++)
	{
		for (i = 21; i < 26; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
		}
	}
	j = 7; for (i = 20; i < 26; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	j = 18; for (i = 20; i < 26; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
}

void Map::dungeon_stealth3(Console& g_Console)
{
	COORD c;
	Border(g_Console);
	//doors
	j = 22; for (i = 2; i < 8; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}
	j = 2; for (i = 60; i < 78; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}
	//walls
	j = 20; for (i = 0; i < 60; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	i = 59; for (j = 2; j < 20; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	i = 59; for (j = 8; j < 13; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
	}
	//elevator
	c.Y = 2;
	c.X = 4;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	c.X = 5;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'E', 0x1A);
	c.X = 6;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);

	//statue
	j = 9; for (i = 5; i < 15; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	j = 16; for (i = 5; i < 15; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	i = 5; for (j = 10; j < 16; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	i = 14; for (j = 10; j < 16; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	c.Y = 12;
	c.X = 9;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'O', 0x1A);
	c.X = 10;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'O', 0x1A);

	c.Y = 13;
	c.X = 9;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'O', 0x1A);
	c.X = 10;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'O', 0x1A);
}

//AAAAAAAAAAAA cockroach yummy
void Map::protest_area(Console& g_Console)
{
	COORD c;
	Border(g_Console);
	//doors
	j = 2;
	for (i = 67; i <= 77; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '@', 0x1A);
	}

	//barrels
	Barrel(g_Console, 4, 2);
	Barrel(g_Console, 7, 2);
	Barrel(g_Console, 2, 3);
	Barrel(g_Console, 5, 3);
	Barrel(g_Console, 8, 3);
	Barrel(g_Console, 4, 4);
	Barrel(g_Console, 7, 4);

	//Town Hall
	j = 2;  for (i = 17; i <= 61; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	i = 17;  for (j = 3; j <= 5; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	i = 61; for (j = 3; j <= 5; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	j = 6;  for (i = 17; i <= 61; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	i = 17; for (j = 7; j <= 9; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	i = 61;  for (j = 7; j <= 9; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	j = 9; for (i = 18; i <= 60; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}

	//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	//podium
	c.Y = 9;
	c.X = 36;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	c.X = 42;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);

	j = 8; for (i = 37; i <= 41; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x1A);
	}

	//Taco stand
	j = 12;  for (i = 8; i <= 14; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	i = 7; for (j = 13; j <= 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	i = 15; for (j = 13; j <= 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	j = 18; for (i = 8; i <= 14; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}

	c.Y = 15;
	c.X = 9;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'T', 0x1A);
	c.X = 10;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'a', 0x1A);
	c.X = 11;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'c', 0x1A);
	c.X = 12;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'o', 0x1A);
	c.X = 13;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 's', 0x1A);

	//Burger stand
	j = 12; for (i = 65; i <= 71; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	i = 64; for (j = 13; j <= 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	i = 72; for (j = 13; j <= 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x1A);
	}
	j = 18; for (i = 65; i <= 71; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x1A);
	}
	c.Y = 15;
	c.X = 65;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'B', 0x1A);
	c.X = 66;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'u', 0x1A);
	c.X = 67;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'r', 0x1A);
	c.X = 68;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'g', 0x1A);
	c.X = 69;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'e', 0x1A);
	c.X = 70;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'r', 0x1A);
	c.X = 71;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 's', 0x1A);
}

void Map::dungeon_stealth1(Console& g_Console)
{
	COORD c;
	Border(g_Console);
	Road(g_Console, 10, 18, 5);
	Road2(g_Console, 11, 17, 10);

	Road(g_Console, 21, 12, 8);
	Road2(g_Console, 22, 19, 18);
	Road2(g_Console, 12, 15, 9);
	Road(g_Console, 39, 17, 3);
	Road2(g_Console, 40, 16, 20);
	Road(g_Console, 50, 15, 2);
	Road2(g_Console, 51, 14, 15);
	Road(g_Console, 60, 17, 3);
	Road2(g_Console, 40, 18, 8);

	Road2(g_Console, 12, 11, 9);
	Road(g_Console, 12, 6, 8);

	Road(g_Console, 8, 7, 5);
	Road2(g_Console, 9, 6, 25);

	Road(g_Console, 34, 7, 5);

	Road2(g_Console, 22, 14, 20);
	Road(g_Console, 42, 9, 6);

	Road2(g_Console, 43, 8, 10);
	Road(g_Console, 48, 6, 3);

	Road2(g_Console, 43, 11, 20);
	Road(g_Console, 63, 2, 10);

	Box(g_Console, 49, 7);
	Box(g_Console, 40, 17);
	Barrel(g_Console, 22, 18);

	Box(g_Console, 7, 19);
	Barrel(g_Console, 7, 20);
	Barrel(g_Console, 75, 2);

	c.X = 27;
	c.Y = 14;
	g_Console.writeToBuffer(c, "&&&&&&&&&", 0x1A);

	Road3(g_Console, 2, 22, 8);
	Road3(g_Console, 11, 22, 8);
}