#include "Enemy.h"
#include "Player.h"

Enemy::Enemy()
{
	HP = 0;
	Atk = 0;
}

void Enemy::setEnemy(int h, int d, string n)
{
	HP = h;
	Atk = d;
	d = this->getDamage();
	name = n;
}

short Enemy::getEnemy()
{
	return HP;
	return Atk;
}

string Enemy::getName()
{
	return name;
}

void Enemy::Hit()
{
	Player Attack;
	Attack.Attack();
	HP -= 5;
	HP--;
}

Enemy::~Enemy()
{

}