#include "Andrew's Item.h"
#include <iostream>

Item::Item()
{
	items = new char *[8];
	itemChance = 0;
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

void Item::Barrel(Console& g_Console)
{
	itemChance = (rand() % 2) + 1;
	if (itemChance == 1)
	{
		COORD c;
		c.X = 5;
		c.Y = 26;
		g_Console.writeToBuffer(c, "Stinger", 0x0F);
	}
	if (itemChance == 2)
	{
		COORD c;
		c.X = 5;
		c.Y = 26;
		g_Console.writeToBuffer(c, "Guard Armor", 0x0F);
	}
}

void Item::Box(Console& g_Console)
{
	itemChance = (rand() % 5) + 1;
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
}

Item::~Item()
{

}