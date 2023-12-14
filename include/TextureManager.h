#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <string>

class TextureManager {
public:
    static SDL_Texture *loadTexture(std::string fileName);
    static void draw(SDL_Texture *texture, SDL_Rect srcR, SDL_Rect destR);
    static void draw_null_src(SDL_Texture *texture, SDL_Rect destR);
};

