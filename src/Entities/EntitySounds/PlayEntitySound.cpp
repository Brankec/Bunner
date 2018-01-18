#include "PlayEntitySound.h"



PlayEntitySound::PlayEntitySound()
{

}

void PlayEntitySound::playSound(int volume)
{
	if (timer > delay)
	{
		entitySound.emplace_back(soundBuffer, volume);
		timer = 0;
	}
}

void PlayEntitySound::update(float deltaTime)
{
	timer += deltaTime;
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

