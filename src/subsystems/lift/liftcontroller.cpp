#include "liftcontroller.h"

namespace lift_controller {
    float LiftController::getLeftSensVal() {
        float val = 0.0;
        if (lift->getLeftRot() != nullptr) {
            val = lift->getLeftRot()->get_position();
        } else {
            if (lift->getLeftMotors().size() != 0) {
                val = getAvgLeftSensVal();
            }
        }
        return val;
    }

    float LiftController::getRightSensVal() {
        float val = 0.0;
        if (lift->getRightRot() != nullptr) {
            val = lift->getRightRot()->get_position();
        } else {
            if (lift->getRightMotors().size() != 0) {
                val = getAvgRightSensVal();
            }
        }
        return val;
    }

    float LiftController::getAvgLeftSensVal() {
        float sum = 0.0;

        for (pros::Motor *motor : lift->getLeftMotors()) {
            sum += motor->get_position();
        }

        return sum / lift->getLeftMotors().size();
    }

    float LiftController::getAvgRightSensVal() {
        float sum = 0.0;

        for (pros::Motor *motor : lift->getRightMotors()) {
            sum += motor->get_direction();
        }

        return sum / lift->getRightMotors().size();
    }
}