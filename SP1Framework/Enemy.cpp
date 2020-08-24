#include "Enemy.h"
#include "Entity.h"//j

Enemy::Enemy()
{
	name = 'E';
	attack = false;
	attacked = false;
	Chance = 0;
}

void Enemy::setEnemy(int x, int y, int health, int dmg, const char n)
{
	this->SetX(x);
	this->SetY(y);
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

/*float Enemy::Hit(float Eh, float Pd)
{
	if (attack == true)
	{
		return (Eh - Pd);
	}
}

float Enemy::beenHit(float Ph, float Ed)
{
	if (attacked == true)
	{
		return (Ph - Ed);
	}
}*/

void Enemy::Drop(Console& g_Console)
{
	if (GetH() == 0)
	{
		COORD c;
		c.X = GetX();
		c.Y = GetY();
		g_Console.writeToBuffer(c, ' ', 0x00);
	}
}

bool Enemy::Poison(Console& g_Console) 
{
	Chance = (rand() % 100) + 1;
	if (Chance >= 0 && Chance <= 15)
	{
		return true;
		COORD c;
		c.X = GetX();
		c.Y = GetY();
		int seconds = 0;
		while (true)
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
	else
	{
		return false;
	}
}

Enemy::~Enemy()
{

}