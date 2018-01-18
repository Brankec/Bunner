#include "Projectile.h"


Projectile::Projectile(const sf::Vector2f& position, float yaw, float projectileSpeed, sf::Vector2f projectileSize)
{
	projectileRec.setSize(projectileSize);
	projectileRec.setOrigin(projectileRec.getGlobalBounds().width / 2, projectileRec.getGlobalBounds().height / 2);

	projectileRec.setPosition(position);

	float x = sin(yaw) * projectileSpeed;
	float y = cos(yaw) * projectileSpeed;
	projectileVelocity = { x, y };
}


void Projectile::update(float angle, float dt)
{
	projectileRec.move(projectileVelocity * dt);
}

void Projectile::drawBullet(sf::RenderTarget& renderer)
{
	renderer.draw(projectileRec);
}

sf::FloatRect Projectile::globalBounds()
{
	return projectileRec.getGlobalBounds();
}

bool Projectile::isDed()
{
	if (age >= ageLimit || isHit)
		return true;
	else
		return false;
}


