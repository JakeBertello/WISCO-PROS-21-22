#include "pidcontroller.h"
#include "config/driveconfig.h"

namespace pid_controller {
    float PIDController::setPID(float target, float currVal) {
        pid->target = target;
        pid->currVal = currVal;
    
        pid->dT = (pros::c::millis() - pid->prevT) / 1000;
        pid->prevT = pros::c::millis();

        pid->error = target - pid->currVal;

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

        drive_config::positionTrackerController.updatePosition();
        pros::lcd::print(0, "X = %8.4f", drive_config::positionTracker.currX);
        pros::lcd::print(1, "Y = %8.4f", drive_config::positionTracker.currY);
        pros::lcd::print(2, "A = %8.4f", drive_config::positionTracker.currA*(180 / (float)okapi::pi));
        pros::lcd::print(3, "target = %8.4f", target);
        pros::lcd::print(4, "error = %8.4f", pid->error);
        pros::lcd::print(5, "currVal = %8.4f", currVal);
        return (pid->kP*pid->error + pid->kI*pid->integral + pid->kD*pid->derivative + pid->kC);
    }

    void PIDController::resetPID() {
        pid->prevError = 0;
        pid->integral = 0;
        pid->derivative = 0;
        pid->prevT = 0;
        pid->dT = 0;
        pid->target = 0;
    }
}