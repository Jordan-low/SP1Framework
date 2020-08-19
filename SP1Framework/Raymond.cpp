#include "Raymond.h"
#include <ctime>
#include <stdlib.h> 
#include <iostream>

Raymond::Raymond()
{
	this->setEnemy('R');
	this->SetD(25);
	this->SetH(120);
	this->SetX(1);
	this->SetY(1);
}

void Raymond::Attack()
{
	this->beenHit();
}

void Raymond::Talk()
{
	int seconds = 0;
	char* text[4] = { "It seems like the person that I have been searching for have came to me instead, thank you for that.", "So...have you came to surrender?", "Why don't you join me and we can rule the world together.", "Actually nah, that's a bad idea. Only I can rule the world!" };
	while (true)
	{
		cout << text[0] << endl;
		seconds++;
		if (seconds == 3)
		{
			delete text[0];
			seconds = 0;
			cout << text[1] << endl;
			seconds++;
			if (seconds == 3)
			{
				delete text[1];
				seconds = 0;
				cout << text[2] << endl;
				seconds++;
				if (seconds == 3)
				{
					delete text[2];
					seconds = 0;
					cout << text[3] << endl;
					seconds++;
					if (seconds == 3)
					{
						delete text[3];
						seconds = 0;
					}
				}
			}
		}
	}
}

void Raymond::Damaged()
{
	this->Hit();
}

Raymond::~Raymond()
{
	
}