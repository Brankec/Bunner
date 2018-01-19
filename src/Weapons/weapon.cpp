#include "weapon.h"

weapon::weapon()
{
}

void weapon::fire(const sf::Vector2f& playerPosition, float angle, sf::SoundBuffer& soundBuffer)
{

	float m_yaw = (180.0f - angle) / 180.0f * 3.14159265358979;

	int speed = 5;
	if (time > delayTime)
	{
		weaponSound.playSound(soundBuffer, 30);
		projectiles.emplace_back(playerPosition, m_yaw, projectileSpeed, projectileSize);
		time = 0;
	}
}

void weapon::draw(sf::RenderTarget& renderer)
{
	for (auto& projectile : projectiles)
	{
		projectile.drawBullet(renderer);
	}
}

void weapon::update(float angle, float dt)
{
	time += dt;
	for (auto& projectile : projectiles)
	{
		projectile.update(angle, dt);//update its position
	}
	age(dt);
}

void weapon::age(float dt)
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		projectiles[i].age += dt;
		if (projectiles[i].isDed())
		{
			projectiles.erase(projectiles.begin() + i);
		}
	}
}

sf::FloatRect weapon::projectileGlobalBounds()
{
	for (auto& projectile : projectiles)
	{
		return projectile.globalBounds();
	}
}

void weapon::bulletHit(sf::RectangleShape object)
{
	for (auto& projectile : projectiles)
	{
		if (projectile.globalBounds().intersects(object.getGlobalBounds()))
			projectile.isHit = true;
	}
}
