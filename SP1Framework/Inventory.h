#pragma once
#include "Item.h"
#include "string"

class Inventory : public Item
{
private:
	Item* playerItems[8];
	int Quantity;
	const int MAX = 8;

public:
	Inventory();
	//void setInventory(std::string n, int q);
	//std::string getNameID();
	//int getQuantity();
	//void updateInventory();
	int checkInventory(std::string n);
	~Inventory();
	bool pickup(Item* add);
	bool Consumed(Item* use);
	void setQuantity(int q);
	int getQuantity();
	void QuantityCheck(std::string n);
};