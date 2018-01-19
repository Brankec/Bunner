#pragma once
#include "../../Sound/Sound.h"
#include <vector>

class PlayWeaponSound
{
public:
	PlayWeaponSound();

public:
	void playSound(sf::SoundBuffer& soundBuffer, int volume);

	void update();

	void isSoundOver();

protected:
	sf::SoundBuffer soundBuffer;

private:
	std::vector<Sound> weaponSound;
};