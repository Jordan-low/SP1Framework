#pragma once
#include "Framework\console.h"

class Item
{
private:
	char** items;
	int itemChance;
public:
	Item();
	void setItem(const char i);
	char getItem();
	void Healing();
	void Defence();
	~Item();
	void Barrel(Console& g_Console);
	void Box(Console& g_Console);
};