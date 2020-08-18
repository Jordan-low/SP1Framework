#include "Enemy.h"

Entity Bad;

Enemy::Enemy()
{
	name = ' ';
}

void Enemy::setEnemy(string n)
{
	this->SetD(0);
	this->SetH(0);
	this->SetX(1);
	this->SetY(1);
	name = n;
}

int Enemy::getEnemy()
{
	this->GetD();
	this->GetH();
	this->GetX();
	this->GetY();
}

string Enemy::getName()
{
	return name;
}

Enemy::~Enemy()
{

}