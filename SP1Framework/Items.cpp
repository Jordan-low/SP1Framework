#include "Items.h"
#include "Player.h"
//j
Items::Items()
{
	Items = "";
}

int Items::GetHeal()
{
	return 0;
}

void Items::setItems(char* nameid)
{
	item = nameid;
}

char Items::getItems()
{
	return *item;
}

void Items::Drops()
{ 
	char* Drops[8] = { "Raw Meat", "Burger", "Taco", "Bread", "Cake", "Stinger", "Guard Armor", "Medicine"};
}

void Items::Heal(int h)
{
	char* Healing[5] = { "Raw Meat", "Burger", "Taco", "Bread", "Cake" };
	Healing[0] = HP + 
}

void 