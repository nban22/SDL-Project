#include "GameObject.h"

#include "TextureManager.h"
#include "Game.h"

GameObject::GameObject(std::string textureSheet, int x, int y) {
    m_texture = TextureManager::loadTexture(textureSheet);
    if (m_texture == nullptr) {
        std::cout << "GameObject::GameObject() Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }
    m_x = x;
    m_y = y;
    m_srcWidth = 256;
    m_srcHeight = 256;
}
GameObject::GameObject(std::string textureSheet, int x, int y, int srcWidth, int srcHeight) {
    m_texture = TextureManager::loadTexture(textureSheet);
    if (m_texture == nullptr) {
        std::cout << "GameObject::GameObject() Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }
    m_x = x;
    m_y = y;
    m_srcWidth = srcWidth;
    m_srcHeight = srcHeight;
}

void GameObject::update() {
    m_srcR = {0, 0, m_srcWidth, m_srcHeight};

    m_destR = {m_x, m_y, 256, 256};

    m_x++;
}

void GameObject::render() {
    int errorCode = SDL_RenderCopy(Game::g_renderer, m_texture, &m_srcR, &m_destR);
    if (errorCode != 0) {
        std::cout << "GameObject::render() Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
}