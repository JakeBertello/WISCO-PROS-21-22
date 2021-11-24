#include "pidcontroller.h"
#include "config/driveconfig.h"

namespace pid_controller {
    float PIDController::setPID(float target, float currVal) {
        pid->target = target;
        pid->currVal = currVal;
    
        pid->dT = (pros::c::millis() - pid->prevT) / 1000;
        pid->prevT = pros::c::millis();

        pid->error = target - currVal;
        printf("errorUsingParams = %f\r\n", target - currVal);
        printf("errorFromPid = %f\r\n", pid->error);
        if (fabs(pid->error) > pid->lIntBound && fabs(pid->error) < pid->uIntBound)
        {
            pid->integral += pid->error * pid->dT;
        }

        if (pid->integral > pid->intLimit)
        {
            pid->integral = pid->intLimit;
        }
        else if (pid->integral < -pid->intLimit)
        {
            pid->integral = -pid->intLimit;
        }

        if (pid->error == 0)
        {
            pid->integral = 0;
        }

        pid->derivative = (pid->error - pid->prevError) * pid->dT;
        pid->prevError = pid->error;
        printf("errorAtEndOfLoop = %f\r\n", pid->error);
        return (pid->kP * pid->error + pid->kI * pid->integral + pid->kD * pid->derivative + pid->kC);
    }

    void PIDController::resetPID() {
        pid->kP = pid->kP;
        pid->kI = pid->kI;
        pid->kD = pid->kD;
        pid->kC = pid->kC;
        pid->intLimit = pid->intLimit;
        pid->lIntBound = pid->lIntBound;
        pid->uIntBound = pid->uIntBound;
        pid->target = 0;
        pid->currVal = 0;
        pid->error = 0;
        pid->prevError = 0;
        pid->integral = 0;
        pid->derivative = 0;
        pid->dT = 0;
        pid->prevT = 0;
        pid->changeConstantDirection = false;
        pid->currentC = 0;
    }
}