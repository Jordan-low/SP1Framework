#include "Guard.h"
#include "Enemy.h"
#include <iostream>
#include "Damage.h"

Guard::Guard()
{
	this->setEnemy('G');
	this->SetD(15);
	this->SetH(50);
	this->SetX(1);
	this->SetY(1);
}

void Guard::Attack()
{
	this->beenHit(50, 15);
}

void Guard::Damaged()
{
	this->Hit(50, 5);
}

void Guard::Drop()
{
	if (GetH() == 0)
	{
		cout << "Guard Armor" << endl;
	}
}

Guard::~Guard()
{
	
}