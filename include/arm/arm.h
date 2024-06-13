#pragma once

#include "math/vector/vector2d.h"

class Arm {
    public:
        Arm(float len1, float len2, const Vector2d &desiredPosition);
        void Update();
        const Vector2d& GetPart1() const;
        const Vector2d& GetPart2() const;
        void SetDesiredPosition(const Vector2d &desiredPosition);
        const Vector2d& GetDesiredPosition() const;

    private:
        float GetAlpha();
        float GetBeta();
        float GetDesiredPosVectorDistance();
        float GetLambda();
        float GetTheta();

        float m_len1;
        float m_len2;
        Vector2d m_desiredPosition;
        Vector2d m_part1;
        Vector2d m_part2;
        float m_pivot1Deg;
        float m_pivot2Deg;
};
