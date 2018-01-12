#include <SFML\Graphics.hpp>
#include <iostream>
#include <array>
#include <cctype>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include "../Entities/Player.h"

#pragma once
class Map
{
public:
	Map(std::string fileNameFore, std::string fileNameBack, int n, int amountOfTiles, sf::Vector2i tileSize);

public:
	void loadTilesForeground();
	void loadTilesBackground();
	void drawForeGround(sf::RenderTarget& renderer, Player& player, bool(&isColliding)[4]);
	void drawBackGround(sf::RenderTarget& renderer);
	void setOriginCenter();
	sf::Vector2i Sprite_sheet_coordinates(int tileIndex);


public:
	int powOfN;
	int tileIndex = 0;
	sf::Texture tileTexture;
	sf::RectangleShape tile[2];

	std::vector<std::vector<sf::Vector2i>> mapForeGround, mapBackGround;
	std::vector<sf::Vector2i> tempMap;
	sf::Vector2i loadCounter;
	sf::Vector2i tileSize;
	int amountOfTiles;

	//open the file containing the tile name and tile positions
	std::ifstream openfileForeground;
	std::ifstream openfileBackground;
};

