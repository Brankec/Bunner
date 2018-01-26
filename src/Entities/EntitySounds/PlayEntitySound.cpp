#include "PlayEntitySound.h"



PlayEntitySound::PlayEntitySound()
{

}

void PlayEntitySound::playSound(int volume)
{
	entitySound.emplace_back(soundBuffer, volume);
}

void PlayEntitySound::update(float deltaTime)
{
	isSoundOver();
}

void PlayEntitySound::isSoundOver()
{
	for (int i = 0; i < entitySound.size(); i++)
	{
		if (entitySound[i].isSoundStop())
		{
			entitySound.erase(entitySound.begin() + i);
		}
	}
}

