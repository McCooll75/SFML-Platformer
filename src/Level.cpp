#include "Level.hpp"

Level::Level(std::string levelPath, Player& player) {
    if(!levelImage.loadFromFile(levelPath)){
        cout << "Couldn't load " << levelPath << endl;
    }

    // sprites and textures set
    // wall
    wallTexture.loadFromFile("assets/wall.png");
    wallTile.setTexture(wallTexture);
    set_tile_size(wallTile);

    // render map from sketch.png
    for (unsigned x = 0; x < MAP_WI; x++){
        for (unsigned y = 0; y < MAP_HE; y++)
        {   
            sf::Color pixel = levelImage.getPixel(x, y);

            if (pixel == sf::Color(255, 255, 255)){
                map[y][x] = Tile::Wall;
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

void Level::drawMap(sf::RenderWindow& window){
    for (unsigned x = 0; x < MAP_WI; x++){
        for (unsigned y = 0; y < MAP_HE; y++){
            if(map[y][x] == Tile::Wall){
                wallTile.setPosition(sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE));
                window.draw(wallTile);
            }
        }
    }
}

sf::Vector2f Level::map_collision(sf::Vector2f objectPosition, const std::vector<Tile>& collidableTiles){
    float tileX = objectPosition.x / TILE_SIZE;
    float tileY = objectPosition.y / TILE_SIZE;

    for(unsigned char i = 0; i < 4; i++){
        int x;
        int y;

        switch (i)
        {
        case 0: //Top left tile
            x = floor(tileX);
            y = floor(tileY);

            break;
        
        case 1: //Top right tile
            x = ceil(tileX);
            y = floor(tileY);

            break;
        
        case 2: // Bottom left tile
            x = floor(tileX);
            y = ceil(tileY);

            break;
        
        case 3: // Bottom right tile
            x = ceil(tileX);
            y = ceil(tileY);

            break;
        }

        
    }
}