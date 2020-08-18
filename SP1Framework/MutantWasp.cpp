#include "MutantWasp.h"

Enemy myEnemy;

MutantWasp::MutantWasp()
{
	chance = 0;
	myEnemy.setEnemy(25, 5, "Mutant Wasp");
}

void MutantWasp::Attack()
{
	Damage Sting;
	Sting.setDamage(5);
	Sting.getDamage();
}

void MutantWasp::Debuff()
{
	chance = (rand() % 100) + 1;
	if (chance >= 0 && chance <= 20)
	{
		cout << "Poisoned";
	}
}

void MutantWasp::Drop()
{
	if (HP == 0)
	{
		cout << "Stinger" << endl;
	}
}

void MutantWasp::Damaged()
{
	this->Hit();
}

MutantWasp::~MutantWasp()
{

}