#include "subsystems/intake/opintakecontroller.h"

namespace op_intake_controller {

    void OpIntakeController::setIntakeUpAndDownButtons(controller_input up, controller_input down) {
        if (controller->get_digital(inputConverter.convertButton(up))) {
            setMotors(127);
        } else if (controller->get_digital(inputConverter.convertButton(down))) {
            setMotors(-127);
        } else {
            setMotors(0);
        }
    }

    void OpIntakeController::setIntakeUpAndDownJoy(controller_input joy) {
        motors_on_side side = hasMotors();
        switch (side) {
            case BOTH:
                for (pros::Motor *motor : intake->getLeftMotors()) {
                    *motor = controller->get_analog(inputConverter.convertJoy(joy));
                }

                for (pros::Motor *motor : intake->getRightMotors()) {
                    *motor = controller->get_analog(inputConverter.convertJoy(joy));
                }
                break;
            
            case LEFT:
                for (pros::Motor *motor : intake->getLeftMotors()) {
                    *motor = controller->get_analog(inputConverter.convertJoy(joy));
                }
                break;
            
            case RIGHT:
                for (pros::Motor *motor : intake->getRightMotors()) {
                    *motor = controller->get_analog(inputConverter.convertJoy(joy));
                }
                break;
        }
    }

    void OpIntakeController::setMotors(int voltage) {
        motors_on_side side = hasMotors();
        switch (side) {
            case BOTH:
                for (pros::Motor *motor : intake->getLeftMotors()) {
                    *motor = voltage;
                }

                for (pros::Motor *motor : intake->getRightMotors()) {
                    *motor = voltage;
                }
                break;
            
            case LEFT:
                for (pros::Motor *motor : intake->getLeftMotors()) {
                    *motor = voltage;
                }
                break;
            
            case RIGHT:
                for (pros::Motor *motor : intake->getRightMotors()) {
                    *motor = voltage;
                }
                break;
        }
    }

    motors_on_side OpIntakeController::hasMotors() {
        motors_on_side side;
        if (intake->getLeftMotors().size() > 0 && intake->getRightMotors().size() > 0) {
            side = BOTH;
        } else if (intake->getLeftMotors().size() > 0) {
            side = LEFT;
        } else if (intake->getRightMotors().size() > 0) {
            side = RIGHT;
        }
        return side;
    }

    bool OpIntakeController::isJoy(controller_input input) {
        bool isJoy = false;
        if (input == LJOYX || input == LJOYY || input == RJOYX || input == RJOYY) {
            isJoy = true;
        }
        return isJoy;
    }
}