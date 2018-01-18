#pragma once
#include "EntitySound.h"
#include <vector>

class PlayEntitySound
{
public:
	PlayEntitySound();

public:
	void playSound(int volume);

	void update(float deltaTime);

	void isSoundOver();

	float timer = 0.2, delay = 0.2;

protected:
	sf::SoundBuffer soundBuffer;

private:
	std::vector<EntitySound> entitySound;
};

