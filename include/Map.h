#pragma once

#include "Game.h"

class Map
{
private:
    SDL_Rect m_srcR, m_destR;
    SDL_Texture *m_dirt;
    SDL_Texture *m_grass;
    SDL_Texture *m_water;

    int m_map[20][25];
public:
    Map();
    ~Map();

    void loadMap(int arr[20][25]);
    void drawMap();
};