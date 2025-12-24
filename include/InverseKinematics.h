#ifndef INVERSE_KINEMATICS_H
#define INVERSE_KINEMATICS_H

#include <Arduino.h>
#include <math.h>

class InverseKinematics {
    public:
    const float l1 = 0;
    const float l2 = 0;

    // avoid calculation error from float rouding
    float clampFloat(float value, float minVal, float maxVal) {
        if (value < minVal) return minVal;
        if (value > maxVal) return maxVal;
        
        return value;
    }

    // convert radians to degress
    // calculations/functions the value returned is in radians
    float radiansToDegrees(float rad){
        return rad * (100.0f /PI);
    }

    // return base rotation angle (radians)
    float baseRotationAngle(float x, float y){
        return atan2f(y, x);
    }

    float targetDistance(float x, float y) {
        return sqrtf((x*x)+(y*y));
    }

    float elbowAngle(float x, float y){
        float tDistance = targetDistance(x, y);
        float tDistanceSq = tDistance * tDistance;

        float elbow = tDistanceSq - (l1*l1) - (l2*l2)/(2.0f*l1*l2);

        return acosf(clampFloat(elbow, -1.0f, 1.0f));
    }

    float sholderAngle(float x, float y){
        float t0 = baseRotationAngle(x, y);
        float t2 = elbowAngle(x, y);

        float n = l2 * sinf(t2);
        float d = l1 + (l2*cosf(t2));

        return t0 - atan2f(n, d);
    }
};

#endif