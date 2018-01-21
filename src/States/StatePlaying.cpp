#include "StatePlaying.h"

StatePlaying::StatePlaying(Game& game)
:   StateBase   (game)
{
	map.loadMap("Map1_background", "Map1_backgroundMain", "Map1_main", "Map1_foreground", 6, 9, { 32,32 });
}

void StatePlaying::handleEvent(sf::Event e)
{
	if (e.type == sf::Event::KeyPressed) //for switching betwen the menu and the game
	{
		if (e.key.code == sf::Keyboard::Escape)
		{
			openMenu = !openMenu;
		}
	}


	if (openMenu == false)
	{
		Camera::cameraZoom(e);
	}
	else
	{
		buttonPress(e); //checks what button was pressed
	}
}

void StatePlaying::handleInput()
{
	if (openMenu == false)
	{
		player.playerControl(); //all player controls
	}
}

void StatePlaying::update(sf::Time deltaTime)
{
	if (openMenu == false)
	{
		if (player.isFinished) //for loading other maps
		{
			static int level = 1;
			map.loadMap("Map" + std::to_string(1) + "_background", 
				        "Map" + std::to_string(1) + "_backgroundMain",
				        "Map" + std::to_string(1) + "_main", 
				        "Map" + std::to_string(1) + "_foreground", 
				        6, 9, { 32,32 });
			if (level < 2)
				level++;
			else
				level = 1;

			player.entityRec.setPosition(30, -200);
			player.isFinished = false;
		}

		player.playerUpdate(deltaTime.asSeconds());
		Camera::followPlayerSmooth(player.getPos(), deltaTime.asSeconds());
	}
	else
	{
		ButtonUpdate(player); //updates the button function
	}
}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{

}

void StatePlaying::render(sf::RenderTarget& renderer)
{
		renderer.setView(Camera::getView({ 10.f, 1.f })); //background scroll
		map.drawBackGround(renderer); //Background
		map.drawBackGroundMain(renderer, player);
		map.drawMain(renderer, player); //Main (player base)
		map.drawForeGround(renderer); //Foreground
		renderer.draw(player.entityRec); //player
		player.gun.draw(renderer); //projectiles
		renderer.setView(renderer.getDefaultView()); //resets the view to default state

		if (openMenu)
			renderMenu(renderer);
}
