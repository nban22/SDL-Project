#pragma once

#include "ECS.h"

class PositionComponent : public Component
{
private:
    int m_x;
    int m_y;

public:
    int getX() { return m_x; }
    int getY() { return m_y; }

    void init() override {
        m_x = 0;
        m_y = 0;
    }
    void update() override {
        m_x++;
        m_y++;
    }

    void setPos(int x, int y) {
        m_x = x;
        m_y = y;
    }
};