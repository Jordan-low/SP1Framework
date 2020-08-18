#include "Player.h"

Player::Player()
{
	name = 'O';
}

Player::~Player()
{
	
}

char Player::GetName()
{
	return name;
}

void Player::Attack()
{
	Damage Melee;
	Melee.setDamage(5);
	Melee.getDamage();
}