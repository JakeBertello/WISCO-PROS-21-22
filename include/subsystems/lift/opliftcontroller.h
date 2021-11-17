#ifndef WISCOPROS2122_SUBSYSTEMS_LIFT_OPLIFTCONTROLLER_H_
#define WISCOPROS2122_SUBSYSTEMS_LIFT_OPLIFTCONTROLLER_H_

#include "subsystems/subsystem/subsystemcontroller.h"
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

    class OpLiftController : public subsystem_controller::SubsystemController<OpLiftController> {
     public:
        OpLiftController(subsystem::Subsystem<lift::Lift> *lift, pros::Controller *controller) : SubsystemController<OpLiftController>(lift) {
            this->controller = controller;
        }

        void setLiftUpAndDownButtons(controller_input up, controller_input down);
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