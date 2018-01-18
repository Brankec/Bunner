#include "EntitySound.h"



EntitySound::EntitySound(sf::SoundBuffer& soundBuffer, int volume)
{
	sound.setBuffer(soundBuffer);
	sound.setVolume(volume);
	sound.play();
}

bool EntitySound::isSoundStop()
{
	if (sound.getStatus() == sound.Stopped)
		return true;

	else
		return false;
}

