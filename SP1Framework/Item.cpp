#include "Item.h"
#include <iostream>

Item::Item()
{
	name = " ";
}

void Item::setItemName(std::string n)
{
	name = n;
}

std::string Item::getItemName()
{
	return name;
}

void Item::setHealing(int h)
{
	Heal = 0;
}

int Item::getHealing()
{
	return Heal;
}

void Item::setDmgBoost(int a)
{
	addDmg = a;
}

int Item::getDmgBoost()
{
	return addDmg;
}

void Item::setNoStatus(std::string s)
{
	Status = s;
}

std::string Item::getNoStatus()
{
	return Status;
}

void Item::Barrel(Console& g_Console)
{
	itemChance = (rand() % 2) + 1;
}

void Item::Box(Console& g_Console)
{
	itemChance = (rand() % 6) + 1;
	if (itemChance == 1)
	{
		COORD c;
		c.X = 5;
		c.Y = 26;
		g_Console.writeToBuffer(c, "Raw Meat", 0x0F);
	}
	if (itemChance == 2)
	{
		COORD c;
		c.X = 5;
		c.Y = 26;
		g_Console.writeToBuffer(c, "Bread", 0x0F);
	}
	if (itemChance == 3)
	{
		COORD c;
		c.X = 5;
		c.Y = 26;
		g_Console.writeToBuffer(c, "Burger", 0x0F);
	}
	if (itemChance == 4)
	{
		COORD c;
		c.X = 5;
		c.Y = 26;
		g_Console.writeToBuffer(c, "Taco", 0x0F);
	}
	if (itemChance == 5)
	{
		COORD c;
		c.X = 5;
		c.Y = 26;
		g_Console.writeToBuffer(c, "Cake", 0x0F);
	}
	if (itemChance == 6)
	{
		COORD c;
		c.X = 5;
		c.Y = 26;
		g_Console.writeToBuffer(c, "Medicine", 0x0F);
	}
}

Item::~Item()
{

}