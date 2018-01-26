#pragma once
#include <SFML/Graphics.hpp>

class Level
{
public:
	Level()
	{
		Level_1();
	}

	void Level_1()
	{
		BackGround = "Level 1/Start_background";
		BackGroundMain = "Level 1/Start_backgroundMain";
		Main = "Level 1/Start_main";
		Interactable = "Level 1/Start_interactables";
		ForeGround = "Level 1/Start_foreground";

		gridSize = 6;
		amountOfTilesX = 24;
		tileSize = { 32, 32 };
		objectiveTileCoords = 736;
		whichLevel = 1;

		spawnPoint = { 30, 100 };
	}

	void Level_2()
	{
		BackGround = "Level 2/Map1_background";
		BackGroundMain = "Level 2/Map1_backgroundMain";
		Main = "Level 2/Map1_main";
		ForeGround = "Level 2/Map1_foreground";
		gridSize = 6;
		amountOfTilesX = 9;
		tileSize = { 32, 32 };
		objectiveTileCoords = 256;
		whichLevel = 2;

		spawnPoint = { 30, 100 };
	}

	void Level_3()
	{

	}

	std::string BackGround, BackGroundMain, Main, ForeGround, Interactable;
	int gridSize, amountOfTilesX;
	sf::Vector2i tileSize;
	int objectiveTileCoords;
	int whichLevel = 0;
	sf::Vector2f spawnPoint;
};