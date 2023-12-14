#pragma once

#include <iostream>

class Vector2D {
    float m_a;
    float m_b;
public:

    Vector2D();
    Vector2D(float a, float b);

    float getA() const { return m_a; }
    float getB() const { return m_b; }
    void setA(float a) { m_a = a; }
    void setB(float b) { m_b = b; }

    Vector2D& add(const Vector2D& vec);
    Vector2D& subtract(const Vector2D& vec);

    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;

    Vector2D& operator+=(const Vector2D& vec);
    Vector2D& operator-=(const Vector2D& vec);

    Vector2D operator*(int i) const;
    friend Vector2D operator*(int i, const Vector2D& vec);
    Vector2D& operator*=(int i);

    Vector2D& operator++();
    Vector2D operator++(int);
    Vector2D& operator--();
    Vector2D operator--(int);

    Vector2D& zero();

    friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);
};
