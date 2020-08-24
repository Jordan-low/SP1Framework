#include "Entity.h"
//j
Entity::Entity()
{
	x = 1;
	y = 1;
	h = 100;
	d = 10;
	name = ' ';
}

Entity::~Entity()
{
}

char Entity::GetName()
{
	return name;
}

int Entity::GetX()
{
	return x;
}

int Entity::GetY()
{
	return y;
}

int Entity::GetH()
{
	return h;
}

int Entity::GetD()
{
	return d;
}

void Entity::SetD(int dmg)
{
	d = dmg;
}

void Entity::SetH(int health)
{
	h = health;
}

void Entity::SetX(int x_coord)
{
	x = x_coord;
}

void Entity::SetY(int y_coord)
{
	y = y_coord;
}

