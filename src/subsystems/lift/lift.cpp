#include "lift.h"

namespace lift {
    LiftBuilder Lift::build() {
        return LiftBuilder();
    }

    std::vector<pros::Motor*> Lift::getLeftMotors() {
        return Lift::leftMotors;
    }

    std::vector<pros::Motor*> Lift::getRightMotors() {
        return Lift::rightMotors;
    }

    pros::Rotation* Lift::getLeftRot() {
        return Lift::leftRot;
    }

    pros::Rotation* Lift::getRightRot() {
        return Lift::rightRot;
    }
}