#pragma once

#include "../Game.h"
#include "ECS.h"
#include "Components.h"

#include <iostream>

class KeyboardController : public Component
{    
public:
    TransformComponent* m_transform;

    void init() override {
        m_transform = &m_entity->getComponent<TransformComponent>();
        m_transform->m_velocity.setA(0);
        m_transform->m_velocity.setB(0);
    }

    void update() override {
        if (Game::g_event.type == SDL_KEYDOWN) {
            switch(Game::g_event.key.keysym.sym) {
                case SDLK_RIGHT:
                    m_transform->m_velocity.setA(1);
                    break;
                case SDLK_UP:
                    m_transform->m_velocity.setB(-1);
                    break;
                case SDLK_LEFT:
                    m_transform->m_velocity.setA(-1);
                    break;
                case SDLK_DOWN:
                    m_transform->m_velocity.setB(1);
                    break;
                default:
                    break;
            }
        }
        if (Game::g_event.type == SDL_KEYUP) {
            switch(Game::g_event.key.keysym.sym) {
                case SDLK_RIGHT:
                    m_transform->m_velocity.setA(0);
                    break;
                case SDLK_UP:
                    m_transform->m_velocity.setB(0);
                    break;
                case SDLK_LEFT:
                    m_transform->m_velocity.setA(0);
                    break;
                case SDLK_DOWN:
                    m_transform->m_velocity.setB(0);
                    break;
                default:
                    break;
            }
        }
    }
};