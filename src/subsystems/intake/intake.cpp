#include "intake.h"

namespace intake {
    IntakeBuilder Intake::build() {
        return IntakeBuilder();
    }

    std::vector<pros::Motor*> Intake::getLeftMotors() {
        return Intake::leftMotors;
    }

    std::vector<pros::Motor*> Intake::getRightMotors() {
        return Intake::rightMotors;
    }

    pros::Rotation* Intake::getLeftRot() {
        return Intake::leftRot;
    }

    pros::Rotation* Intake::getRightRot() {
        return Intake::rightRot;
    }
}