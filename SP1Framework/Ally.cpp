#include "Ally.h"
//j
Ally::Ally()
{
	name = ' ';
}

void Ally::setAlly(float x, float y, float health, float dmg, const char n)
{
	this->SetD(x);
	this->SetH(50);
	this->SetX(0);
	this->SetY(0);
	name = n;
}

int Ally::getDmg()
{
	return this->GetD();
}

int Ally::getHealth()
{
	return this->GetH();
}

int Ally::getXCoords()
{
	return this->GetX();
}

int Ally::getYCoords()
{
	return this->GetY();
}

char Ally::getNamed()
{
	return this->GetName();
}
Ally::~Ally()
{

}
/*
int Ally::getAlly()
{
	this->getDmg();
	this->getHealth();
	this->getXCoords();
	this->getYCoords();
	this->getNamed();
}*/