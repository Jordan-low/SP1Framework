#include "Sound.h"
#include <windows.h>
#include <iostream>

using namespace std;

void Sound::bossPhase2()
{

	bool music = PlaySound(TEXT("boss phase2.wav"), NULL, SND_FILENAME | SND_ASYNC);
	
}
