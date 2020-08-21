#include "Pig.h"
#include <iostream>

Pig::Pig()
{
	this->setEnemy('P');
	this->SetD(3);
	this->SetH(15);
	this->SetX(1);
	this->SetY(1);
}

void Pig::Attack()
{
	this->beenHit(50, 3);
}

void Pig::Drop()
{
	if (GetH() == 0)
	{
		cout << "Raw Meat" << endl;
	}
}

void Pig::Damaged()
{
	this->Hit(15, 5);
}

Pig::~Pig()
{

}