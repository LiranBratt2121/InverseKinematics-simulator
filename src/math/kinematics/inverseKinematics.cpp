#include "math/kinematics/inverseKinematics.h"

InverseKinematics::InverseKinematics(const float len1, const float len2, const Vector2d& desiredPosition)
    : m_desiredPosition(desiredPosition), m_len1(len1), m_len2(len2) {}

void InverseKinematics::Solve(float& pivotAngle1, float& pivotAngle2) {
    pivotAngle1 = GetBeta();
    pivotAngle2 = GetAlpha();
}

float InverseKinematics::GetAlpha() {
    float numerator = (m_len1 * m_len1) + (m_len2 * m_len2) - pow(GetDesiredPosVectorDistance(), 2);
    float denominator = 2 * m_len1 * m_len2;
    return acos(numerator / denominator) * TO_DEGREES;
}

float InverseKinematics::GetBeta() {
    return GetLambda() + GetTheta();
}

float InverseKinematics::GetDesiredPosVectorDistance() {
    return m_desiredPosition.GetLength();
}

float InverseKinematics::GetLambda() {
    return 90 - m_desiredPosition.GetArgument();
}

float InverseKinematics::GetTheta() {
    float numerator = m_len2 * sin(GetAlpha() * TO_RADS);
    float denominator = GetDesiredPosVectorDistance();
    return asin(numerator / denominator) * TO_DEGREES;
}
