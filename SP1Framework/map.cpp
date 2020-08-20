#include "Map.h"
#include <iostream>

using namespace std;

void Map::initialise()
{
	//initialise map
	for (j = 0; j < 25; j++)
	{
		for (i = 0; i < 80; i++)
		{
			(Grid[i][j] = ' ');
		}
	}
}

void Map::printmap(Console& g_Console)
{
	//print first line
	j = 0;
	COORD c; COORD d;
	for (int col = 1; col < 79; col++)
	{
		c.X = col;
		c.Y = 1;
		d.X = col;
		d.Y = 23;
		g_Console.writeToBuffer(c, "#");
		g_Console.writeToBuffer(d, "#");
		for (int row = 1; row < 24; row++)
		{
			c.X = 78;
			c.Y = row;
			d.X = 1;
			d.Y = row;
			g_Console.writeToBuffer(c, "#");
			g_Console.writeToBuffer(d, "#");
		}
		
	}
}

void Map::Border(Console &g_Console)
{
	COORD c; COORD d;
	for (int col = 1; col < 79; col++)
	{
		c.X = col;
		c.Y = 1;
		d.X = col;
		d.Y = 23;
		g_Console.writeToBuffer(c, "#", 0x1A);
		g_Console.writeToBuffer(d, "#", 0x1A);
		for (int row = 1; row < 24; row++)
		{
			c.X = 78;
			c.Y = row;
			d.X = 1;
			d.Y = row;
			g_Console.writeToBuffer(c, "#", 0x1A);
			g_Console.writeToBuffer(d, "#", 0x1A);
		}
	}

}

void Map::House(Console& g_Console, int x, int y)
{
	COORD c;
	int xLoc = x;
	int yLoc = y;
	for (int i = 0; i < 5; i++)
	{
		c.X = xLoc + i;
		c.Y = yLoc;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	for (int i = 0; i < 5; i++)
	{
		c.X = xLoc + i;
		c.Y = yLoc + 2;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	for (int i = 0; i < 1; i++)
	{
		c.X = xLoc + 2;
		c.Y = yLoc + 1;
		g_Console.writeToBuffer(c, "H", 0x1A);
	}
	for (int i = 0; i < 1; i++)
	{
		c.X = xLoc;
		c.Y = yLoc + 1;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	for (int i = 0; i < 1; i++)
	{
		c.X = xLoc + 4;
		c.Y = yLoc + 1;
		g_Console.writeToBuffer(c, "|", 0x1A);
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
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	for (int i = 0; i < 5; i++)
	{
		c.X = xLoc + i;
		c.Y = yLoc + 2;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	for (int i = 0; i < 1; i++)
	{
		c.X = xLoc + 2;
		c.Y = yLoc + 1;
		g_Console.writeToBuffer(c, "O", 0x1A);
	}
	for (int i = 0; i < 1; i++)
	{
		c.X = xLoc;
		c.Y = yLoc + 1;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	for (int i = 0; i < 1; i++)
	{
		c.X = xLoc + 4;
		c.Y = yLoc + 1;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
}

void Map::townsquare(Console &g_Console)
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

	/*
	//doors
	j = 0; for (i = 8; i < 24; i++) { (Grid[i][j] = '@'); }
	j = 0; for (i = 57; i < 73; i++) { (Grid[i][j] = '@'); }
	//road lines
	i = 7; for (int j = 0; j < 21; j++) { (Grid[i][j] = '|'); }i = 72; for (int j = 0; j < 21; j++) { (Grid[i][j] = '|'); }j = 22; for (int i = 7; i < 77; i++) { (Grid[i][j] = '-'); }
	i = 24; for (int j = 0; j < 17; j++) { (Grid[i][j] = '|'); }i = 56; for (int j = 0; j < 17; j++) { (Grid[i][j] = '|'); }j = 17; for (int i = 24; i < 57; i++) { (Grid[i][j] = '-'); }
	//road markings
	i = 15; for (int j = 3; j < 7; j++) { (Grid[i][j] = 'I'); }i = 15; for (int j = 10; j < 14; j++) { (Grid[i][j] = 'I'); }i = 15; for (int j = 17; j < 20; j++) { (Grid[i][j] = 'I'); }
	i = 64; for (int j = 3; j < 7; j++) { (Grid[i][j] = 'I'); }i = 64; for (int j = 10; j < 14; j++) { (Grid[i][j] = 'I'); }i = 64; for (int j = 17; j < 20; j++) { (Grid[i][j] = 'I'); }
	j = 19; for (int i = 17; i < 22; i++) { (Grid[i][j] = '='); }j = 19; for (int i = 30; i < 36; i++) { (Grid[i][j] = '='); }j = 19; for (int i = 44; i < 50; i++) { (Grid[i][j] = '='); }j = 19; for (int i = 58; i < 63; i++) { (Grid[i][j] = '='); }
	//houses on the sides
	j = 1; for (int i = 3; i < 8; i++) { (Grid[i][j] = '-'); }Grid[3][2] = '|'; Grid[4][2] = ' '; Grid[5][2] = 'H'; Grid[6][2] = ' '; Grid[7][2] = '|'; j = 3; for (int i = 3; i < 8; i++) { (Grid[i][j] = '-'); }
	j = 6; for (int i = 3; i < 8; i++) { (Grid[i][j] = '-'); }Grid[3][7] = '|'; Grid[4][7] = ' '; Grid[5][7] = 'H'; Grid[6][7] = ' '; Grid[7][7] = '|'; j = 8; for (int i = 3; i < 8; i++) { (Grid[i][j] = '-'); }
	j = 11; for (int i = 3; i < 8; i++) { (Grid[i][j] = '-'); }Grid[3][12] = '|'; Grid[4][12] = ' '; Grid[5][12] = 'H'; Grid[6][12] = ' '; Grid[7][12] = '|'; j = 13; for (int i = 3; i < 8; i++) { (Grid[i][j] = '-'); }
	j = 16; for (int i = 3; i < 8; i++) { (Grid[i][j] = '-'); }Grid[3][17] = '|'; Grid[4][17] = ' '; Grid[5][17] = 'H'; Grid[6][17] = ' '; Grid[7][17] = '|'; j = 18; for (int i = 3; i < 8; i++) { (Grid[i][j] = '-'); }
	j = 21; for (int i = 3; i < 8; i++) { (Grid[i][j] = '-'); }Grid[3][22] = '|'; Grid[4][22] = ' '; Grid[5][22] = 'H'; Grid[6][22] = ' '; Grid[7][22] = '|'; j = 23; for (int i = 3; i < 8; i++) { (Grid[i][j] = '-'); }
	j = 1; for (int i = 72; i < 77; i++) { (Grid[i][j] = '-'); }Grid[72][2] = '|'; Grid[73][2] = ' '; Grid[74][2] = 'H'; Grid[75][2] = ' '; Grid[76][2] = '|'; j = 3; for (int i = 72; i < 77; i++) { (Grid[i][j] = '-'); }
	j = 6; for (int i = 72; i < 77; i++) { (Grid[i][j] = '-'); }Grid[72][7] = '|'; Grid[73][7] = ' '; Grid[74][7] = 'H'; Grid[75][7] = ' '; Grid[76][7] = '|'; j = 8; for (int i = 72; i < 77; i++) { (Grid[i][j] = '-'); }
	j = 11; for (int i = 72; i < 77; i++) { (Grid[i][j] = '-'); }Grid[72][12] = '|'; Grid[73][12] = ' '; Grid[74][12] = 'H'; Grid[75][12] = ' '; Grid[76][12] = '|'; j = 13; for (int i = 72; i < 77; i++) { (Grid[i][j] = '-'); }
	j = 16; for (int i = 72; i < 77; i++) { (Grid[i][j] = '-'); }Grid[72][17] = '|'; Grid[73][17] = ' '; Grid[74][17] = 'H'; Grid[75][17] = ' '; Grid[76][17] = '|'; j = 18; for (int i = 72; i < 77; i++) { (Grid[i][j] = '-'); }
	j = 21; for (int i = 72; i < 77; i++) { (Grid[i][j] = '-'); }Grid[72][22] = '|'; Grid[73][22] = ' '; Grid[74][22] = 'H'; Grid[75][22] = ' '; Grid[76][22] = '|'; j = 23; for (int i = 72; i < 77; i++) { (Grid[i][j] = '-'); }
	j = 21; for (int i = 54; i < 59; i++) { (Grid[i][j] = '-'); }Grid[54][22] = '|'; Grid[55][22] = ' '; Grid[56][22] = 'H'; Grid[57][22] = ' '; Grid[58][22] = '|'; j = 23; for (int i = 54; i < 59; i++) { (Grid[i][j] = '-'); }
	j = 21; for (int i = 38; i < 43; i++) { (Grid[i][j] = '-'); }Grid[38][22] = '|'; Grid[39][22] = ' '; Grid[40][22] = 'H'; Grid[41][22] = ' '; Grid[42][22] = '|'; j = 23; for (int i = 38; i < 43; i++) { (Grid[i][j] = '-'); }
	//houses in the middle
	j = 1; for (int i = 22; i < 27; i++) { (Grid[i][j] = '-'); }Grid[22][2] = '|'; Grid[23][2] = ' '; Grid[24][2] = 'H'; Grid[25][2] = ' '; Grid[26][2] = '|'; j = 3; for (int i = 22; i < 27; i++) { (Grid[i][j] = '-'); }
	j = 6; for (int i = 22; i < 27; i++) { (Grid[i][j] = '-'); }Grid[22][7] = '|'; Grid[23][7] = ' '; Grid[24][7] = 'H'; Grid[25][7] = ' '; Grid[26][7] = '|'; j = 8; for (int i = 22; i < 27; i++) { (Grid[i][j] = '-'); }
	j = 11; for (int i = 22; i < 27; i++) { (Grid[i][j] = '-'); }Grid[22][12] = '|'; Grid[23][12] = ' '; Grid[24][12] = 'H'; Grid[25][12] = ' '; Grid[26][12] = '|'; j = 13; for (int i = 22; i < 27; i++) { (Grid[i][j] = '-'); }
	j = 1; for (int i = 54; i < 59; i++) { (Grid[i][j] = '-'); }Grid[54][2] = '|'; Grid[55][2] = ' '; Grid[56][2] = 'H'; Grid[57][2] = ' '; Grid[58][2] = '|'; j = 3; for (int i = 54; i < 59; i++) { (Grid[i][j] = '-'); }
	j = 6; for (int i = 54; i < 59; i++) { (Grid[i][j] = '-'); }Grid[54][7] = '|'; Grid[55][7] = ' '; Grid[56][7] = 'H'; Grid[57][7] = ' '; Grid[58][7] = '|'; j = 8; for (int i = 54; i < 59; i++) { (Grid[i][j] = '-'); }
	j = 11; for (int i = 54; i < 59; i++) { (Grid[i][j] = '-'); }Grid[54][12] = '|'; Grid[55][12] = ' '; Grid[56][12] = 'H'; Grid[57][12] = ' '; Grid[58][12] = '|'; j = 13; for (int i = 54; i < 59; i++) { (Grid[i][j] = '-'); }
	//Orphanage
	j = 21; for (int i = 21; i < 26; i++) { (Grid[i][j] = '-'); }Grid[21][22] = '|'; Grid[22][22] = ' '; Grid[23][22] = '�'; Grid[24][22] = ' '; Grid[25][22] = '|'; j = 23; for (int i = 21; i < 26; i++) { (Grid[i][j] = '-'); }
	*/
}

void Map::insideAbandonedFacility3(Console& g_Console)
{
	Border(g_Console);
	//small box
	j = 0; for (i = 30; i < 50; i++) { (Grid[i][j] = '-'); }
	j = 10; for (i = 30; i < 50; i++) { (Grid[i][j] = '-'); }
	j = 10; for (i = 39; i < 42; i++) { (Grid[i][j] = ' '); }
	i = 30; for (j = 1; j < 10; j++) { (Grid[i][j] = '|'); }
	i = 49; for (j = 1; j < 10; j++) { (Grid[i][j] = '|'); }
	i = 38; for (j = 11; j < 25; j++) { (Grid[i][j] = '|'); }
	i = 42; for (j = 11; j < 25; j++) { (Grid[i][j] = '|'); }
	//door
	j = 24; for (i = 39; i < 42; i++) { (Grid[i][j] = '@'); }
}

void Map::insideMedicalFacility(Console& g_Console)
{
	//door
	i = 0; for (int j = 10; j < 15; j++) { (Grid[i][j] = '@'); }
	//beds
	//vertical
	i = 75; for (int j = 0; j < 25; j++) { (Grid[i][j] = '|'); } for (int j = 6; j < 19; j++) { (Grid[i][j] = ' '); }
	i = 65; for (int j = 0; j < 25; j++) { (Grid[i][j] = '|'); } for (int j = 6; j < 19; j++) { (Grid[i][j] = ' '); }
	i = 60; for (int j = 0; j < 25; j++) { (Grid[i][j] = '|'); } for (int j = 6; j < 19; j++) { (Grid[i][j] = ' '); }
	i = 50; for (int j = 0; j < 25; j++) { (Grid[i][j] = '|'); } for (int j = 6; j < 19; j++) { (Grid[i][j] = ' '); }
	i = 45; for (int j = 0; j < 25; j++) { (Grid[i][j] = '|'); } for (int j = 6; j < 19; j++) { (Grid[i][j] = ' '); }
	i = 35; for (int j = 0; j < 25; j++) { (Grid[i][j] = '|'); } for (int j = 6; j < 19; j++) { (Grid[i][j] = ' '); }
	//horizontal
	j = 0; for (i = 35; i < 76; i++) { (Grid[i][j] = '-'); }
	j = 2; for (i = 35; i < 76; i++) { (Grid[i][j] = '-'); }
	j = 6; for (i = 35; i < 76; i++) { (Grid[i][j] = '-'); }
	j = 18; for (i = 35; i < 76; i++) { (Grid[i][j] = '-'); }
	j = 22; for (i = 35; i < 76; i++) { (Grid[i][j] = '-'); }
	j = 24; for (i = 35; i < 76; i++) { (Grid[i][j] = '-'); }
	for (j = 0; j < 25; j++) { for (i = 61; i < 65; i++) { (Grid[i][j] = ' '); } }
	for (j = 0; j < 25; j++) { for (i = 46; i < 50; i++) { (Grid[i][j] = ' '); } }
	//front desk
	i = 20; for (int j = 8; j < 18; j++) { (Grid[i][j] = '|'); }
	i = 23; for (int j = 2; j < 23; j++) { (Grid[i][j] = '|'); }
	for (j = 8; j < 18; j++) { for (i = 21; i < 26; i++) { (Grid[i][j] = ' '); } }
	j = 7; for (i = 20; i < 26; i++) { (Grid[i][j] = '-'); }
	j = 18; for (i = 20; i < 26; i++) { (Grid[i][j] = '-'); }
}

void Map::dungeon_stealth1(Console& g_Console)
{
	//door
	j = 24; for (i = 0; i < 16; i++) { (Grid[i][j] = '@'); }
	//maze generation
	i = 7; for (j = 19; j < 25; j++) { (Grid[i][j] = '|'); }
	j = 18; for (i = 7; i < 25; i++) { (Grid[i][j] = '-'); }
	i = 25; for (j = 12; j < 22; j++) { (Grid[i][j] = '|'); }
	j = 11; for (i = 12; i < 26; i++) { (Grid[i][j] = '-'); }
	j = 16; for (i = 11; i < 25; i++) { (Grid[i][j] = '-'); }
	i = 11; for (j = 5; j < 14; j++) { (Grid[i][j] = '|'); }
	j = 4; for (i = 4; i < 37; i++) { (Grid[i][j] = '-'); }
	i = 4; for (j = 5; j < 12; j++) { (Grid[i][j] = '|'); }
	i = 36; for (j = 5; j < 12; j++) { (Grid[i][j] = '|'); }
	j = 15; for (i = 26; i < 49; i++) { (Grid[i][j] = '-'); }
	i = 48; for (j = 7; j < 15; j++) { (Grid[i][j] = '|'); }
	j = 7; for (i = 48; i < 60; i++) { (Grid[i][j] = '-'); }
	j = 11; for (i = 49; i < 70; i++) { (Grid[i][j] = '-'); }
	i = 69; for (j = 0; j < 11; j++) { (Grid[i][j] = '|'); }
	i = 55; for (j = 4; j < 7; j++) { (Grid[i][j] = '|'); }
	j = 22; for (i = 25; i < 49; i++) { (Grid[i][j] = '-'); }
	i = 48; for (j = 19; j < 22; j++) { (Grid[i][j] = '|'); }
	j = 18; for (i = 48; i < 70; i++) { (Grid[i][j] = '-'); }
	i = 59; for (j = 15; j < 18; j++) { (Grid[i][j] = '|'); }
	j = 14; for (i = 59; i < 75; i++) { (Grid[i][j] = '-'); }
	i = 69; for (j = 19; j < 22; j++) { (Grid[i][j] = '|'); }
	j = 20; for (i = 49; i < 60; i++) { (Grid[i][j] = '-'); }
	//locked door
	j = 15; for (i = 34; i < 41; i++) { (Grid[i][j] = '&'); }
	//barrel locations
	j = 0; Grid[77][j] = '('; Grid[78][j] = 'B'; Grid[79][j] = ')';
	j = 21; Grid[26][j] = '('; Grid[27][j] = 'B'; Grid[28][j] = ')';
	j = 20; Grid[4][j] = '('; Grid[5][j] = 'B'; Grid[6][j] = ')';
	//box locations
	j = 21; Grid[4][j] = '|'; Grid[5][j] = 'B'; Grid[6][j] = '|';
	j = 19; Grid[49][j] = '|'; Grid[50][j] = 'B'; Grid[51][j] = '|';
	j = 6; Grid[56][j] = '|'; Grid[57][j] = 'B'; Grid[58][j] = '|';
}

void Map::dungeon_stealth3(Console& g_Console)
{
	//doors
	j = 24; for (i = 0; i < 6; i++) { (Grid[i][j] = '@'); }
	j = 0; for (i = 60; i < 80; i++) { (Grid[i][j] = '@'); }
	//walls
	j = 20; for (i = 0; i < 60; i++) { (Grid[i][j] = '-'); }
	i = 59; for (j = 0; j < 20; j++) { (Grid[i][j] = '|'); }
	i = 59; for (j = 8; j < 13; j++) { (Grid[i][j] = ' '); }
	//elevator
	j = 2; Grid[4][j] = '|'; Grid[5][j] = 'E'; Grid[6][j] = '|';
	//statue
	j = 9; for (i = 5; i < 15; i++) { (Grid[i][j] = '-'); }
	j = 16; for (i = 5; i < 15; i++) { (Grid[i][j] = '-'); }
	i = 5; for (j = 10; j < 16; j++) { (Grid[i][j] = '|'); }
	i = 14; for (j = 10; j < 16; j++) { (Grid[i][j] = '|'); }
	j = 12; Grid[9][j] = 'O'; Grid[10][j] = 'O';
	j = 13; Grid[9][j] = 'O'; Grid[10][j] = 'O';
}

void Map::orphanage(Console &g_Console)
{
	COORD c; COORD d; COORD e;
	for (int col = 1; col < 79; col++) // border
	{
		c.X = col;
		c.Y = 1;
		d.X = col;
		d.Y = 23;
		g_Console.writeToBuffer(c, "#");
		g_Console.writeToBuffer(d, "#");
		for (int row = 1; row < 24; row++)
		{
			c.X = 78;
			c.Y = row;
			d.X = 1;
			d.Y = row;
			g_Console.writeToBuffer(c, "#");
			g_Console.writeToBuffer(d, "#");
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
		g_Console.writeToBuffer(c, "@");
		g_Console.writeToBuffer(d, "@");
		g_Console.writeToBuffer(e, "@");
	}
	c.X = 2;
	c.Y = 22;
	g_Console.writeToBuffer(c, "/", 0x1A);
	c.X = 3;
	c.Y = 21;
	g_Console.writeToBuffer(c, "/", 0x1A);
	c.X = 4;
	c.Y = 20;
	for (int i = 0; i < 4; i++)
	{
		c.X = 4 + i;
		c.Y = 20;
		g_Console.writeToBuffer(c, "_", 0x1A);
	}
	g_Console.writeToBuffer(c, "/", 0x1A);
	for (int i = 0; i < 5; i++)
	{
		c.X = 8 + i;
		c.Y = 19;
		g_Console.writeToBuffer(c, "_", 0x1A);
	}
	for (int i = 0; i < 2; i++)
	{
		c.X = 13 + i;
		c.Y = 19 - i;
		g_Console.writeToBuffer(c, "/", 0x1A);
	}
	for (int i = 0; i < 6; i++)
	{
		c.X = 15 + i;
		c.Y = 17;
		g_Console.writeToBuffer(c, "_", 0x1A);
	}
	c.X = 21;
	c.Y = 17;
	g_Console.writeToBuffer(c, "/", 0x1A);
	c.X = 22;
	c.Y = 16;
	g_Console.writeToBuffer(c, "/", 0x1A);
	c.X = 23;
	c.Y = 15;
	g_Console.writeToBuffer(c, "/", 0x1A);
	for (int i = 0; i < 10; i++)
	{
		c.X = 24 + i;
		c.Y = 14;
		g_Console.writeToBuffer(c, "_", 0x1A);
	}
	c.X = 34;
	c.Y = 14;
	g_Console.writeToBuffer(c, "/", 0x1A);
	c.X = 35;
	c.Y = 13;
	g_Console.writeToBuffer(c, "/", 0x1A);
	for (int i = 0; i < 15; i++)
	{
		c.X = 36 + i;
		c.Y = 12;
		g_Console.writeToBuffer(c, "_", 0x1A);
	}
	c.X = 51;
	c.Y = 12;
	g_Console.writeToBuffer(c, "/", 0x1A);
	for (int i = 0; i < 7; i++)
	{
		c.X = 52 + i;
		c.Y = 11;
		g_Console.writeToBuffer(c, "_", 0x1A);
	}
	c.X = 59;
	c.Y = 11;
	g_Console.writeToBuffer(c, "/", 0x1A);
	c.X = 60;
	c.Y = 10;
	g_Console.writeToBuffer(c, "/", 0x1A);
	c.X = 61;
	c.Y = 9;
	g_Console.writeToBuffer(c, "/", 0x1A);
	for (int i = 0; i < 15; i++)
	{
		c.X = 62 + i;
		c.Y = 8;
		g_Console.writeToBuffer(c, "_", 0x1A);
	}
	c.X = 77;
	c.Y = 8;
	g_Console.writeToBuffer(c, "/", 0x1A);
}

void Map::protest_area(Console& g_Console)
{
	//doors
	for (i = 69; i <= 79; i++) { Grid[i][0] = '@'; }

	//barrels
	Grid[4][2] = '('; Grid[5][2] = 'B'; Grid[6][2] = ')';
	Grid[7][2] = '('; Grid[8][2] = 'B'; Grid[9][2] = ')';
	Grid[2][3] = '('; Grid[3][3] = 'B'; Grid[4][3] = ')';
	Grid[5][3] = '('; Grid[6][3] = 'B'; Grid[7][3] = ')';
	Grid[8][3] = '('; Grid[9][3] = 'B'; Grid[10][3] = ')';
	Grid[4][4] = '('; Grid[5][4] = 'B'; Grid[6][4] = ')';
	Grid[7][4] = '('; Grid[8][4] = 'B'; Grid[9][4] = ')';

	//Town Hall
	for (i = 17; i <= 61; i++) { Grid[i][2] = '-'; }
	for (j = 3; j <= 5; j++) { Grid[17][j] = '|'; }
	for (j = 3; j <= 5; j++) { Grid[61][j] = '|'; }
	for (i = 17; i <= 61; i++) { Grid[i][6] = '-'; }
	for (j = 7; j <= 9; j++) { Grid[17][j] = '|'; }
	for (j = 7; j <= 9; j++) { Grid[61][j] = '|'; }
	for (i = 18; i <= 60; i++) { Grid[i][9] = '_'; }

	//podium
	Grid[36][9] = '|'; Grid[42][9] = '|';
	for (i = 37; i <= 41; i++) { Grid[i][8] = '_'; }

	//Taco stand
	for (i = 8; i <= 14; i++) { Grid[i][12] = '-'; }
	for (j = 13; j <= 17; j++) { Grid[7][j] = '|'; }
	for (j = 13; j <= 17; j++) { Grid[15][j] = '|'; }
	for (i = 8; i <= 14; i++) { Grid[i][18] = '-'; }
	Grid[9][15] = 'T'; Grid[10][15] = 'a'; Grid[11][15] = 'c'; Grid[12][15] = 'o'; Grid[13][15] = 's';

	//Burger stand
	for (i = 65; i <= 71; i++) { Grid[i][12] = '-'; }
	for (j = 13; j <= 17; j++) { Grid[64][j] = '|'; }
	for (j = 13; j <= 17; j++) { Grid[72][j] = '|'; }
	for (i = 65; i <= 71; i++) { Grid[i][18] = '-'; }
	Grid[65][15] = 'B'; Grid[65][15] = 'B'; Grid[66][15] = 'u'; Grid[67][15] = 'r'; Grid[68][15] = 'g'; Grid[69][15] = 'e'; Grid[70][15] = 'r'; Grid[71][15] = 's';

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
		g_Console.writeToBuffer(c, '@', 0x1A);
	}
	for (j = 17; j <= 20; j++)
	{
		c.X = 58;
		c.Y = j;
		g_Console.writeToBuffer(c, '@', 0x1A);
	}

	//Building
	for (i = 58; i <= 76; i++)
	{
		c.X = i;
		c.Y = 3;
		g_Console.writeToBuffer(c, '-', 0x1A);
	}
	for (j = 4; j <= 16; j++)
	{
		c.X = 58;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (j = 4; j <= 20; j++)
	{
		c.X = 76;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (i = 58; i <= 76; i++)
	{
		c.X = i;
		c.Y = 21;
		g_Console.writeToBuffer(c, '-', 0x1A);
	}

	//camera
	for (i = 40; i <= 41; i++)
	{
		c.X = i;
		c.Y = 3;
		g_Console.writeToBuffer(c, '_', 0x1A);
	}
	c.X = 39;
	c.Y = 4;
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.X = 42;
	c.Y = 4;
	g_Console.writeToBuffer(c, '|', 0x1A);
	for (i = 40; i <= 41; i++)
	{
		c.X = i;
		c.Y = 4;
		g_Console.writeToBuffer(c, '_', 0x1A);
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
		g_Console.writeToBuffer(c, '@', 0x1A);
	}
	for (j = 11; j <= 15; j++)
	{
		c.X = 76;
		c.Y = j;
		g_Console.writeToBuffer(c, '@', 0x1A);
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
			g_Console.writeToBuffer(c, '/', 0x1A);
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
		g_Console.writeToBuffer(c, '@', 0x1A);
	}

	//box thing for defense items
	for (i = 34; i <= 46; i++)
	{
		c.X = i;
		c.Y = 4;
		g_Console.writeToBuffer(c, '-', 0x1A);
	}
	for (j = 5; j <= 7; j++)
	{
		c.X = 34;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (j = 5; j <= 7; j++)
	{
		c.X = 46;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (i = 34; i <= 46; i++)
	{
		c.X = i;
		c.Y = 8;
		g_Console.writeToBuffer(c, '-', 0x1A);
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
		g_Console.writeToBuffer(c, '@', 0x1A);
	}
	
	//cell bars
	for (i = 2; i <= 77; i++) 
	{ 
		c.X = i;
		c.Y = 8;
		g_Console.writeToBuffer(c, '-', 0x1A);
	}

	//locked doors
	for (i = 32; i <= 45; i++) 
	{ 
		c.X = i;
		c.Y = 8;
		g_Console.writeToBuffer(c, '&', 0x1A);
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
		g_Console.writeToBuffer(c, '@', 0x1A);
	}
	for (i = 17; i <= 25; i++)
	{
		c.X = i;
		c.Y = 18;
		g_Console.writeToBuffer(c, '@', 0x1A);
	}

	//walls
	for (j = 6; j <= 22; j++)
	{
		c.X = 9;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (j = 6; j <= 22; j++)
	{
		c.X = 16;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (j = 6; j <= 17; j++)
	{
		c.X = 69;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (i = 9; i <= 69; i++)
	{
		c.X = i;
		c.Y = 5;
		g_Console.writeToBuffer(c, '-', 0x1A);
	}
	for (i = 27; i <= 69; i++)
	{
		c.X = i;
		c.Y = 18;
		g_Console.writeToBuffer(c, '-', 0x1A);
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
		g_Console.writeToBuffer(c, '@', 0x1A);
	}
	
	//long table
	for (i = 26; i <= 54; i++)
	{
		c.X = i;
		c.Y = 4;
		g_Console.writeToBuffer(c, '-', 0x1A);
	}
	for (j = 5; j <= 7; j++)
	{
		c.X = 26;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (j = 5; j <= 7; j++)
	{
		c.X = 54;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (i = 26; i <= 54; i++)
	{
		c.X = i;
		c.Y = 8;
		g_Console.writeToBuffer(c, '-', 0x1A);
	}

	//chairs
	for (i = 31; i <= 35; i++)
	{
		c.X = i;
		c.Y = 9;
		g_Console.writeToBuffer(c, '_', 0x1A);
	}
	for (j = 10; j <= 11; j++)
	{
		c.X = 30;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (j = 10; j <= 11; j++)
	{
		c.X = 36;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (i = 31; i <= 35; i++)
	{
		c.X = i;
		c.Y = 11;
		g_Console.writeToBuffer(c, '_', 0x1A);
	}

	for (i = 45; i <= 49; i++)
	{
		c.X = i;
		c.Y = 9;
		g_Console.writeToBuffer(c, '_', 0x1A);
	}
	for (j = 10; j <= 11; j++)
	{
		c.X = 44;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (j = 10; j <= 11; j++)
	{
		c.X = 50;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (i = 45; i <= 49; i++)
	{
		c.X = i;
		c.Y = 11;
		g_Console.writeToBuffer(c, '_', 0x1A);
	}

	//coffee table
	for (i = 33; i <= 47; i++)
	{
		c.X = i;
		c.Y = 13;
		g_Console.writeToBuffer(c, '-', 0x1A);
	}
	for (j = 14; j <= 15; j++)
	{
		c.X = 33;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (j = 14; j <= 15; j++)
	{
		c.X = 47;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (i = 33; i <= 47; i++)
	{
		c.X = i;
		c.Y = 16;
		g_Console.writeToBuffer(c, '-', 0x1A);
	}
}

void Map::Box(Console& g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, "|", 0x1A);
	c.X = x + 1;
	c.Y = y;
	g_Console.writeToBuffer(c, "B", 0x1A);
	c.X = x + 2;
	c.Y = y;
	g_Console.writeToBuffer(c, "|", 0x1A);
}

void Map::Barrel(Console& g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, "(", 0x1A);
	c.X = x + 1;
	c.Y = y;
	g_Console.writeToBuffer(c, "B", 0x1A);
	c.X = x + 2;
	c.Y = y;
	g_Console.writeToBuffer(c, ")", 0x1A);
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
		g_Console.writeToBuffer(c, "|", 0x1A);
	}

	i = 46;
	for (int j = 2; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}

	j = 10;
	for (int i = 46; i < 78; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}

	j = 15;
	for (int i = 46; i < 78; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}

	i = 46;
	for (int j = 11; j < 15; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, " ", 0x1A);
	}

	//door
	j = 2;
	for (int i = 37; i < 46; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "@", 0x1A);
	}

	j = 22;
	for (int i = 37; i < 46; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "@", 0x1A);
	}
	i = 77;
	for (int j = 11; j < 15; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "@", 0x1A);
	}
}

void Map::insideAbandonedFacility1(Console& g_Console)
{
	COORD c;
	Border(g_Console);
	j = 25; for (int i = 34; i < 44; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "@", 0x1A);
	}

	//generator vertical
	i = 20; for (int j = 2; j < 16; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	i = 59; for (int j = 2; j < 16; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}

	//generator horizontal
	j = 16; for (int i = 20; i < 60; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	j = 2; for (int i = 20; i < 60; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}

	//opening
	j = 16; for (int i = 36; i < 46; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, " ", 0x1A);
	}
	//locked doors
	i = 2; for (int j = 17; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "&", 0x1A);
	}
	i = 77; for (int j = 17; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "&", 0x1A);
	}

	j = 22; for (int i = 36; i < 46; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "&", 0x1A);
	}

	//minigame
	c.Y = 4;
	c.X = 55;
	g_Console.writeToBuffer(c, "|", 0x1A);
	c.X = 56;
	g_Console.writeToBuffer(c, "!", 0x1A);
	c.X = 57;
	g_Console.writeToBuffer(c, "|", 0x1A);

	//Control Room
	c.Y = 7;
	c.X = 32;
	g_Console.writeToBuffer(c, "C", 0x1A);
	c.X = 33;
	g_Console.writeToBuffer(c, "o", 0x1A);
	c.X = 34;
	g_Console.writeToBuffer(c, "n", 0x1A);
	c.X = 35;
	g_Console.writeToBuffer(c, "t", 0x1A);
	c.X = 36;
	g_Console.writeToBuffer(c, "r", 0x1A);
	c.X = 37;
	g_Console.writeToBuffer(c, "o", 0x1A);
	c.X = 38;
	g_Console.writeToBuffer(c, "l", 0x1A);
	c.X = 42;
	g_Console.writeToBuffer(c, "R", 0x1A);
	c.X = 43;
	g_Console.writeToBuffer(c, "o", 0x1A);
	c.X = 44;
	g_Console.writeToBuffer(c, "o", 0x1A);
	c.X = 45;
	g_Console.writeToBuffer(c, "m", 0x1A);


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
		g_Console.writeToBuffer(c, "|", 0x1A);
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
		g_Console.writeToBuffer(c, "_", 0x1A);
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
		g_Console.writeToBuffer(c, "@", 0x1A);
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
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	j = 10; for (i = 30; i < 50; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	j = 10; for (i = 39; i < 42; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, " ", 0x1A);
	}
	i = 30; for (j = 3; j < 10; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	i = 49; for (j = 3; j < 10; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	i = 38; for (j = 11; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	i = 42; for (j = 11; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	//door
	j = 22; for (i = 39; i < 42; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "@", 0x1A);
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
		g_Console.writeToBuffer(c, "@", 0x1A);
	}

	//beds
	//vertical
	i = 75;
	for (int j = 2; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	for (int j = 8; j < 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, " ", 0x1A);
	}
	i = 65;
	for (int j = 2; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	for (int j = 8; j < 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, " ", 0x1A);
	}
	i = 60; for (int j = 2; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	for (int j = 8; j < 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, " ", 0x1A);
	}
	i = 50; for (int j = 2; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	for (int j = 8; j < 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, " ", 0x1A);
	}
	i = 45; for (int j = 2; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	for (int j = 8; j < 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, " ", 0x1A);
	}
	i = 35; for (int j = 2; j < 23; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	for (int j = 8; j < 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, " ", 0x1A);
	}
	//horizontal
	j = 2; for (i = 35; i < 76; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	j = 4; for (i = 35; i < 76; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	j = 8; for (i = 35; i < 76; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	j = 16; for (i = 35; i < 76; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	j = 20; for (i = 35; i < 76; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	j = 22; for (i = 35; i < 76; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	for (j = 2; j < 23; j++)
	{
		for (i = 61; i < 65; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, " ", 0x1A);
		}
	}
	for (j = 2; j < 23; j++)
	{
		for (i = 46; i < 50; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, " ", 0x1A);
		}
	}
	//front desk
	i = 20; for (int j = 8; j < 18; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	i = 23; for (int j = 4; j < 21; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	for (j = 8; j < 18; j++)
	{
		for (i = 21; i < 26; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, " ", 0x1A);
		}
	}
	j = 7; for (i = 20; i < 26; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	j = 18; for (i = 20; i < 26; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
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
		g_Console.writeToBuffer(c, "@", 0x1A);
	}
	j = 2; for (i = 60; i < 78; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "@", 0x1A);
	}
	//walls
	j = 20; for (i = 0; i < 60; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	i = 59; for (j = 2; j < 20; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	i = 59; for (j = 8; j < 13; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, " ", 0x1A);
	}
	//elevator
	c.Y = 2;
	c.X = 4;
	g_Console.writeToBuffer(c, "|", 0x1A);
	c.X = 5;
	g_Console.writeToBuffer(c, "E", 0x1A);
	c.X = 6;
	g_Console.writeToBuffer(c, "|", 0x1A);

	//statue
	j = 9; for (i = 5; i < 15; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	j = 16; for (i = 5; i < 15; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	i = 5; for (j = 10; j < 16; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	i = 14; for (j = 10; j < 16; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	c.Y = 12;
	c.X = 9;
	g_Console.writeToBuffer(c, "O", 0x1A);
	c.X = 10;
	g_Console.writeToBuffer(c, "O", 0x1A);

	c.Y = 13;
	c.X = 9;
	g_Console.writeToBuffer(c, "O", 0x1A);
	c.X = 10;
	g_Console.writeToBuffer(c, "O", 0x1A);
}
//COCKROACH VErY YUMMY
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
		g_Console.writeToBuffer(c, "@", 0x1A);
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
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	i = 17;  for (j = 3; j <= 5; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	i = 61; for (j = 3; j <= 5; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	j = 6;  for (i = 17; i <= 61; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	i = 17; for (j = 7; j <= 9; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	i = 61;  for (j = 7; j <= 9; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	j = 9; for (i = 18; i <= 60; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "_", 0x1A);
	}

	//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	//podium
	c.Y = 9;
	c.X = 36;
	g_Console.writeToBuffer(c, "|", 0x1A);
	c.X = 42;
	g_Console.writeToBuffer(c, "|", 0x1A);

	j = 8; for (i = 37; i <= 41; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "_", 0x1A);
	}

	//Taco stand
	j = 12;  for (i = 8; i <= 14; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	i = 7; for (j = 13; j <= 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	i = 15; for (j = 13; j <= 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	j = 18; for (i = 8; i <= 14; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}

	c.Y = 15;
	c.X = 9;
	g_Console.writeToBuffer(c, "T", 0x1A);
	c.X = 10;
	g_Console.writeToBuffer(c, "a", 0x1A);
	c.X = 11;
	g_Console.writeToBuffer(c, "c", 0x1A);
	c.X = 12;
	g_Console.writeToBuffer(c, "o", 0x1A);
	c.X = 13;
	g_Console.writeToBuffer(c, "s", 0x1A);

	//Burger stand
	j = 12; for (i = 65; i <= 71; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	i = 64; for (j = 13; j <= 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	i = 72; for (j = 13; j <= 17; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "|", 0x1A);
	}
	j = 18; for (i = 65; i <= 71; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, "-", 0x1A);
	}
	c.Y = 15;
	c.X = 65;
	g_Console.writeToBuffer(c, "B", 0x1A);
	c.X = 66;
	g_Console.writeToBuffer(c, "u", 0x1A);
	c.X = 67;
	g_Console.writeToBuffer(c, "r", 0x1A);
	c.X = 68;
	g_Console.writeToBuffer(c, "g", 0x1A);
	c.X = 69;
	g_Console.writeToBuffer(c, "e", 0x1A);
	c.X = 70;
	g_Console.writeToBuffer(c, "r", 0x1A);
	c.X = 71;
	g_Console.writeToBuffer(c, "s", 0x1A);
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