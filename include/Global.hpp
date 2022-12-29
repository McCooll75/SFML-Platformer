#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using std::endl;
using std::cout;

constexpr unsigned TILE_SIZE = 40;
constexpr unsigned TEXTURE_SIZE = 8;

constexpr unsigned MAP_HE = 7;
constexpr unsigned MAP_WI = 10;

void set_tile_size(sf::Sprite& body);

enum Tile {
    Void = 1,
    Wall
};