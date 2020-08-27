#include "drawSprites.h"

void drawSprites::drawGuard(Console& g_Console, int k)
{
	Battle_Screen(g_Console);
	drawRobert(g_Console, 0);
	//head
	Road2(g_Console, 56 + k, 3, 7);
	Road2(g_Console, 56 + k, 6, 7);
	Road2(g_Console, 54 + k, 2, 12);
	Road(g_Console, 55 + k, 4, 3);
	Road(g_Console, 63 + k, 4, 3);

	//helmet
	COORD c;
	c.Y = 4;
	c.X = 54 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 5;
	c.X = 53 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 3;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	for (int i = 0; i < 2; i++)
	{
		c.Y = 4 + i;
		c.X = 52 + k;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	}
	c.Y = 3;
	c.X = 65 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 4;
	c.X = 64 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);

	//left hand
	Road(g_Console, 57 + k, 7, 2);
	Road(g_Console, 61 + k, 7, 2);
	Road2(g_Console, 52 + k, 8, 5);
	Road(g_Console, 51 + k, 9, 2);
	Road2(g_Console, 52 + k, 10, 5);

	//right hand
	Road2(g_Console, 62 + k, 8, 5);
	Road(g_Console, 67 + k, 9, 2);
	Road2(g_Console, 62 + k, 10, 5);

	//left leg
	Road(g_Console, 57 + k, 11, 3);
	c.Y = 14;
	c.X = 56 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 15;
	c.X = 55 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);

	//right leg
	Road(g_Console, 61 + k, 11, 3);
	Road2(g_Console, 56 + k, 15, 3);
	Road2(g_Console, 62 + k, 15, 3);
	c.Y = 14;
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 15;
	c.X = 64 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 14;
	c.X = 59 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 14;
	c.X = 60 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);

	c.Y = 15;
	c.X = 58 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 15;
	c.X = 61 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);

	//eyes
	c.Y = 5;
	c.X = 57 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'O', 0x0A);
	c.Y = 5;
	c.X = 61 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'O', 0x0A);
	c.Y = 4;
	c.X = 58 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 4;
	c.X = 60 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 5;
	c.X = 59 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '<', 0x0A);

	//sword
	//right side
	c.Y = 8;
	c.X = 51 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 7;
	c.X = 50 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);

	c.Y = 10;
	c.X = 50 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 9;
	c.X = 49 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 6;
	c.X = 50 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 5;
	c.X = 50 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 5;
	c.X = 49 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 5;
	c.X = 48 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 4;
	c.X = 47 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 3;
	c.X = 46 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);

	//tip of sword
	c.Y = 2;
	c.X = 43 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 2;
	c.X = 45 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);

	// left side
	c.Y = 9;
	c.X = 48 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 9;
	c.X = 47 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 8;
	c.X = 47 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 7;
	c.X = 47 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 6;
	c.X = 46 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 5;
	c.X = 45 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 4;
	c.X = 44 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 3;
	c.X = 43 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
}


void drawSprites::drawRobert(Console& g_Console, int k)
{
	Road2(g_Console, 12 + k, 3, 6);
	Road2(g_Console, 11 + k, 6, 7);
	Road(g_Console, 11 + k, 4, 3);
	Road(g_Console, 18 + k, 4, 3);
	COORD c;
	c.Y = 6;
	c.X = 12 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 6;
	c.X = 17 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 7;
	c.X = 13 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 8;
	c.X = 12 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 9;
	c.X = 11 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 10;
	c.X = 11 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 10;
	c.X = 12 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 9;
	c.X = 13 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 10;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.Y = 11;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.Y = 12;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);

	//eyes
	c.Y = 5;
	c.X = 16 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'O', 0x0A);
	c.Y = 5;
	c.X = 13 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'O', 0x0A);
	c.Y = 4;
	c.X = 13 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 4;
	c.X = 16 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);

	//left legs
	c.Y = 13;
	c.X = 12 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 14;
	c.X = 11 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 14;
	c.X = 12 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.Y = 14;
	c.X = 13 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.Y = 13;
	c.X = 14 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.Y = 14;
	c.X = 14 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);

	//right body
	c.Y = 7;
	c.X = 16 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 8;
	c.X = 17 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 9;
	c.X = 18 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 10;
	c.X = 18 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 10;
	c.X = 17 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 9;
	c.X = 16 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 10;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.Y = 11;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.Y = 12;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);

	//right leg
	c.Y = 13;
	c.X = 17 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 14;
	c.X = 18 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 14;
	c.X = 17 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.Y = 14;
	c.X = 16 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.Y = 13;
	c.X = 15 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.Y = 14;
	c.X = 15 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);

	c.Y = 12;
	c.X = 14 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.Y = 12;
	c.X = 15 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
}

void drawSprites::Tutorial_Wasp(Console& g_Console, int k)
{
	Battle_Screen(g_Console);
	COORD c;
	//head
	Road2(g_Console, 56 + k, 3, 7);
	Road(g_Console, 55 + k, 4, 3);
	Road(g_Console, 63 + k, 4, 3);
	Road2(g_Console, 56 + k, 6, 7);

	//Left eye
	c.Y = 5;
	c.X = 57 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);

	//right eye
	c.Y = 5;
	c.X = 61 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	
	//Mouth
	c.Y = 6;
	c.X = 59 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'V', 0x0A);

	//feelers
	c.X = 57 + k;
	c.Y = 3;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 61 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	Road2(g_Console, 54 + k, 2, 3);
	c.X = 53 + k;
	c.Y = 3;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 4;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	Road2(g_Console, 62 + k, 2, 3);
	c.X = 65 + k;
	c.Y = 3;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 4;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);

	//body middle
	Road(g_Console, 55 + k, 8, 1);
	Road(g_Console, 63 + k, 8, 1);
	Road2(g_Console, 56 + k, 8, 7);
	c.X = 55 + k;
	c.Y = 7;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 55 + k;
	c.Y = 9;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 56 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 62 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);

	//body end
	c.X = 55 + k;
	c.Y = 10;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	Road(g_Console, 55 + k, 11, 1);
	Road(g_Console, 63 + k, 11, 1);
	Road2(g_Console, 56 + k, 10, 7);
	Road2(g_Console, 56 + k, 11, 7);
	c.X = 55 + k;
	c.Y = 12;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 56 + k;
	c.Y = 13;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 62 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	Road2(g_Console, 57 + k, 13, 5);
	// stinger

	c.Y = 14;
	c.X = 58 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 60 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 59 + k;
	c.Y = 15;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'V', 0x0A);

	//mandibles
	c.X = 57 + k;
	c.Y = 7;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 61 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 58 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 60 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);

	//Left leg 1
	c.X = 54 + k;
	c.Y = 7;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	Road2(g_Console, 50 + k, 6, 4);

	//Right leg 1
	c.X = 64 + k;
	c.Y = 7;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	Road2(g_Console, 65 + k, 6, 4);

	//Left leg 2
	c.X = 54 + k;
	c.Y = 9;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 53 + k;
	c.Y = 8;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 52 + k;
	c.Y = 8;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 51 + k;
	c.Y = 7;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 50 + k;
	c.Y = 8;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	Road2(g_Console, 48 + k, 8, 2);

	//Right leg 2
	c.X = 64 + k;
	c.Y = 9;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 65 + k;
	c.Y = 8;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 66 + k;
	c.Y = 8;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 67 + k;
	c.Y = 7;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 68 + k;
	c.Y = 8;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	Road2(g_Console, 69 + k, 8, 2);

	//Left leg 3
	Road2(g_Console, 53 + k, 10, 2);
	c.X = 52 + k;
	c.Y = 11;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 51 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 50 + k;
	c.Y = 12;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 13;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.Y = 14;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	//Right leg 3
	Road2(g_Console, 64 + k, 10, 2);
	c.X = 66 + k;
	c.Y = 11;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 67 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 68 + k;
	c.Y = 12;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 68 + k;
	c.Y = 13;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 68 + k;
	c.Y = 14;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
}

void drawSprites::Battle_Wasp(Console& g_Console, int k)
{
	Battle_Screen(g_Console);
	drawRobert(g_Console, 0);
	COORD c;
	//head
	Road2(g_Console, 56 + k, 3, 7);
	Road(g_Console, 55 + k, 4, 3);
	Road(g_Console, 63 + k, 4, 3);
	Road2(g_Console, 56 + k, 6, 7);

	//Left eye
	c.X = 56 + k;
	c.Y = 5;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 57 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 56 + k;
	c.Y = 4;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);

	//right eye
	c.X = 62 + k;
	c.Y = 5;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 61 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 62 + k;
	c.Y = 4;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);

	//feelers
	c.X = 57 + k;
	c.Y = 3;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 61 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	Road2(g_Console, 54 + k, 2, 3);
	c.X = 53 + k;
	c.Y = 3;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 4;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	Road2(g_Console, 62 + k, 2, 3);
	c.X = 65 + k;
	c.Y = 3;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 4;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);

	//body middle
	Road(g_Console, 55 + k, 8, 1);
	Road(g_Console, 63 + k, 8, 1);
	Road2(g_Console, 56 + k, 8, 7);
	c.X = 55 + k;
	c.Y = 7;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 55 + k;
	c.Y = 9;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 56 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 62 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);

	//body end
	c.X = 55 + k;
	c.Y = 10;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	Road(g_Console, 55 + k, 11, 1);
	Road(g_Console, 63 + k, 11, 1);
	Road2(g_Console, 56 + k, 10, 7);
	Road2(g_Console, 56 + k, 11, 7);
	c.X = 55 + k;
	c.Y = 12;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 56 + k;
	c.Y = 13;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 62 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	Road2(g_Console, 57 + k, 13, 5);
	// stinger

	c.Y = 14;
	c.X = 58 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 60 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 59 + k;
	c.Y = 15;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'V', 0x0A);

	//mandibles
	c.X = 57 + k;
	c.Y = 7;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 61 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 58 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 60 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);

	//Left leg 1
	c.X = 54 + k;
	c.Y = 7;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	Road2(g_Console, 50 + k, 6, 4);

	//Right leg 1
	c.X = 64 + k;
	c.Y = 7;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	Road2(g_Console, 65 + k, 6, 4);

	//Left leg 2
	c.X = 54 + k;
	c.Y = 9;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 53 + k;
	c.Y = 8;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 52 + k;
	c.Y = 8;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 51 + k;
	c.Y = 7;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 50 + k;
	c.Y = 8;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	Road2(g_Console, 48 + k, 8, 2);

	//Right leg 2
	c.X = 64 + k;
	c.Y = 9;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 65 + k;
	c.Y = 8;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 66 + k;
	c.Y = 8;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 67 + k;
	c.Y = 7;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 68 + k;
	c.Y = 8;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	Road2(g_Console, 69 + k, 8, 2);

	//Left leg 3
	Road2(g_Console, 53 + k, 10, 2);
	c.X = 52 + k;
	c.Y = 11;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 51 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 50 + k;
	c.Y = 12;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.Y = 13;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.Y = 14;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	//Right leg 3
	Road2(g_Console, 64 + k, 10, 2);
	c.X = 66 + k;
	c.Y = 11;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 67 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 68 + k;
	c.Y = 12;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 68 + k;
	c.Y = 13;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 68 + k;
	c.Y = 14;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
}


void drawSprites::Battle_Raymond(Console& g_Console, int k)
{
	Battle_Screen(g_Console);
	COORD c;

	//face shape
	Road(g_Console, 55 + k, 5, 1);
	Road(g_Console, 63 + k, 5, 1);
	Road2(g_Console, 57 + k, 6, 5);
	c.X = 56 + k;
	c.Y = 6;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 62 + k;
	c.Y = 6;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	//glasses
	Road2(g_Console, 56 + k, 5, 2);
	Road(g_Console, 58 + k, 5, 1);
	c.Y = 5;
	c.X = 59 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0A);
	Road(g_Console, 60 + k, 5, 1);
	Road2(g_Console, 61 + k, 5, 2);
	Road2(g_Console, 56 + k, 4, 2);
	Road2(g_Console, 61 + k, 4, 2);
	//hair + ear things
	c.X = 56 + k;
	c.Y = 4;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 57 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0A);
	c.X = 58 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 59 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 60 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 61 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0A);
	c.X = 62 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	Road2(g_Console, 57 + k, 2, 5);
	c.Y = 2;
	c.X = 55 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 56 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 62 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 3;
	c.X = 54 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 64 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.Y = 4;
	c.X = 54 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 64 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	//body
	Road2(g_Console, 43 + k, 7, 4);
	c.Y = 7;
	c.X = 55 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0A);
	c.X = 56 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0A);
	c.X = 57 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0A);
	c.X = 58 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 59 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'v', 0x0A);
	c.X = 60 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 61 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0A);
	c.X = 62 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0A);
	c.X = 64 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.X = 65 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0A);
	c.Y = 8;
	Road2(g_Console, 50 + k, 8, 4);
	Road2(g_Console, 44 + k, 8, 4);
	c.X = 42 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 47 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 48 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0A);
	c.X = 49 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0A);
	c.X = 54 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 55 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 58 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 60 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 66 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 9;
	c.X = 46 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 47 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 48 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 49 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	Road2(g_Console, 50 + k, 9, 5);
	c.X = 55 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 58 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 60 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 64 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.X = 67 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x0A);
	c.Y = 10;
	c.X = 55 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 59 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'Y', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 64 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0A);
	c.X = 67 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.Y = 11;
	c.X = 55 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	Road2(g_Console, 56 + k, 11, 3);
	c.X = 59 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	Road2(g_Console, 60 + k, 11, 3);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 64 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0A);
	c.X = 65 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0A);
	c.X = 66 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0A);
	c.Y = 12;
	c.X = 55 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	Road2(g_Console, 56 + k, 12, 7);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.Y = 13;
	c.X = 55 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.Y = 14;
	c.X = 55 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 59 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.Y = 15;
	c.X = 55 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 59 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.Y = 16;
	c.X = 55 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 59 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
	c.X = 63 + k;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0A);
}

void drawSprites::pig(Console& g_Console, int k)
{
	Battle_Screen(g_Console);
	COORD c;

	//tail
	c.X = 75 + k;
	c.Y = 9;
	g_Console.writeToBuffer(c, '\\', 0x0A);
	c.X = 74 + k;
	c.Y = 8;
	g_Console.writeToBuffer(c, '_', 0x0A);
	c.X = 73 + k;
	g_Console.writeToBuffer(c, '_', 0x0A);

	//body
	for (j = 5; j <= 12; j++)
	{
		c.X = 72 + k;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x0A);
	}
	for (i = 56; i <= 71; i++)
	{
		c.X = i + k;
		c.Y = 4;
		g_Console.writeToBuffer(c, '_', 0x0A);
	}
	for (i = 56; i <= 71; i++)
	{
		c.X = i + k;
		c.Y = 12;
		g_Console.writeToBuffer(c, '_', 0x0A);
	}
	c.X = 55 + k;
	c.Y = 5;
	g_Console.writeToBuffer(c, '|', 0x0A);
	c.Y = 6;
	g_Console.writeToBuffer(c, '|', 0x0A);
	c.Y = 12;
	g_Console.writeToBuffer(c, '|', 0x0A);
	
	//head
	c.X = 56 + k;
	c.Y = 6;
	g_Console.writeToBuffer(c, '_', 0x0A);
	c.X = 57 + k;
	g_Console.writeToBuffer(c, '_', 0x0A);
	c.X = 58 + k;
	g_Console.writeToBuffer(c, '/', 0x0A);  //right ear
	c.X = 59 + k;								//right ear
	g_Console.writeToBuffer(c, '\\', 0x0A); //right ear
	c.X = 54 + k;
	g_Console.writeToBuffer(c, '_', 0x0A);
	c.X = 53 + k;
	g_Console.writeToBuffer(c, '_', 0x0A);
	c.X = 52 + k;
	g_Console.writeToBuffer(c, '\\', 0x0A); //left ear
	c.X = 51 + k;							    //left ear
	g_Console.writeToBuffer(c, '/', 0x0A);  //left ear
	for (j = 7; j <= 11; j++)
	{
		c.X = 60 + k;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x0A);
	}
	for (j = 7; j <= 11; j++)
	{
		c.X = 50 + k;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x0A);
	}
	for (i = 51; i <= 59; i++)
	{
		c.X = i + k;
		c.Y = 11;
		g_Console.writeToBuffer(c, '_', 0x0A);
	}
	//eye
	c.X = 53 + k;
	c.Y = 8;
	g_Console.writeToBuffer(c, ' ', 0xFF); //right eye
	c.X = 57 + k;
	g_Console.writeToBuffer(c, ' ', 0xFF); //left eye
	//nose
	for (i = 53; i <= 57; i++)
	{
		c.X = i + k;
		c.Y = 9;
		g_Console.writeToBuffer(c, '_', 0x0A);
	}
	for (j = 10; j <= 11; j++)
	{
		c.X = 52 + k;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x0A);
	}
	for (j = 10; j <= 11; j++)
	{
		c.X = 58 + k;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x0A);
	}
	//nose hole
	c.X = 54 + k;
	c.Y = 10;
	g_Console.writeToBuffer(c, ' ');
	c.X = 56 + k;
	g_Console.writeToBuffer(c, ' ');

	//legs
	for (j = 13; j <= 15; j++)
	{
		c.X = 58 + k;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x0A);
	}
	for (j = 13; j <= 15; j++)
	{
		c.X = 60 + k;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x0A);
	}
	c.X = 59 + k;
	c.Y = 15;
	g_Console.writeToBuffer(c, '_', 0x0A);
	for (j = 13; j <= 15; j++)
	{
		c.X = 67 + k;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x0A);
	}
	for (j = 13; j <= 15; j++)
	{
		c.X = 69 + k;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x0A);
	}
	c.X = 68 + k;
	c.Y = 15;
	g_Console.writeToBuffer(c, '_', 0x0A);
}

void drawSprites::stickbug_frame1(Console& g_Console)
{
	COORD c;
	// frame 1
	c.X = 5;
	c.Y = 21;
	g_Console.writeToBuffer(c, '|');
	c.Y = 22;
	g_Console.writeToBuffer(c, '|');
	c.X = 6;
	c.Y = 20;
	g_Console.writeToBuffer(c, '/');
	c.X = 7;
	c.Y = 19;
	g_Console.writeToBuffer(c, '/');
	c.Y = 21;
	g_Console.writeToBuffer(c, '|');
	c.Y = 22;
	g_Console.writeToBuffer(c, '|');
	c.X = 8;
	c.Y = 18;
	g_Console.writeToBuffer(c, '_');
	c.Y = 20;
	g_Console.writeToBuffer(c, '/');
	c.X = 9;
	c.Y = 18;
	g_Console.writeToBuffer(c, '\\');
	c.Y = 19;
	g_Console.writeToBuffer(c, '/');
	c.X = 10;
	c.Y = 19;
	g_Console.writeToBuffer(c, '\\');
	c.X = 11;
	c.Y = 20;
	g_Console.writeToBuffer(c, '\\');
	c.Y = 21;
	g_Console.writeToBuffer(c, '/');
	c.Y = 22;
	g_Console.writeToBuffer(c, '\\');
	c.X = 12;
	c.Y = 20;
	g_Console.writeToBuffer(c, '_');
	c.X = 13;
	g_Console.writeToBuffer(c, '_');
	c.Y = 21;
	g_Console.writeToBuffer(c, '\\');
	c.X = 14;
	c.Y = 20;
	g_Console.writeToBuffer(c, '_');
	c.Y = 22;
	g_Console.writeToBuffer(c, '\\');
	c.X = 15;
	c.Y = 20;
	g_Console.writeToBuffer(c, '_');
	c.X = 16;
	g_Console.writeToBuffer(c, '_');
	c.X = 17;
	g_Console.writeToBuffer(c, '_');
	c.Y = 21;
	g_Console.writeToBuffer(c, '|');
	c.Y = 22;
	g_Console.writeToBuffer(c, '|');
	c.X = 18;
	c.Y = 20;
	g_Console.writeToBuffer(c, '_');
}

void drawSprites::stickbug_frame2(Console& g_Console)
{
	COORD c;
	for (int j = 18; j <= 22; j++)
	{
		for (int i = 4; i <= 19; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, "       ");
		}
	}
	for (int j = 19; j <= 22; j++)
	{
		c.X = 4;
		c.Y = j;
		g_Console.writeToBuffer(c, '|');
	}
	c.X = 5;
	c.Y = 18;
	g_Console.writeToBuffer(c, '_');
	c.X = 6;
	g_Console.writeToBuffer(c, '_');
	c.X = 7;
	g_Console.writeToBuffer(c, '_');
	c.X = 8;
	g_Console.writeToBuffer(c, '\\');
	for (int j = 19; j <= 22; j++)
	{
		c.Y = j;
		g_Console.writeToBuffer(c, '|');
	}
	c.X = 9;
	c.Y = 19;
	g_Console.writeToBuffer(c, '\\');
	c.X = 10;
	c.Y = 20;
	g_Console.writeToBuffer(c, '\\');
	c.Y = 21;
	g_Console.writeToBuffer(c, '/');
	c.Y = 22;
	g_Console.writeToBuffer(c, '|');
	c.X = 11;
	c.Y = 20;
	g_Console.writeToBuffer(c, '_');
	c.X = 12;
	g_Console.writeToBuffer(c, '_');
	c.X = 13;
	g_Console.writeToBuffer(c, '_');
	c.Y = 21;
	g_Console.writeToBuffer(c, '|');
	c.Y = 22;
	g_Console.writeToBuffer(c, '|');
	c.X = 14;
	c.Y = 20;
	g_Console.writeToBuffer(c, '_');
	c.X = 15;
	g_Console.writeToBuffer(c, '_');
	c.X = 16;
	g_Console.writeToBuffer(c, '_');
	c.Y = 21;
	g_Console.writeToBuffer(c, '\\');
	c.X = 17;
	c.Y = 20;
	g_Console.writeToBuffer(c, '_');
	c.Y = 22;
	g_Console.writeToBuffer(c, '\\');
}
