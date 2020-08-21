#include "TutEnemy.h"
#include <iostream>
//j
TutEnemy::TutEnemy()
{
	chance = 0;
	this->setEnemy('T');
	this->SetD(2);
	this->SetH(10);
	this->SetX(1);
	this->SetY(1);
}

void TutEnemy::Attack()
{
	this->beenHit(50, 2);
}

void TutEnemy::Debuff(Console& g_Console)
{
	chance = (rand() % 100) + 1;
	if (chance >= 0 && chance <= 15)
	{
		setPoison(g_Console);
		getPoison();
	}
}

void TutEnemy::Damaged()
{
	this->Hit(10, 5);
}

TutEnemy::~TutEnemy()
{
	
}