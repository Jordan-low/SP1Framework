#pragma once

class Item
{
private:
	char* items[9];
public:
	Item();
	void setItem(const char i);
	char getItem();
	void Healing();
	void Defence();
	~Item();
};