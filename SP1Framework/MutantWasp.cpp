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
	this->beenHit();
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
	if (GetH() == 0)
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