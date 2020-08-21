#include "Poison.h"
#include "Player.h"
//j
#include <iostream>

using namespace std;

Poison::Poison()
{
	Poisoned = 'P';
}

void Poison::setPoison(Console& g_Console)
{
	COORD c;
	c.X = GetX();
	c.Y = GetY();
	int seconds = 0;
	while (Poisoned)
	{
		g_Console.writeToBuffer(c, "Poisoned", 0xD2);
		if (seconds == 10 || seconds == 20)
		{
			this->SetH(h - 3);
			this->GetH();
			Sleep(1000);
			seconds++;
		}
		
		if (seconds == 30)
		{
			this->SetH(h - 3);
			this->GetH();
			Sleep(1000);
			seconds = 0;
		}
		break;
	}
}

char Poison::getPoison()
{
	return Poisoned;
}

Poison::~Poison()
{

}