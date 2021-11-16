#include "subsystems/lift/opliftcontroller.h"

namespace op_lift_controller {

    void OpLiftController::setLiftUpAndDownButton(controller_input up, controller_input down) {
        if (controller->get_digital(inputConverter.convertButton(up))) {
            setMotors(127);
        } else if (controller->get_digital(inputConverter.convertButton(down))) {
            setMotors(-127);
        } else {
            setMotors(0);
        }
    }

    void OpLiftController::setLiftUpAndDownJoy(controller_input joy) {
        motors_on_side side = hasMotors();
        switch (side) {
            case BOTH:
                for (pros::Motor *motor : lift->getLeftMotors()) {
                    *motor = controller->get_analog(inputConverter.convertJoy(joy));
                }

                for (pros::Motor *motor : lift->getRightMotors()) {
                    *motor = controller->get_analog(inputConverter.convertJoy(joy));
                }
                break;
            
            case LEFT:
                for (pros::Motor *motor : lift->getLeftMotors()) {
                    *motor = controller->get_analog(inputConverter.convertJoy(joy));
                }
                break;
            
            case RIGHT:
                for (pros::Motor *motor : lift->getRightMotors()) {
                    *motor = controller->get_analog(inputConverter.convertJoy(joy));
                }
                break;
        }
    }

    void OpLiftController::setMotors(int voltage) {
        motors_on_side side = hasMotors();
        switch (side) {
            case BOTH:
                for (pros::Motor *motor : lift->getLeftMotors()) {
                    *motor = voltage;
                }

                for (pros::Motor *motor : lift->getRightMotors()) {
                    *motor = voltage;
                }
                break;
            
            case LEFT:
                for (pros::Motor *motor : lift->getLeftMotors()) {
                    *motor = voltage;
                }
                break;
            
            case RIGHT:
                for (pros::Motor *motor : lift->getRightMotors()) {
                    *motor = voltage;
                }
                break;
        }
    }

    motors_on_side OpLiftController::hasMotors() {
        motors_on_side side;
        if (lift->getLeftMotors().size() > 0 && lift->getRightMotors().size() > 0) {
            side = BOTH;
        } else if (lift->getLeftMotors().size() > 0) {
            side = LEFT;
        } else if (lift->getRightMotors().size() > 0) {
            side = RIGHT;
        }
        return side;
    }

    bool OpLiftController::isJoy(controller_input input) {
        bool isJoy = false;
        if (input == LJOYX || input == LJOYY || input == RJOYX || input == RJOYY) {
            isJoy = true;
        }
        return isJoy;
    }
}