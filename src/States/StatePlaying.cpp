#include "StatePlaying.h"

#include <iostream>

StatePlaying::StatePlaying(Game& game)
:   StateBase   (game), map("Map1_foreground", "Map1_background", 6, 8, { 32,32 })
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
	//std::cout << isColliding[0] << std::endl;
	player.playerUpdate();
	Camera::followPlayerSmooth(player.getPos(), deltaTime.asSeconds());
}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{

}

void StatePlaying::render(sf::RenderTarget& renderer)
{
	renderer.setView(Camera::getView());

	map.drawBackGround(renderer); //Background
	renderer.draw(player.entityRec);
	map.drawForeGround(renderer, player, player.isColliding); //Foreground
}
