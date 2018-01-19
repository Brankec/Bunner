#include "PlayWeaponSound.h"



PlayWeaponSound::PlayWeaponSound()
{

}

void PlayWeaponSound::playSound(sf::SoundBuffer& soundBuffer, int volume)
{
	weaponSound.emplace_back(soundBuffer, volume);
}

void PlayWeaponSound::update()
{
	isSoundOver();
}

void PlayWeaponSound::isSoundOver()
{
	for (int i = 0; i < weaponSound.size(); i++)
	{
		if (weaponSound[i].isSoundStop())
		{
			weaponSound.erase(weaponSound.begin() + i);
		}
	}
}