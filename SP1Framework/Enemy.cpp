#include "Enemy.h"
#include "Entity.h"
#include "Player.h"
#include "Guard.h"

Enemy::Enemy()
{
	name = 'E';
}

void Enemy::setEnemy(const char n)
{
	this->SetX(1);
	this->SetY(1);
	this->SetH(0);
	this->SetD(0);
	name = n;
}

short Enemy::getEnemy()
{
	return this->GetX();
	return this->GetY();
	return this->GetH();
	return this->GetD();
	return this->GetName();
}

void Enemy::Hit()
{
	Player Attack;
	if (attack == true)
	{
		this->SetH(x);
		Attack.Attack();
		this->SetH(x - 5);
		this->GetH();
	}
}

void Enemy::beenHit()
{
	Player Attacked;
	if (attacked == true)
	{
		Attacked.SetH(50);
		this->SetD(d);
		Attacked.SetH(50 - d);
		this->GetH();
	}
}

Enemy::~Enemy()
{

}