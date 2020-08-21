#include "Damage.h"

Damage::Damage()
{
	dmg = 0;
	attack = false;
	attacked = false;
}

void Damage::setDamage(int x)
{
	dmg = x;
}

int Damage::getDamage()
{
	return dmg;
}

float Damage::Hit(float Eh, float Pd)
{
	if (attack == true)
	{
		return (Eh - Pd);
	}
}

float Damage::beenHit(float Ph, float Ed)
{
	if (attacked == true)
	{
		return (Ph - Ed);
	}
}

Damage::~Damage()
{

}
