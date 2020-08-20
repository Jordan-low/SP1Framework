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

int Player::getPlayer()
{
	this->GetDmg();
	this->GetHealth();
	this->GetXcoord();
	this->GetYcoord();
	this->GetPlayerName();
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