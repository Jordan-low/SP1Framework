#include "Pig.h"

Enemy Friendly;

Pig::Pig()
{
	Friendly.setEnemy(15, 3, "Pig");
}

void Pig::Attack()
{
	Damage Hit;
	Hit.setDamage(3);
	Hit.getDamage();
}

void Pig::Drop()
{
	if (HP == 0)
	{
		cout << "Raw Meat" << endl;
	}
}

Pig::~Pig()
{

}