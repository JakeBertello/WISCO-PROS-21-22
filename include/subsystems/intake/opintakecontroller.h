#ifndef WISCOPROS2122_SUBSYSTEMS_INTAKE_OPINTAKECONTROLLER_H_
#define WISCOPROS2122_SUBSYSTEMS_INTAKE_OPINTAKECONTROLLER_H_

#include "main/main.h"
#include "intakecontroller.h"
#include "misc/controllerinputs.h"
#include "misc/inputconverter.h"

namespace op_intake_controller {

    enum motors_on_side {
        LEFT,
        RIGHT,
        BOTH
    };

    class OpIntakeController : public intake_controller::IntakeController {
     public:
        OpIntakeController(intake::Intake *intake, pros::Controller *controller) : IntakeController(intake) {
            this->controller = controller;
        }

        void setIntakeUpAndDownButtons(controller_input up, controller_input down);
        void setIntakeUpAndDownJoy(controller_input joy);

     private:
        motors_on_side hasMotors();
        void setMotors(int voltage);
        void setMotorToJoy();
        bool isJoy(controller_input input);

        pros::Controller *controller;
        input_converter::InputConverter& inputConverter = input_converter::InputConverter::getInstance();
    };
}

#endif  // WISCOPROS2122_SUBSYSTEMS_INTAKE_OPINTAKECONTROLLER_H_