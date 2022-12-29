#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Global.hpp"

void set_tile_size(sf::Sprite& body){
    body.setScale(TILE_SIZE / TEXTURE_SIZE, TILE_SIZE / TEXTURE_SIZE);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 300), "SFML works!", sf::Style::Close);

    Player player(sf::Vector2f(0,0));

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

        player.drawBody(window);
        player.control();
        player.gravity();
        player.move(time);

        window.display();
    }

    return 0;
}