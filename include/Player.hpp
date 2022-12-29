#pragma once

#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Player {
sf::Texture texture;
sf::Sprite body;
sf::Vector2f velocity;

public:
    Player();
    ~Player();

    void setPosition(sf::Vector2f);
    bool isOnFloor();
    void control();
    void gravity();
    void move(float&);
    void animate();
    void drawBody(sf::RenderWindow&);
};