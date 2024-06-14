#include "math/vector/vector2d.h"

Vector2d::Vector2d() : m_x(0), m_y(0) {}

Vector2d::Vector2d(float x, float y) : m_x(x), m_y(y) {}

void Vector2d::Update(float x, float y){
    m_x = x;
    m_y = y;
}

void Vector2d::Update(const Vector2d &other){
    m_x = other.m_x;
    m_y = other.m_y;
}

Vector2d Vector2d::operator+(const Vector2d &other) const{
    return Vector2d{m_x + other.m_x, m_y + other.m_y};
}

Vector2d Vector2d::operator-(const Vector2d &other) const{
    return Vector2d{m_x - other.m_x, m_y - other.m_y};
}

float Vector2d::GetRealArgument() const{
    if (m_x == 0 || m_y == 0) {
        return 0.0f;
    }

    return atan2(m_y, m_x) * TO_DEGREES;
}

float Vector2d::GetArgument() const{
    if (m_x == 0 || m_y == 0) {
        return 0.0f;
    }
    
    return atan(abs(m_y / m_x)) * TO_DEGREES;
}

float Vector2d::GetLength() const{
    return hypot(m_x, m_y);
}

std::string Vector2d::ToString() const {
  std::ostringstream ss;
  ss << "[" << m_x << ", " << m_y << "]";
  return ss.str();
}