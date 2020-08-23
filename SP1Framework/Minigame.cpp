#include "Minigame.h"
#include "Framework/console.h"

void Minigame::wire_game(Console& g_Console)
{
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
	c.X = 47;
	c.Y = 2;
	g_Console.writeToBuffer(c, '_', 0x1A); //    _
	c.X = 46;							   //   |
	c.Y = 3;							   //   |_
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.Y = 4;
	g_Console.writeToBuffer(c, '|', 0x1A);
	c.X = 47;
	g_Console.writeToBuffer(c, '_', 0x1A);

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
}
