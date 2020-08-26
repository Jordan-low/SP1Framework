#include "Enemy.h"
#include "game.h"
#include "Entity.h"//j

Enemy::Enemy()
{
	//name = 'E';
	//attack = false;
	//attacked = false;
	Chance = 0;
}

/*void Enemy::setEnemy(int health, int dmg, const char n)
{
	this->SetH(health);
	this->SetD(dmg);
	name = n;
}

int Enemy::getD()
{
	return this->GetD();
}

int Enemy::getH()
{
	return this->GetH();
}

int Enemy::getX()
{
	return this->GetX();
}

int Enemy::getY()
{
	return this->GetY();
}

char Enemy::getName()
{
	return this->GetName();
}

int Enemy::Hit(int Eh, int Pd)
{
	if (attack == true)
	{
		return (Eh - Pd);
	}
}

int Enemy::beenHit(int Ph, int Ed)
{
	if (attacked == true)
	{
		return (Ph - Ed);
	}
}

void Enemy::Drop(Console& g_Console)
{
	if (GetH() == 0)
	{
		COORD c;
		c.X = 5;
		c.Y = 26;
		g_Console.writeToBuffer(c, ' ', 0x00);
	}
}*/

bool Enemy::Poison(Console& g_Console) 
{
	Chance = (rand() % 100) + 1;
	if (Chance > 0 && Chance < 16)
	{
		return true;
		COORD c;
		c.X = 5;
		c.Y = 26;
		int seconds = 0;
		while (true)
		{
			g_Console.writeToBuffer(c, "Poisoned", 0xD2);
			/*if (seconds == 10 && seconds == 20)
			{
				SetH(GetH() - 3);
				Sleep(1000);
				seconds++;
			}

			if (seconds == 30)
			{
				SetH(GetH() - 3);
				Sleep(1000);
				seconds = 0;
			}
			break;*/
		}
	}
	else
	{
		return false;
	}
}

Enemy::~Enemy()
{

}