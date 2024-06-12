#pragma once

#include <cmath>

constexpr float TO_DEGREES = 180 / 3.14159;
constexpr float TO_RADS = 3.14159 / 180;

struct Vector2d {
    Vector2d();
    Vector2d(float x, float y);

    void Update(float x, float y);
    void Update(const Vector2d& other);

    Vector2d operator+(const Vector2d& other) const;
    Vector2d operator-(const Vector2d& other) const;
    
    float GetRealArgument() const;
    float GetArgument() const;
    float GetLength() const;
    
    float m_x, m_y;
};
