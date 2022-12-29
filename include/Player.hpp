#pragma once

#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Player {
sf::Texture texture;
sf::Sprite body;
sf::Vector2f velocity;

public:
    Player(sf::Vector2f);
    ~Player();

    bool isOnFloor();
    void control();
    void gravity();
    void move(float&);
    void animate();
    void drawBody(sf::RenderWindow&);
};