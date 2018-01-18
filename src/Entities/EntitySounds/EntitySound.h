#include <SFML/Audio.hpp>
#include <iostream>

#pragma once
class EntitySound  
{
public:
	EntitySound(sf::SoundBuffer& soundBuffer, int volume);

	bool isSoundStop();

private:
	sf::Sound sound;
};

