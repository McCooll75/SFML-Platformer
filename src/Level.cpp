#include "Level.hpp"

Level::Level(std::string levelPath, Player& player) {
    if(!levelImage.loadFromFile(levelPath)){
        cout << "Couldn't load " << levelPath << endl;
    }

    for (unsigned x = 0; x < MAP_WI; x++){
        for (unsigned y = 0; y < MAP_HE; y++)
        {   
            sf::Color pixel = levelImage.getPixel(x, y);

            if (pixel == sf::Color(255, 255, 255)){
                map[y][x] = Tile::Wall;
                cout << y << endl;
            }

            else if (pixel == sf::Color(255, 0, 0)){
                player.setPosition(sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE));
            }

            else {
                map[y][x] = Tile::Void;
            }
        }
    }
}

Level::~Level() {

}