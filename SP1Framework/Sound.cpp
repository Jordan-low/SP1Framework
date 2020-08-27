#include "Sound.h"
#include <windows.h>

void Sound::sound()
{
	bool music = PlaySound(L"../SP1Framework/sound.wav", NULL, SND_FILENAME | SND_ASYNC);
}
