#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "../Entities/Player.h"
#include "../Util/Camera.h"

#pragma once

class Map
{
public:
	Map(std::string fileNameFore, std::string fileNameMain, std::string fileNameBack, int n, int amountOfTiles, sf::Vector2i tileSize);

public:
	void loadTilesForeground();
	void drawForeGround(sf::RenderTarget& renderer);
	void loadTilesMain();
	void drawMain(sf::RenderTarget& renderer, Player& player);
	void loadTilesBackground();
	void drawBackGround(sf::RenderTarget& renderer);


	void setOriginCenter();
	sf::Vector2i Sprite_sheet_coordinates(int tileIndex);


public:
	int powOfN;
	int tileIndex = 0;
	sf::Texture tileTexture;
	sf::RectangleShape tile[3];  // 0) background, 1) main(playerbase, 2) foreground

	std::vector<std::vector<sf::Vector2i>> mapForeGround, mapBackGround, mapMain;
	std::vector<sf::Vector2i> tempMap;
	sf::Vector2i loadCounter;
	sf::Vector2i tileSize;
	int amountOfTiles;
	void Collision(Player &player);

	//open the file containing the tile name and tile positions
	std::ifstream openfileForeground;
	std::ifstream openfileMain;
	std::ifstream openfileBackground;

	//Collision GetCollision() { return Collision(tile[0]); }
};

