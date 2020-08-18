#include "Guard.h"

Enemy Aggressive;

Guard::Guard()
{
	Aggressive.setEnemy(40, 15, "Guard");
}

void Guard::Attack()
{
	Damage Whack;
	Whack.setDamage(15);
	Whack.getDamage();
}

void Guard::Drop()
{
	if (HP == 0)
	{
		cout << "???" << endl; //Guard Suit???
	}
}

void Guard::Damaged()
{
	this->Hit();
}

Guard::~Guard()
{
	if (HP == 0)
	{
		
	}
}