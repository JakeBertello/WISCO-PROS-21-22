#include "subsystems/subsystem/subsystemcontroller.h"

namespace subsystem_controller {
    float SubsystemController::getLeftSensVal() {
        float val = 0.0;
        if (subsystem->getLeftRot() != nullptr) {
            val = subsystem->getLeftRot()->get_position();
        } else {
            if (subsystem->getLeftMotors().size() != 0) {
                val = getAvgLeftSensVal();
            }
        }
        return val;
    }

    float SubsystemController::getRightSensVal() {
        float val = 0.0;
        if (subsystem->getRightRot() != nullptr) {
            val = subsystem->getRightRot()->get_position();
        } else {
            if (subsystem->getRightMotors().size() != 0) {
                val = getAvgRightSensVal();
            }
        }
        return val;
    }

    float SubsystemController::getAvgLeftSensVal() {
        float sum = 0.0;

        for (pros::Motor *motor : subsystem->getLeftMotors()) {
            sum += motor->get_position();
        }

        return sum / subsystem->getLeftMotors().size();
    }

    float SubsystemController::getAvgRightSensVal() {
        float sum = 0.0;

        for (pros::Motor *motor : subsystem->getRightMotors()) {
            sum += motor->get_direction();
        }

        return sum / subsystem->getRightMotors().size();
    }
}