#include "Andrew's Inventory.h"

Inventory::Inventory()
{
	items = new const char* [300];
	Quantity = 0;
	name = " ";
	pickup = false;
}

void Inventory::setInventory(std::string n, int q)
{
	name = n;
	Quantity = q;
}

std::string Inventory::getNameID()
{
	return name;
}

int Inventory::getQuantity()
{
	return Quantity;
}

void Inventory::checkInventory()
{
	if ("Raw Meat" && Quantity == 0)
	{
		items[0] = "Raw Meat";
		Quantity = 1;
		getQuantity();
	}

	else if ("Bread" && Quantity == 0)
	{
		items[1] = "Bread";
		Quantity = 1;
		getQuantity();
	}

	else if ("Burger" && Quantity == 0)
	{
		items[2] = "Burger";
		Quantity = 1;
		getQuantity();
	}

	else if ("Taco" && Quantity == 0)
	{
		items[3] = "Taco";
		Quantity = 1;
		getQuantity();
	}

	else if ("Cake" && Quantity == 0)
	{
		items[4] = "Cake";
		Quantity = 1;
		getQuantity();
	}

	else if ("Stinger" && Quantity == 0)
	{
		items[5] = "Singer";
		Quantity = 1;
		getQuantity();
	}

	else if ("Guard Armor" && Quantity == 0)
	{
		items[6] = "Guard Armor";
		Quantity = 1;
		getQuantity();
	}

	else if ("Medicine" && Quantity == 0)
	{
		items[7] = "Medicine";
		Quantity = 1;
		getQuantity();
	}
}

void Inventory::updateInventory()
{
	while (pickup == true)
	{
		if (name == "Raw Meat")
		{
			Quantity++;
			this->items;
			getQuantity();
			break;
		}

		else if (name == "Bread")
		{
			Quantity++;
			this->items;
			getQuantity();
			break;
		}

		else if (name == "Burger")
		{
			Quantity++;
			this->items;
			getQuantity();
			break;
		}

		else if (name == "Taco")
		{
			Quantity++;
			this->items;
			getQuantity();
			break;
		}

		else if (name == "Cake")
		{
			Quantity++;
			this->items;
			getQuantity();
			break;
		}

		else if (name == "Stinger")
		{
			Quantity++;
			this->items;
			getQuantity();
			break;
		}

		else if (name == "Guard Armor")
		{
			Quantity++;
			this->items;
			getQuantity();
			break;
		}

		else if (name == "Medicine")
		{
			Quantity++;
			this->items;
			getQuantity();
			break;
		}

	}
}


Inventory::~Inventory()
{

}