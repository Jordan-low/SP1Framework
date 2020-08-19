#include "Guard.h"
#include "Enemy.h"
#include <iostream>

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
	this->beenHit();
}

void Guard::Damaged()
{
	this->Hit();
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