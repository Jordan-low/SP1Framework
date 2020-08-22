#include "Player.h"
//j
Player::Player()
{
	name = ' ';
}

void Player::setPlayer(float x, float y, float health, float dmg, const char n)
{
	this->SetD(x);
	this->SetH(y);
	this->SetX(health);
	this->SetY(dmg);
	name = n;
}

int Player::GetDmg()
{
	return this->GetD();
}

int Player::GetHealth()
{
	return this->GetH();
}

int Player::GetXcoord()
{
	return this->GetX();
}

int Player::GetYcoord()
{
	return this->GetY();
}

char Player::GetPlayerName()
{
	return this->GetName();
}

void Player::Attack()
{
	Player player;
	player.SetD(5);
	/*
	Damage Melee;
	Melee.setDamage(5);
	Melee.getDamage();
	*/
}

Player::~Player()
{

}