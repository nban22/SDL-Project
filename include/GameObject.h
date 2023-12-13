#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <string>
#include <iostream>

class GameObject
{
private:
    int m_x;
    int m_y;

    int m_srcWidth;
    int m_srcHeight;

    SDL_Texture *m_texture;
    SDL_Rect m_srcR, m_destR;
public:
    GameObject(std::string textureSheet, int x, int y);
    GameObject(std::string textureSheet, int x, int y, int srcWidth, int srcHeight);

    void update();
    void render();
};
