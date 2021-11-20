#ifndef WISCOPROS2122_PID_PID_H_
#define WISCOPROS2122_PID_PID_H_

#include "main/main.h"

namespace pid {

    class PID {
    public: 
        PID(float kP, float kI, float kD, float kC, float intLimit, float lIntBound, float uIntBound);

        float kP = 0;
        float kI = 0;
        float kD = 0;
        float kC = 0;

        float intLimit = 0;
        float lIntBound = 0;
        float uIntBound = 0;

        float target = 0;
        float currVal = 0;

        float error = 0;
        float prevError = 0;

        float integral = 0;
        float derivative = 0;

        float dT = 0;
        float prevT = 0;

        bool changeConstantDirection = 0;
        float currentC = 0;
    };
}


#endif  // WISCOPROS2122_PID_PID_H_