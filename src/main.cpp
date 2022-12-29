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
    sf::RenderWindow window(sf::VideoMode(400, 300), "SFML works!", sf::Style::Close);

    // wall texture and sprite
    sf::Texture wallTexture;
    wallTexture.loadFromFile("assets/wall.png");

    sf::Sprite wallTile;
    wallTile.setTexture(wallTexture);
    set_tile_size(wallTile);

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

        for (unsigned x = 0; x < MAP_WI; x++)
        for (unsigned y = 0; y < MAP_HE; y++){
            if(level.map[y][x] == Tile::Wall){
                wallTile.setPosition(sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE));
                window.draw(wallTile);
            }
        }

        player.drawBody(window);
        player.control();
        player.gravity();
        player.move(time);

        window.display();
    }

    return 0;
}