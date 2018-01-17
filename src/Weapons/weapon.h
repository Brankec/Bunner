#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include "Projectile.h"

#pragma once
class weapon
{
public:
	weapon();

public:
	//asthetics
	int animationSequence;
	sf::Texture weaponTexture;
	sf::RectangleShape weaponRec;
	sf::SoundBuffer weaponSound, weaponReloadSound;
	sf::Sound shootSound, reloadSound;


	//functionality
	int damage;
	float timeBetweenShots = 0;
	float reloadTime = 0;
	float projectileSpeed;
	int amountShots;
	int ammo;
	sf::Vector2f projectileSize;

	void fire(const sf::Vector2f& playerPosition, float angle);
	void draw(sf::RenderTarget& renderer);
	void update(float angle, float dt);
	void age(float dt);
	sf::FloatRect projectileGlobalBounds();
	void bulletHit(sf::RectangleShape object);

public:
	std::vector<Projectile> projectiles;
	float time = 0;
	float delayTime = 0;
};

