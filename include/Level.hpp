#pragma once

#include <SFML/Graphics.hpp>
#include "Global.hpp"
#include "Player.hpp"
#include <string>

struct Level {

sf::Image levelImage;
unsigned height;
unsigned width;

Level(std::string, Player&);
~Level();

Tile map[MAP_HE][MAP_WI];
};