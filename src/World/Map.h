
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "../Entities/Player.h"
#include "../Util/Camera.h"
#include "../World/Level.h"

#pragma once

class Map
{
public:
	Map();

public:
	void loadMap(Level& levelsPass);

	void loadTilesForeground();//for deocrations
	void drawForeGround(sf::RenderTarget& renderer);

	void loadTilesMain();//main player layer with all 4 collisions
	void drawMain(sf::RenderTarget& renderer, Player& player);

	void loadTilesBackgroundMain();//player background top collision
	void drawBackGroundMain(sf::RenderTarget & renderer, Player & player);

	void loadTilesBackground();//for decorations
	void drawBackGround(sf::RenderTarget& renderer);


	void setOriginCenter();
	sf::Vector2i Sprite_sheet_coordinates(int tileIndex);


public:
	Level* levels;
	int powOfN;
	int tileIndex = 0;
	int objectiveTileCoords = 0;
	sf::Texture tileTexture;
	sf::RectangleShape tile[4];  // 0) background, 1) background-main(only top has collision), 2) main(playerbase), 3) foreground

	std::vector<std::vector<sf::Vector2i>> mapForeGround, mapBackGround, mapMain, mapBackGroundMain;
	std::vector<sf::Vector2i> tempMap;
	sf::Vector2i loadCounter;
	sf::Vector2i tileSize;
	int amountOfTiles;
	void Collision(Player &player);
	void CollisionTopOnly(Player &player);
	void Objective(Player &player);
	void ProjectileCollision(Player &player);

	//open the file containing the tile name and tile positions
	std::ifstream openfileForeground;
	std::ifstream openfileMain;
	std::ifstream openfileBackgroundMain;
	std::ifstream openfileBackground;
};

