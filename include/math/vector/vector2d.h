#pragma once

#include <cmath>
#include <string>
#include <sstream>

#include "math/constants.h"

struct Vector2d {
    Vector2d();
    Vector2d(float x, float y);
    Vector2d(const Vector2d& other);

    void Update(float x, float y);
    void Update(const Vector2d& other);

    Vector2d operator+(const Vector2d& other) const;
    Vector2d operator-(const Vector2d& other) const;
    
    float GetRealArgument() const;
    float GetArgument() const;
    float GetLength() const;

    std::string ToString() const;
    
    float m_x, m_y;
};
