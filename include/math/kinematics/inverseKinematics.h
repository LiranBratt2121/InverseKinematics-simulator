#include "math/vector/vector2d.h"

class InverseKinematics {
    public:
        InverseKinematics(const float len1, const float len2, const Vector2d& desiredPosition);
        void Solve(float& pivotAngle1, float& pivotAngle2);
    private:
        float GetAlpha();
        float GetBeta();
        float GetDesiredPosVectorDistance();
        float GetLambda();
        float GetTheta();

        const Vector2d& m_desiredPosition;
        const float m_len1, m_len2;
};