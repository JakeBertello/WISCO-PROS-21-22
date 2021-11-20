#ifndef WISCOPROS2122_PID_PID_H_
#define WISCOPROS2122_PID_PID_H_

#include "main/main.h"

namespace pid {

    class PID {
    public: 
        PID(float kP, float kI, float kD, float kC, float intLimit, float lIntBound, float uIntBound);

        float kP;
        float kI;
        float kD;
        float kC;

        float intLimit;
        float lIntBound;
        float uIntBound;

        float target;
        float currVal;

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