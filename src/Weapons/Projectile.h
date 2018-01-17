#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED
#include <SFML\Graphics.hpp>

class Projectile
{
    public:
		Projectile(const sf::Vector2f& position, float yaw, float projectileSpeed, sf::Vector2f projectileSize);

    public:
        void update(float angle, float dt);
		void drawBullet(sf::RenderTarget& renderer);
		sf::FloatRect globalBounds();
		bool isDed(); //determing if the bullet is "dead" or "alive"(it destroys it in weapon class)

		sf::Vector2f projectileVelocity;
		sf::RectangleShape projectileRec;
	    sf::Texture projectileTexture;

		float ageLimit = 1; //age limit
		float age = 0; //current age
		bool isHit = false;
};

#endif // BULLET_H_INCLUDED
