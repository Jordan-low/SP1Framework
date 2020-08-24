#include "Minigame.h"
#include "Framework/console.h"

void Minigame::wire_game(Console& g_Console)
{
	//length is same, colour and thickness different
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

void Minigame::skull_game(Console& g_Console)
{
	COORD c;
	//dagai shape 
	for (i = 30; i <= 50; i++)
	{
		c.X = i;
		c.Y = 2;
		g_Console.writeToBuffer(c, '_', 0x1A);
	}
	c.X = 29;
	c.Y = 3;
	g_Console.writeToBuffer(c, '/', 0x1A);
	c.X = 51;
	g_Console.writeToBuffer(c, '\\', 0x1A);
	c.X = 28;
	c.Y = 4;
	g_Console.writeToBuffer(c, '/', 0x1A);
	c.X = 52;
	g_Console.writeToBuffer(c, '\\', 0x1A);
	c.X = 27;
	c.Y = 5;
	g_Console.writeToBuffer(c, '/', 0x1A);
	c.X = 53;
	g_Console.writeToBuffer(c, '\\', 0x1A);
	c.X = 26;
	c.Y = 6;
	g_Console.writeToBuffer(c, '/', 0x1A);
	c.X = 54;
	g_Console.writeToBuffer(c, '\\', 0x1A);
	for (j = 7; j <= 11; j++)
	{
		c.X = 25;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	c.Y = 12;
	g_Console.writeToBuffer(c, '\\', 0x1A);
	c.X = 26;
	c.Y = 13;
	g_Console.writeToBuffer(c, '\\', 0x1A);
	c.X = 27;
	c.Y = 14;
	g_Console.writeToBuffer(c, '\\', 0x1A);
	c.X = 28;
	c.Y = 15;
	g_Console.writeToBuffer(c, '\\', 0x1A);
	c.X = 29;
	c.Y = 16;
	g_Console.writeToBuffer(c, '\\', 0x1A);
	for (j = 7; j <= 11; j++)
	{
		c.X = 55;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	c.Y = 12;
	g_Console.writeToBuffer(c, '/', 0x1A);
	c.X = 54;
	c.Y = 13;
	g_Console.writeToBuffer(c, '/', 0x1A);
	c.X = 53;
	c.Y = 14;
	g_Console.writeToBuffer(c, '/', 0x1A);
	c.X = 52;
	c.Y = 15;
	g_Console.writeToBuffer(c, '/', 0x1A);
	c.X = 51;
	c.Y = 16;
	g_Console.writeToBuffer(c, '/', 0x1A);
	for (j = 17; j <= 21; j++)
	{
		c.X = 30;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (j = 17; j <= 21; j++)
	{
		c.X = 50;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (i = 31; i <= 49; i++)
	{
		c.X = i;
		c.Y = 21;
		g_Console.writeToBuffer(c, '_', 0x1A);
	}

	//teeth thing
	for (j = 18; j <= 21; j++)
	{
		c.X = 37;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}
	for (j = 18; j <= 21; j++)
	{
		c.X = 43;
		c.Y = j;
		g_Console.writeToBuffer(c, '|', 0x1A);
	}

	//nose thing
	for (j = 13; j <= 14; j++)
	{
		for (i = 38; i <= 42; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ');
		}
	}

	//left eye socket
	for (i = 34; i <= 38; i++)
	{
		c.X = i;
		c.Y = 6;
		g_Console.writeToBuffer(c, '_', 0x1A);
	}
	i = 33;
	for (j = 7; j <= 10; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, '/', 0x1A);
		i--;
	}
	for (i = 31; i <= 34; i++)
	{
		c.X = i;
		c.Y = 10;
		g_Console.writeToBuffer(c, '_', 0x1A);
	}
	i = 38;
	for (j = 7; j <= 10; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, '/', 0x1A);
		i--;
	}

	//right eye socket
	for (i = 42; i <= 46; i++)
	{
		c.X = i;
		c.Y = 6;
		g_Console.writeToBuffer(c, '_', 0x1A);
	}
	i = 47;
	for (j = 7; j <= 10; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, '\\', 0x1A);
		i++;
	}
	for (i = 46; i <= 49; i++)
	{
		c.X = i;
		c.Y = 10;
		g_Console.writeToBuffer(c, '_', 0x1A);
	}
	i = 42;
	for (j = 7; j <= 10; j++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, '\\', 0x1A);
		i++;
	}
}

void Minigame::trueSkull(Console& g_Console)
{
	skull_game(g_Console);
	COORD c;
	for (i = 38; i <= 42; i++)
	{
		c.X = i;
		c.Y = 17;
		g_Console.writeToBuffer(c, '_', 0x1A);
	}
}
