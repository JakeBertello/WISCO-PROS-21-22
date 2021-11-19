#ifndef WISCOPROS2122_PID_PID_H_
#define WISCOPROS2122_PID_PID_H_

#include "main/main.h"

namespace pid {

    class PID {
    public: 
        PID(float kP, float kI, float kD, float kC, float intLimit, float lIntBound, float uIntBound) {
            this->kP = kP;
            this->kI = kI;
            this->kD = kD;
            this->kC = kC;
            this->intLimit = intLimit;
            this->lIntBound = lIntBound;
            this->uIntBound = uIntBound;
            target = 0;
            sensVal = 0;
            error = 0;
            prevError = 0;
            integral = 0;
            derivative = 0;
            dT = 0;
            prevT = 0;
            changeConstantDirection = false;
            currentC = 0;
        }

        float kP;
        float kI;
        float kD;
        float kC;

        float intLimit;
        float lIntBound;
        float uIntBound;

        float target;
        float sensVal;

        float error;
        float prevError;

        float integral;
        float derivative;

        float dT;
        float prevT;

        bool changeConstantDirection;
        float currentC;
    };
}


#endif  // WISCOPROS2122_PID_PID_H_