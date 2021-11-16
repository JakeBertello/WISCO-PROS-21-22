#ifndef WISCOPROS2122_SUBSYSTEMS_LIFT_OPLIFTCONTROLLER_H_
#define WISCOPROS2122_SUBSYSTEMS_LIFT_OPLIFTCONTROLLER_H_

#include "main/main.h"
#include "liftcontroller.h"
#include "misc/controllerinputs.h"
#include "misc/inputconverter.h"

namespace op_lift_controller {

    enum motors_on_side {
        LEFT,
        RIGHT,
        BOTH
    };

    class OpLiftController : public lift_controller::LiftController {
     public:
        OpLiftController(lift::Lift *lift, pros::Controller *controller) : LiftController(lift) {
            this->controller = controller;
        }

        void setLiftUpAndDownButton(controller_input up, controller_input down);
        void setLiftUpAndDownJoy(controller_input joy);

     private:
        motors_on_side hasMotors();
        void setMotors(int voltage);
        void setMotorToJoy();
        bool isJoy(controller_input input);

        pros::Controller *controller;
        input_converter::InputConverter& inputConverter = input_converter::InputConverter::getInstance();
    };
}

#endif  // WISCOPROS2122_SUBSYSTEMS_LIFT_OPLIFTCONTROLLER_H_