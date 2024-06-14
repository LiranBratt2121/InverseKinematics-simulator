#pragma once

#include "math/vector/vector2d.h"
#include "math/kinematics/inverseKinematics.h"

class Arm {
    public:
        Arm(const float len1, const float len2, Vector2d &desiredPosition);
        void Update();
        const Vector2d& GetPart1() const;
        const Vector2d& GetPart2() const;
        const Vector2d& GetDesiredPosition() const;
        void SetDesiredPosition(const Vector2d &desiredPosition);
    private:
        InverseKinematics m_inverseKinematics;
        Vector2d m_desiredPosition;
        Vector2d m_part1;
        Vector2d m_part2;
        const float m_len1;
        const float m_len2;
        float m_pivot1Deg;
        float m_pivot2Deg;
};
