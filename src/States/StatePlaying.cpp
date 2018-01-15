#include "StatePlaying.h"

#include <iostream>

StatePlaying::StatePlaying(Game& game)
:   StateBase   (game), map("Map1_foreground", "Map1_main", "Map1_background", 6, 8, { 32,32 })
{
}

void StatePlaying::handleEvent(sf::Event e)
{
	Camera::cameraZoom(e);
}

void StatePlaying::handleInput()
{
	player.playerControl(); //all player controls
}

void StatePlaying::update(sf::Time deltaTime)
{
	player.playerUpdate(deltaTime.asSeconds());
	Camera::followPlayerSmooth(player.getPos(), deltaTime.asSeconds());
}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{

}

void StatePlaying::render(sf::RenderTarget& renderer)
{
	//std::cout << Camera::getView().getCenter().x << std::endl;

	renderer.setView(Camera::getView({10.f, 1.f})); //background scroll
	map.drawBackGround(renderer); //Background
	map.drawMain(renderer, player); //Main (player base)
	map.drawForeGround(renderer); //Foreground
	renderer.draw(player.entityRec);
	renderer.setView(renderer.getDefaultView());
}
