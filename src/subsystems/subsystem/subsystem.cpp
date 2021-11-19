#include "subsystems/subsystem/subsystem.h"

namespace subsystem {
    SubsystemBuilder Subsystem::build() {
        return SubsystemBuilder();
    }

    std::vector<pros::Motor*> Subsystem::getLeftMotors() {
        return Subsystem::leftMotors;
    }

    std::vector<pros::Motor*> Subsystem::getRightMotors() {
        return Subsystem::rightMotors;
    }

    pros::Rotation* Subsystem::getLeftRot() {
        return Subsystem::leftRot;
    }

    pros::Rotation* Subsystem::getRightRot() {
        return Subsystem::rightRot;
    }
}