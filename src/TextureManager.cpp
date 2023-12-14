#include "TextureManager.h"

#include <iostream>

#include "Game.h"

SDL_Texture *TextureManager::loadTexture(std::string fileName) {
    SDL_Texture* texture = IMG_LoadTexture(Game::g_renderer ,fileName.c_str());
    if (texture == nullptr) {
        std::cout << "TextureManager::loadTexture() Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return nullptr;
    }
    return texture;
}

void TextureManager::draw(SDL_Texture *texture, SDL_Rect srcR, SDL_Rect destR) {
    int errorCode = SDL_RenderCopy(Game::g_renderer, texture, &srcR, &destR);
    if (errorCode != 0) {
        std::cout << "TextureManager::draw() Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
}

void TextureManager::draw_null_src(SDL_Texture *texture, SDL_Rect destR) {
    int errorCode = SDL_RenderCopy(Game::g_renderer, texture, nullptr, &destR);
    if (errorCode != 0) {
        std::cout << "TextureManager::draw_null_src() Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
}
