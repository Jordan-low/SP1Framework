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

void Enemy::Hit()
{
	Player Attack;
	if (attack == true)
	{
		Player* setPlayer();
		setPlayer()->SetH(50 - d);
	}
}

void Enemy::beenHit()
{
	if (attacked == true)
	{
		Enemy* setEnemy();
		setEnemy()->SetH(h - 5);
	}
}

Enemy::~Enemy()
{

}