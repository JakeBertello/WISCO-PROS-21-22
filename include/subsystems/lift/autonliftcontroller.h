#ifndef WISCOPROS2122_SUBSYSTEMS_LIFT_AUTONLIFTCONTROLLER_H_
#define WISCOPROS2122_SUBSYSTEMS_LIFT_AUTONLIFTCONTROLLER_H_

#include "main/main.h"
#include "subsystems/lift/liftcontroller.h"

namespace auton_lift_controller {
    class AutonLiftController : public lift_controller::LiftController {
     public:
        AutonLiftController(lift::Lift *lift, pros::Controller *controller) : LiftController(lift) {
            this->controller = controller;
        }

        void setHookersPos(float target, float speed);

     private:
        pros::Controller *controller;
    };
}

#endif  // WISCOPROS2122_SUBSYSTEMS_LIFT_AUTONLIFTCONTROLLER_H_