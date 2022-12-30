#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <vector>
#include "Global.hpp"
#include "Player.hpp"

struct Level {

// image sketch
sf::Image levelImage;

// wall texture and sprite
sf::Texture wallTexture;
sf::Sprite wallTile;

// map
Tile map[MAP_HE][MAP_WI];

// methods
Level(std::string, Player&);
~Level();

void drawMap(sf::RenderWindow&);
sf::Vector2f map_collision(sf::Vector2f, const std::vector<Tile>&); // returns direction

};