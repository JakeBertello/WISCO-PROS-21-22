#include "pid.h"

namespace pid {
    PID::PID(float kP, float kI, float kD, float kC, float intLimit, float lIntBound, float uIntBound) {
        this->kP = kP;
        this->kI = kI;
        this->kD = kD;
        this->kC = kC;
        this->intLimit = intLimit;
        this->lIntBound = lIntBound;
        this->uIntBound = uIntBound;
        target = 0;
        currVal = 0;
        error = 0;
        prevError = 0;
        integral = 0;
        derivative = 0;
        dT = 0;
        prevT = 0;
        changeConstantDirection = false;
        currentC = 0;
    }
}