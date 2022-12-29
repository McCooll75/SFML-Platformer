#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

using std::endl;
using std::cout;

constexpr unsigned TILE_SIZE = 40;
constexpr unsigned TEXTURE_SIZE = 8;

void set_tile_size(sf::Sprite& body);