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
