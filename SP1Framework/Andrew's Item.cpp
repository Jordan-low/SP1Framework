#include "Andrew's Item.h"

Item::Item()
{
	*items[8] = { ' ' };
}

void Item::setItem(const char i)
{
	*items[8] = i;
}

char Item::getItem()
{
	return *items[8];
}

void Item::Healing()
{
	const char* Healing[5] = { "Raw Meat",  "Bread", "Burger", "Taco", "Cake" };
}

void Item::Defence()
{
	const char* Defence[2] = { "Stinger", "Guard Armor" };
}

Item::~Item()
{

}