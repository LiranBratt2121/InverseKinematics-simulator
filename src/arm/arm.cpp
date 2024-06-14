#include "arm/arm.h"

Arm::Arm(const float len1, const float len2, Vector2d &desiredPosition) 
    : m_len1(len1), m_len2(len2), m_desiredPosition(desiredPosition), m_inverseKinematics(len1, m_len2, desiredPosition) {}

void Arm::Update() {
    m_inverseKinematics.Solve(m_pivot1Deg, m_pivot2Deg);

    float m_part1X = m_len1 * cos(m_pivot1Deg * TO_RADS);
    float m_part1Y = m_len1 * sin(m_pivot1Deg * TO_RADS);

    float m_part2X = m_len2 * cos(m_pivot2Deg * TO_RADS);
    float m_part2Y = m_len2 * sin(m_pivot2Deg * TO_RADS);

    m_part1.Update(m_part1X, m_part1Y);
    m_part2.Update(m_part2X, m_part2Y);
}

const Vector2d& Arm::GetPart1() const {
    return m_part1;
}

const Vector2d& Arm::GetPart2() const {
    return m_part2;
}

void Arm::SetDesiredPosition(const Vector2d &desiredPosition) {
    m_desiredPosition.Update(desiredPosition);
}

const Vector2d& Arm::GetDesiredPosition() const {
    return m_desiredPosition;
}

