#pragma once

#include <SDL.h>

#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{
public:
    Vector2D m_position;
    Vector2D m_velocity;

    int m_speed = 3;


    TransformComponent() {}
    
    void init() override {
        m_position = Vector2D(300, 200);
        m_velocity = Vector2D(1, 1);
    }
    void update() override {
        m_position.setA(m_position.getA() + m_velocity.getA() * m_speed);
        m_position.setB(m_position.getB() + m_velocity.getB() * m_speed);
    }
}; 