#include <SFML/Audio.hpp>

#pragma once
class EntitySound  //we will deal with this later
{
public:
	EntitySound();
	~EntitySound();

protected:
	void loadWalkingSoundBuffers(std::string audioName);

private:
	sf::SoundBuffer entityWalkingBuffers[5];
	sf::Sound entityWalkingSounds[5];
};

