#include <SFML/Audio.hpp>
#include <iostream>

#pragma once
class Sound  
{
public:
	Sound(sf::SoundBuffer& soundBuffer, int volume);

	bool isSoundStop();

private:
	sf::Sound sound;
};

