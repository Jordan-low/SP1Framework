#include "Cutscenes.h"

void Cutscenes::animate(Console& g_Console)
{
	printmap(g_Console);
}

void Cutscenes::nextdialogue(Console& g_Console)
{
	printmap(g_Console);
}

void Cutscenes::drawgrid(Console& g_Console, int x, int y, char chara)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = chara, 0x04);
}

void Cutscenes::drawgridG(Console& g_Console, int x, int y, char chara)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = chara, 0x0A);
}

void Cutscenes::drawgridY(Console& g_Console, int x, int y, char chara)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = chara, 0x0E);
}

void Cutscenes::drawgridW(Console& g_Console, int x, int y, char chara)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = chara, 0x0F);
}

void Cutscenes::drawgridLaserRight(Console& g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x04);
	c.X = x - 3;
	c.Y = y - 3;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x04);
}

void Cutscenes::drawgridLaserLeft(Console& g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x04);
	c.X = x + 3;
	c.Y = y - 3;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x04);
}

void Cutscenes::drawgridLaserUp(Console& g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '^', 0x04);
	c.X = x;
	c.Y = y - 1;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x04);
}
void Cutscenes::stickmanLeft(Console& g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '>', 0x04);
	c.X = x + 1;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x04);
	c.X = x + 2;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x04);
	c.X = x + 3;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x04);
	c.X = x + 4;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x04);
	c.X = x + 5;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = 'O', 0x04);
	c.X = x - 1;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x04);
}

void Cutscenes::movingBlock(Console& g_Console, int x, int y)
{
	COORD c;

	c.X = x;
	c.Y = y + 1;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0D);
	c.X = x + 8;
	c.Y = y + 1;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0D);
	for (int i = x; i < (x + 9); i++)
	{
		c.X = i;
		c.Y = y;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0D);
	}

	for (int i = (x+1); i < (x + 8); i++)
	{
		c.X = i;
		c.Y = y + 1;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x0D);
	}

	for (int i = x; i < (x+9); i++)
	{
		c.X = i;
		c.Y = y - 1;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x0D);
	}
	
}

void Cutscenes::breakFloor(Console& g_Console, int x, int y)
{
	COORD c;

	c.X = x;
	c.Y = y;

	//horizontal lines
	for (int i = x; i < (x + 11); i++)
	{
		c.X = i;
		c.Y = y;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0E);
	}

	for (int i = x; i < (x + 11); i++)
	{
		c.X = i;
		c.Y = y + 5;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '-', 0x0E);
	}

	//vertical lines
	for (int j = (y + 2); j < (y + 4); j++)
	{
		for (int i = (x - 2); i < (x-1); i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0E);
		}
	}

	c.Y = y + 1;
	c.X = x - 1;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0E);
	c.X = x;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0E);

	c.Y = y + 1;
	c.X = x + 10;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0E);
	c.X = x + 11;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0E);

	c.Y = y + 4;
	c.X = x - 1;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0E);
	c.X = x;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0E);

	c.Y = y + 4;
	c.X = x + 10;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '_', 0x0E);
	c.X = x + 11;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0E);

	for (int j = (y + 2); j < (y + 4); j++)
	{
		for (int i = (x + 12); i < (x + 13); i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '|', 0x0E);
		}
	}
}

void Cutscenes::cleargrid(Console& g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x0A);
}

void Cutscenes::clearSprite(Console& g_Console)
{
	COORD c;
	for (int j = 2; j < 16; j++)
	{
		for (int i = 35; i < 78; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x0A);
		}
	}
}

void Cutscenes::clearRobertSprite(Console& g_Console)
{
	COORD c;
	for (int j = 3; j < 16; j++)
	{
		for (int i = 3; i < 27; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x0A);
		}
	}
}

void Cutscenes::clearSpriteLine(Console& g_Console, int y)
{
	COORD c;
	for (int i = 35; i < 78; i++)
	{
		c.X = i;
		c.Y = y;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x0A);
	}
}

void Cutscenes::clearRobertSpriteLine(Console& g_Console, int y)
{
	COORD c;
	for (int i = 3; i < 27; i++)
	{
		c.X = i;
		c.Y = y;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x0A);
	}
}

void Cutscenes::clearRaymondSpriteLine(Console& g_Console, int y)
{
	COORD c;
	for (int i = 3; i < 75; i++)
	{
		c.X = i;
		c.Y = y;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x0A);
	}
}

void Cutscenes::clearScreen(Console& g_Console)
{
	COORD c;
	for (int j = 2; j <= 22; j++)
	{
		for (int i = 2; i <= 77; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ', 0x00);
		}
	}
}

void Cutscenes::CrowdStandstill(Console& g_Console)
{
	for (j = 11; j < 22; (j = j + 2))
	{
		for (i = 19; i < 60; (i = i + 2))
		{
			drawgrid(g_Console, i, j, (char)12);
		}
	}
	//even rows
	for (j = 12; j < 21; (j = j + 2))
	{
		for (i = 18; i < 61; (i = i + 2))
		{
			drawgrid(g_Console, i, j, (char)12);
		}
	}
}

void Cutscenes::CrowdStandstillclear(Console& g_Console)
{
	for (j = 11; j < 22; (j = j + 2))
	{
		for (i = 19; i < 60; (i = i + 2))
		{
			cleargrid(g_Console, i, j);
		}
	}
	//even rows
	for (j = 12; j < 21; (j = j + 2))
	{
		for (i = 18; i < 61; (i = i + 2))
		{
			cleargrid(g_Console, i, j);
		}
	}
}

void Cutscenes::CrowdMoveLeft(Console& g_Console)
{
	for (j = 11; j < 22; (j = j + 2))
	{
		for (i = 18; i < 59; (i = i + 2))
		{
			drawgrid(g_Console, i, j, (char)12);
		}
	}
	//even rows
	for (j = 12; j < 21; (j = j + 2))
	{
		for (i = 19; i < 62; (i = i + 2))
		{
			drawgrid(g_Console, i, j, (char)12);
		}
	}
}

void Cutscenes::CrowdMoveLeftclear(Console& g_Console)
{
	for (j = 11; j < 22; (j = j + 2))
	{
		for (i = 18; i < 59; (i = i + 2))
		{
			cleargrid(g_Console, i, j);
		}
	}
	//even rows
	for (j = 12; j < 21; (j = j + 2))
	{
		for (i = 19; i < 62; (i = i + 2))
		{
			cleargrid(g_Console, i, j);
		}
	}
}

void Cutscenes::CrowdMoveRight(Console& g_Console)
{
	for (j = 11; j < 22; (j = j + 2))
	{
		for (i = 20; i < 61; (i = i + 2))
		{
			drawgrid(g_Console, i, j, (char)12);
		}
	}
	//even rows
	for (j = 12; j < 21; (j = j + 2))
	{
		for (i = 17; i < 60; (i = i + 2))
		{
			drawgrid(g_Console, i, j, (char)12);
		}
	}
}

void Cutscenes::CrowdMoveRightclear(Console& g_Console)
{
	for (j = 11; j < 22; (j = j + 2))
	{
		for (i = 20; i < 61; (i = i + 2))
		{
			cleargrid(g_Console, i, j);
		}
	}
	//even rows
	for (j = 12; j < 21; (j = j + 2))
	{
		for (i = 17; i < 60; (i = i + 2))
		{
			cleargrid(g_Console, i, j);
		}
	}
}
