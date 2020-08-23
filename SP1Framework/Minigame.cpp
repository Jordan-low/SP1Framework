#include "Minigame.h"
#include "Framework/console.h"

void Minigame::wire_game(Console& g_Console)
{
	//A2
	//B1
	//C3
	COORD c;

	//screen

	//A
	c.X = 17;
	c.Y = 2;
	g_Console.writeToBuffer(c, '_', 0x1A);  //   _
	c.X = 16;								//	|_|
	c.Y = 3;								//  | |
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.X = 17;
	g_Console.writeToBuffer(c, '_', 0x1A);
	c.X = 18;
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.Y = 4;
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.X = 16;
	g_Console.writeToBuffer(c, '|', 0x1A);

	//B
	c.X = 32;
	c.Y = 2;
	g_Console.writeToBuffer(c, '_', 0x1A);	//    _
	c.X = 31;								//   |_|
	c.Y = 3;								//   |_|
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.X = 32;
	g_Console.writeToBuffer(c, '_', 0x1A);
	c.X = 33;
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.Y = 4;
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.X = 32;
	g_Console.writeToBuffer(c, '_', 0x1A);
	c.X = 33;
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.X = 31;
	g_Console.writeToBuffer(c, '|', 0x1A);

	//C
	c.X = 48;
	c.Y = 2;
	g_Console.writeToBuffer(c, '_', 0x1A); //    _
	c.X = 47;							   //   |
	c.Y = 3;							   //   |_
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.Y = 4;
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.X = 48;
	g_Console.writeToBuffer(c, '_', 0x1A);

	for (i = 2; i <= 76; i++)
	{
		c.X = i;
		c.Y = 5;
		g_Console.writeToBuffer(c, '_', 0x1A);
	}

	//Wire A
	for (j = 5; j <= 8; j++)
	{
		for (i = 16; i <= 18; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ', 0x4D);
		}
	}

	//Wire B
	for (j = 5; j <= 8; j++)
	{
		c.X = 32;
		c.Y = j;
		g_Console.writeToBuffer(c, ' ', 0x2B);
	}

	//Wire C
	for (j = 5; j <= 8; j++)
	{
		for (i = 47; i <= 48; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ', 0x3C);
		}
	}

	//1
	c.X = 17;
	c.Y = 21;
	g_Console.writeToBuffer(c, '|', 0x1A); //   |
	c.Y = 22;							   //   |
	g_Console.writeToBuffer(c, '|', 0x1A);

	//2
	c.X = 32;
	c.Y = 20;
	g_Console.writeToBuffer(c, '_', 0x1A); //    _
	c.X = 33;							   //    _|
	c.Y = 21;							   //   |_
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.X = 32;
	g_Console.writeToBuffer(c, '_', 0x1A);
	c.X = 31;
	c.Y = 22;
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.X = 32;
	g_Console.writeToBuffer(c, '_', 0x1A);

	//3
	c.X = 47;
	c.Y = 20;
	g_Console.writeToBuffer(c, '_', 0x1A); //    _
	c.X = 48;							   //    _|
	c.Y = 21;							   //    _|
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.X = 47;
	g_Console.writeToBuffer(c, '_', 0x1A);
	c.X = 48;
	c.Y = 22;
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.X = 47;
	g_Console.writeToBuffer(c, '_', 0x1A);

	for (i = 2; i <= 76; i++)
	{
		c.X = i;
		c.Y = 19;
		g_Console.writeToBuffer(c, '_', 0x1A);
	}

	//Wire 1 (B)
	for (j = 16; j <= 19; j++)
	{
		c.X = 17;
		c.Y = j;
		g_Console.writeToBuffer(c, ' ', 0x2B);
	}

	//Wire 2 (A)
	for (j = 16; j <= 19; j++)
	{
		for (i = 31; i <= 33; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ', 0x4D);
		}
	}

	//Wire 3 (C)
	for (j = 16; j <= 19; j++)
	{
		for (i = 47; i <= 48; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ', 0x3C);
		}
	}

	c.X = 2;
	c.Y = 25;
	g_Console.writeToBuffer(c, "Objective: Connect the wires", 0x1A);

	//multiple choice thing?
}
