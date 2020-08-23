#pragma once

class Item
{
private:
	char* items[8];
public:
	Item();
	void setItem(const char i);
	char getItem();
	char Healing();
	char Defence();
	~Item();
};