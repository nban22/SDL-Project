#include "Vector2D.h"

Vector2D::Vector2D() : m_a(0), m_b(0) {}
Vector2D::Vector2D(float a, float b) : m_a(a), m_b(b) {}

Vector2D& Vector2D::add(const Vector2D& vec) {
    this->m_a += vec.m_a;
    this->m_b += vec.m_b;
    return *this;
}
Vector2D& Vector2D::subtract(const Vector2D& vec) {
    this->m_a -= vec.m_a;
    this->m_b -= vec.m_b;
    return *this;
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(this->m_a + other.m_a, this->m_b + other.m_b);
}
Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(this->m_a - other.m_a, this->m_b - other.m_b);
}

Vector2D& Vector2D::operator+=(const Vector2D& vec) {
    return this->add(vec);
}
Vector2D& Vector2D::operator-=(const Vector2D& vec) {
    return this->subtract(vec);
}

Vector2D Vector2D::operator*(int i) const {
    return Vector2D(this->m_a * i, this->m_b * i);
}
Vector2D operator*(int i, const Vector2D& vec) {
    return Vector2D(vec.m_a * i, vec.m_b * i);
}
Vector2D& Vector2D::operator*=(int i) {
    this->m_a *= i;
    this->m_b *= i;
    return *this;
}

Vector2D& Vector2D::operator++() {
    this->m_a++;
    this->m_b++;
    return *this;
}
Vector2D Vector2D::operator++(int) {
    Vector2D tmp(*this);
    operator++();
    return tmp;
}
Vector2D& Vector2D::operator--() {
    this->m_a--;
    this->m_b--;
    return *this;
}
Vector2D Vector2D::operator--(int) {
    Vector2D tmp(*this);
    operator--();
    return tmp;
}

Vector2D& Vector2D::zero() {
    this->m_a = 0;
    this->m_b = 0;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& vec) {
    stream << "(" << vec.m_a << ", " << vec.m_b << ")";
    return stream;
}





