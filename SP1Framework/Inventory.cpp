#include "Inventory.h"
#include "Item.h"

Inventory::Inventory()
{
	for (int i = 0; i < 8; i++)
	{
		playerItems[i] = nullptr;
	}
	Quantity = 0;
}

bool Inventory::pickup(Item* add)
{
	if (Quantity < 0)
	{
		for (int i = 0; i < 8; i++)
		{
			if (playerItems[i] == nullptr)
			{
				playerItems[i] = add;
				Quantity++;
				break;
			}
		}
		return true;
	}
	else
	{
		Quantity = 0;
		return false;
	}
}

bool Inventory::Consumed(Item* use)
{
	if (Quantity > 0)
	{
		for (int i = 0; i < 8; i++)
		{
			if (playerItems[i] != nullptr)
			{
				playerItems[i] = use;
				Quantity--;
				break;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

/*void Inventory::setInventory(std::string n, int q)
{
	
	Quantity = q;
}

std::string Inventory::getNameID()
{
	
}

int Inventory::getQuantity()
{
	return Quantity;
}*/

int Inventory::checkInventory(std::string n)
{
	for (int i = 0; i < MAX; i++)
	{
		if (playerItems[i] != nullptr)
		{
			if (playerItems[i]->getItemName() == n)
			{
				Quantity++;
			}
		}

		else
		{
			Quantity = 0;
		}
	}
	return Quantity; 

	/*if ("Raw Meat" && Quantity == 0)
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
	}*/
}

/*void Inventory::updateInventory()
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
}*/

Inventory::~Inventory()
{

}