#include "TutEnemy.h"

Enemy ThisEnemy;

TutEnemy::TutEnemy()
{
	chance = 0;
	ThisEnemy.setEnemy(10, 2, "Tutorial Enemy");
}

void TutEnemy::Attack()
{
	Damage Lunge;
	Lunge.setDamage(2);
	Lunge.getDamage();
}

void TutEnemy::Debuff()
{
	chance = (rand() % 100) + 1;
	if (chance >= 0 && chance <= 15)
	{
		cout << "Poisoned";
	}
}

void TutEnemy::Damaged()
{
	this->Hit();
}

TutEnemy::~TutEnemy()
{
	if (HP == 0)
	{
		
	}
}