#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Level.hpp"
#include "Global.hpp"

void set_tile_size(sf::Sprite& body){
    body.setScale(TILE_SIZE / TEXTURE_SIZE, TILE_SIZE / TEXTURE_SIZE);
}

// TODO : COLLISION

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 280), "SFML works!", sf::Style::Close);

    // player and level
    Player player;
    Level level("levels/1.png", player);

    float time;
    sf::Clock clock;
    while (window.isOpen())
    {
        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 1200;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        level.drawMap(window);

        player.drawBody(window);
        player.control();
        player.gravity();
        player.move(time);

        window.display();
    }

    return 0;
}