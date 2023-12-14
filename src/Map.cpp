#include "Map.h"

#include "TextureManager.h"

int map_arr[20][25] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 2, 0, 0, 0, 2, 0, 2, 2, 2, 2, 0, 2, 0, 0, 0, 2, 0, 2, 2, 2, 2, 0, 0},
    {0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0},
    {0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0},
    {0, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 0, 0},
    {0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0},
    {0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0},
    {0, 0, 2, 0, 0, 0, 2, 0, 2, 2, 2, 2, 0, 2, 0, 0, 0, 2, 0, 2, 2, 2, 2, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

enum TileType {
    DIRT,
    GRASS,
    WATER
};

Map::Map() {
    m_dirt  = TextureManager::loadTexture("assets/dirt_92x92.png");
    m_grass = TextureManager::loadTexture("assets/grass_92x92.png");
    m_water = TextureManager::loadTexture("assets/water_92x92.png");

    loadMap(map_arr);

    m_srcR  = {0, 0, 92, 92};
    m_destR = {0, 0, 32, 32};
}

Map::~Map() {
    SDL_DestroyTexture(m_dirt);
    SDL_DestroyTexture(m_grass);
    SDL_DestroyTexture(m_water);
}

void Map::loadMap(int arr[20][25]) {
    for (int row = 0; row < 20; row++) {
        for (int column = 0; column < 25; column++) {
            m_map[row][column] = arr[row][column];
        }
    }
} 

void Map::drawMap() {
    TileType tileType;
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 25; col ++) {
            tileType = static_cast<TileType>(m_map[row][col]);
            m_destR.x = col * 32;
            m_destR.y = row * 32;
            switch (tileType) {
                case DIRT:
                    TextureManager::draw(m_dirt, m_srcR, m_destR);
                    break;
                case GRASS:
                    TextureManager::draw(m_grass, m_srcR, m_destR);
                    break;
                case WATER:
                    TextureManager::draw(m_water, m_srcR, m_destR);
                    break;
                default:
                    break;
            }
        }
    }

}