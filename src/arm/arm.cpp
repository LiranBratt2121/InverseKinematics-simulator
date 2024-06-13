#include "arm/arm.h"

Arm::Arm(float len1, float len2, Vector2d &desiredPosition) 
    : m_len1(len1), m_len2(len2), m_desiredPosition(desiredPosition) {}

void Arm::Update(){
    m_pivot1Deg = GetBeta();
    m_pivot2Deg = GetAlpha();

    float m_part1X = m_len1 * cos(m_pivot1Deg * TO_RADS);
    float m_part1Y = m_len1 * sin(m_pivot1Deg * TO_RADS);

    float m_part2X = m_len2 * cos(m_pivot2Deg * TO_RADS);
    float m_part2Y = m_len2 * sin(m_pivot2Deg * TO_RADS);

    m_part1.Update(m_part1X, m_part1Y);
    m_part2.Update(m_part2X, m_part2Y);
}

Vector2d& Arm::GetPart1(){
    return m_part1;
}

Vector2d& Arm::GetPart2(){
    return m_part2;
}

float Arm::GetAlpha(){
    float numerator = (m_len1 * m_len1) + (m_len2 * m_len2) - pow(GetDesiredPosVectorDistance(), 2);
    float denominator = 2 * m_len1 * m_len2;
    return acos(numerator / denominator) * TO_DEGREES;
}

float Arm::GetBeta(){
    return GetLambda() + GetTheta();
}

float Arm::GetDesiredPosVectorDistance(){
    return m_desiredPosition.GetLength();
}


float Arm::GetLambda(){
    return 90 - m_desiredPosition.GetArgument();
}

float Arm::GetTheta(){
    float numerator = m_len2 * sin(GetAlpha() * TO_RADS);
    float denominator = GetDesiredPosVectorDistance();
    return asin(numerator / denominator) * TO_DEGREES;
}
