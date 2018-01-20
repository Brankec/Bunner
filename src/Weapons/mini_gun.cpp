#include "mini_gun.h"

mini_gun::mini_gun(std::string audioName)
{
	m_gunBuffer.loadFromFile("res/entities/audio/WeaponSounds/" + audioName + ".ogg");
	defaults();
}

void mini_gun::fireGun(const sf::Vector2f & playerPosition, float angle)
{
	fire(playerPosition, angle, m_gunBuffer);
}

void mini_gun::defaults()
{
	projectileSpeed = 1000;
	projectileSize = { 5, 5 };
	delayTime = 0.2;
}

