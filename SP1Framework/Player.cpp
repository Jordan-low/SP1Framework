#include "Player.h"

Player::Player()
{
	name = 'O';
}

void Player::setPlayer()
{
	this->SetD(5);
	this->SetH(50);
	this->SetX(0);
	this->SetY(0);
}

int Player::getPlayer()
{
	return this->GetD();
	return this->GetH();
	return this->GetX();
	return this->GetY();
}

char Player::GetName()
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