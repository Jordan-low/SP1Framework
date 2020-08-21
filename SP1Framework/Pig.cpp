#include "Pig.h"
#include <iostream>
//j
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

void Pig::Drop(Console& g_Console)
{
	if (GetH() == 0)
	{
		COORD c;
		c.X = GetX();
		c.Y = GetY();
		g_Console.writeToBuffer(c, "Raw Meat", 0xC4);
	}
}

void Pig::Damaged()
{
	this->Hit(15, 5);
}

Pig::~Pig()
{

}