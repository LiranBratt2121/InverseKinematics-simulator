#pragma once

#include "math/vector/vector2d.h"

class Arm {
    public:
        Arm(float link1, float link2, Vector2d& desiredPosition);
        void Update();
        Vector2d& GetPart1();
        Vector2d& GetPart2();
        
    private:
        float GetDesiredPosVectorDistance();
        float GetAlpha();
        float GetBeta();
        float GetLambda();
        float GetTheta();

    private:
        Vector2d m_desiredPosition;
        Vector2d m_part1, m_part2;
        float m_len1, m_len2;
        float m_pivot1Deg, m_pivot2Deg;
};