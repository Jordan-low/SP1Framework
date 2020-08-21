#include "Damage.h"
//j
Damage::Damage()
{
	dmg = 0;
}

void Damage::setDamage(int x)
{
	dmg = x;
}

int Damage::getDamage()
{
	return dmg;
}

Damage::~Damage()
{

}
