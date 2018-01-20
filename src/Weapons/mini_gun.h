#include "weapon.h"

#pragma once
class mini_gun : public weapon
{
public:
	mini_gun(std::string audioName);

	void fireGun(const sf::Vector2f& playerPosition, float angle);

	void defaults();

	sf::SoundBuffer m_gunBuffer;
};

