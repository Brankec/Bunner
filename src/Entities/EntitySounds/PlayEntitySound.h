#pragma once
#include "../../Sound/Sound.h"
#include <vector>

class PlayEntitySound
{
public:
	PlayEntitySound();

public:
	void playSound(int volume);

	void update(float deltaTime);

	void isSoundOver();

protected:
	sf::SoundBuffer soundBuffer;

private:
	std::vector<Sound> entitySound;
};

