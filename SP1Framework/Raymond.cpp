#include "Raymond.h"
#include <stdlib.h> 
#include <iostream>
//h
Raymond::Raymond()
{
	this->setEnemy('R');
	this->SetD(25);
	this->SetH(120);
	this->SetX(1);
	this->SetY(1);
}

void Raymond::Attack()
{
	this->beenHit(75, 25);
}

void Raymond::Talk(Console& g_Console)
{
	int seconds = 3;
	COORD c;
	c.X = GetX();
	c.Y = GetY();
	char* text[4] = { "It seems like the person that I have been searching for have came to me instead, thank you for that.", "So...have you came to surrender?", "Why don't you join me and we can rule the world together.", "Actually nah, that's a bad idea. Only I can rule the world!" };
	while (true)
	{
		g_Console.writeToBuffer(c, text[0], 0xF0);
		Sleep(3000);
		seconds--;
		if (seconds == 0)
		{
			delete text[0];
			seconds = 0;
			g_Console.writeToBuffer(c, text[1], 0xF0);
			Sleep(2000);
			seconds--;
			if (seconds == 0)
			{
				delete text[1];
				seconds = 0;
				g_Console.writeToBuffer(c, text[2], 0xF0);
				Sleep(2000);
				seconds--;
				if (seconds == 0)
				{
					delete text[2];
					seconds = 0;
					g_Console.writeToBuffer(c, text[3], 0xF0);
					Sleep(2000);
					seconds--;
					if (seconds == 0)
					{
						delete text[3];
						seconds = 0;
					}
				}
			}
		}
	}
}

void Raymond::Damaged()
{
	this->Hit(120, 5);
}

Raymond::~Raymond()
{
	
}