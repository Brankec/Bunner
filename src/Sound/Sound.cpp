#include "Sound.h"



Sound::Sound(sf::SoundBuffer& soundBuffer, int volume)
{
	sound.setBuffer(soundBuffer);
	sound.setVolume(volume);
	sound.play();
}

bool Sound::isSoundStop()
{
	if (sound.getStatus() == sound.Stopped)
		return true;

	else
		return false;
}

