#include "TutEnemy.h"
#include <iostream>

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
	this->beenHit();
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
	
}