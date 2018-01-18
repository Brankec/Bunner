#include "Walking.h"

Walking::Walking(std::string audioName)
{
	soundBuffer.loadFromFile("res/entities/audio/" + audioName + ".ogg");
}
