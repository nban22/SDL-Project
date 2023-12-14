#pragma once

#include <SDL.h>

#include <string>

#include "Components.h"
#include "../TextureManager.h"

class SpriteComponent : public Component
{
private:
    TransformComponent *m_transform;
    SDL_Texture *m_texture;
    SDL_Rect m_srcRect, m_destRect;

    std::string m_path;
public:
    SpriteComponent() = default;
    
    SpriteComponent(std::string path) {
        m_path = path;
        m_texture = TextureManager::loadTexture(path);
    }

    void init() override {
        m_transform = &m_entity->getComponent<TransformComponent>();

        m_srcRect = {0, 0, 32, 32};
        m_destRect = {0, 0, 256, 256};
    }
    void update() override {
        m_destRect.x = m_transform->m_position.getA();
        m_destRect.y = m_transform->m_position.getB();

    }
    void draw() override {
        TextureManager::draw_null_src(m_texture, m_destRect);
    }

    void setTexture(std::string path) {
        m_path = path;
        m_texture = TextureManager::loadTexture(path);
    }
    std::string getTexture() {
        return m_path;
    }
};