#include "Sound.h"
#include <windows.h>
#include <iostream>

using namespace std;

void Sound::sound()
{

	bool music = PlaySound(TEXT("sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
	
}
