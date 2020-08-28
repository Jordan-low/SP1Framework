#include "Sound.h"
#include <windows.h>
#include <iostream>

using namespace std;

void Sound::sound()
{

	bool music = PlaySound(TEXT("C:\\Users\\chong\\Documents\\School Stuff\\DM2196-STUDIO PROJECT 1\\SP1\\SP1Framework\\SP1Framework\\sound.wav"), NULL, SND_ASYNC);
	
}
