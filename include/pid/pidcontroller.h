#ifndef PROS_PID_PIDCONTROLLER_H_
#define PROS_PID_PIDCONTROLLER_H_

#include "main/main.h"
#include "pid.h"

namespace pid_controller {
    class PIDController {
     public:
        PIDController(pid::PID *pid) {
            this->pid = pid;
        }

        float setPID(float target, float currVal);
        void resetPID();
    
     private:
        pid::PID *pid;
    };
}

#endif  // PROS_PID_PIDCONTROLLER_H_