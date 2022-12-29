#include "Player.hpp"
#include "Global.hpp"

constexpr float WALK_SPEED = 1;
constexpr float GRAVITY_FORCE = 0.01;
constexpr float JUMP_FORCE = 1;

Player::Player() {
    texture.loadFromFile("assets/player-sheet.png");
    body.setTexture(texture);
    body.setTextureRect(sf::IntRect(0, 0, TEXTURE_SIZE, TEXTURE_SIZE));

    set_tile_size(body);
}

Player::~Player() {

}

void Player::setPosition(sf::Vector2f newPosition){
    body.setPosition(newPosition);
}

bool Player::isOnFloor(){
    return 0;
}

void Player::drawBody(sf::RenderWindow& window){
    window.draw(body);
}

void Player::control(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        velocity.x -= WALK_SPEED;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        velocity.x += WALK_SPEED;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and isOnFloor()){
        velocity.y -= JUMP_FORCE;
    }
}

void Player::gravity(){
    if(!isOnFloor()){
        velocity.y += GRAVITY_FORCE;
    }
}

void Player::move(float& time){
    body.move(velocity.x * time, velocity.y * time);
    velocity.x = 0;
}