#pragma once

#include <SFML/Graphics.hpp>

class Player {
sf::Texture texture;
sf::Sprite body;
sf::Vector2i direction;
sf::Vector2f velocity;

public:
    Player(sf::Vector2f&);
    ~Player();
};