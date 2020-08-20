#include "Poison.h"
#include "Player.h"
#include <iostream>

using namespace std;

Poison::Poison()
{
	Poisoned = 'P';
}

void Poison::setPoison()
{
	int seconds = 0;
	while (true)
	{
		Player Status;
		cout << "Poisoned" << endl;
		Status.SetH(h);
		this->SetD(3);
		Status.SetH(h - 3);
		this->GetH();
		break;
		Sleep(1000);
		seconds++;
		if (seconds == 10)
		{
			Status.SetH(h);
			this->SetD(3);
			Status.SetH(h - 3);
			this->GetH();
			break;
			Sleep(1000);
			seconds++;
			if (seconds == 20)
			{
				Status.SetH(h);
				this->SetD(3);
				Status.SetH(h - 3);
				this->GetH();
				break;
				Sleep(1000);
				seconds++;
				if (seconds == 30)
				{
					Status.SetH(h);
					this->SetD(3);
					Status.SetH(h - 3);
					this->GetH();
					break;
					Sleep(1000);
					seconds = 0;
					break;
				}
			}
		}
	}
}

char Poison::getPoison()
{
	return Poisoned;
}

Poison::~Poison()
{

}