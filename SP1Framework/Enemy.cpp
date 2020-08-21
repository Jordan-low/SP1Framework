#include "Enemy.h"
#include "Entity.h"//j

Enemy::Enemy()
{
	name = 'E';
	attack = false;
	attacked = false;
}

void Enemy::setEnemy(const char n)
{
	this->SetX(1);
	this->SetY(1);
	this->SetH(0);
	this->SetD(0);
	name = n;
}

int Enemy::getD()
{
	return this->GetD();
}

int Enemy::getH()
{
	return this->GetH();
}

int Enemy::getX()
{
	return this->GetX();
}

int Enemy::getY()
{
	return this->GetY();
}

char Enemy::getName()
{
	return this->GetName();
}

float Enemy::Hit(float Eh, float Pd)
{
	if (attack == true)
	{
		return (Eh - Pd);
	}
}

float Enemy::beenHit(float Ph, float Ed)
{
	if (attacked == true)
	{
		return (Ph - Ed);
	}
}

Enemy::~Enemy()
{

}