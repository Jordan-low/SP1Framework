#include "MutantWasp.h"
#include <iostream>

MutantWasp::MutantWasp()
{
	chance = 0;
	this->setEnemy('W');
	this->SetD(5);
	this->SetH(25);
	this->SetX(1);
	this->SetY(1);

}

void MutantWasp::Attack()
{
	this->beenHit(50, 5);
}

void MutantWasp::Debuff()
{
	chance = (rand() % 100) + 1;
	if (chance >= 0 && chance <= 20)
	{
		Poison Poisons;
		Poisons.setPoison();
		Poisons.getPoison();
	}
}

void MutantWasp::Drop()
{
	if (GetH() == 0)
	{
		cout << "Stinger" << endl;
	}
}

void MutantWasp::Damaged()
{
	this->Hit(25, 5);
}

MutantWasp::~MutantWasp()
{

}