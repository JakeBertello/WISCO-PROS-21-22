#include "subsystems/drive/drivecontroller.h"

namespace drive_controller {
    float DriveController::getLeftSensVal() {
        float val = 0.0;
        if (_drive->getLeftRot() != nullptr) {
            val = _drive->getLeftRot()->get_position();
        } else {
            if (_drive->getLeftMotors().size() != 0) {
                val = getAvgLeftSensVal();
            }
        }
        return val;
    }

    float DriveController::getRightSensVal() {
        float val = 0.0;
        if (_drive->getRightRot() != nullptr) {
            val = _drive->getRightRot()->get_position();
        } else {
            if (_drive->getRightMotors().size() != 0) {
                val = getAvgRightSensVal();
            }
        }
        return val;
    }

    float DriveController::getStrafeSensVal() {
        float val = 0.0;
        if (_drive->getStrafeRot() != nullptr) {
            val = _drive->getStrafeRot()->get_position();
        } else {
            if (_drive->getStrafeMotors().size() != 0) {
                val = getAvgStrafeSensVal();
            }
        }
        return val;
    }

    float DriveController::getImuSensVal() {
        float val = 0.0;
        if (_drive->getImu() != nullptr) {
            val = _drive->getImu()->get_heading();
        }
        return val;
    }

    float DriveController::getLeftDistSensVal() {
        float val = 0.0;
        if (_drive->getLeftDistance() != nullptr) {
            val = _drive->getLeftDistance()->get();
        }
        return val;
    }

    float DriveController::getRightDistSensVal() {
        float val = 0.0;
        if (_drive->getRightDistance() != nullptr) {
            val = _drive->getRightDistance()->get();
        }
        return val;
    }

    float DriveController::getAvgLeftSensVal() {
        float sum = 0.0;

        for (pros::Motor* motor : _drive->getLeftMotors()) {
            sum += motor->get_position();
        }

        return sum / _drive->getLeftMotors().size();
    }

    float DriveController::getAvgRightSensVal() {
        float sum = 0.0;

        for (pros::Motor* motor : _drive->getRightMotors()) {
            sum += motor->get_position();
        }

        return sum / _drive->getRightMotors().size();
    }

    float DriveController::getAvgStrafeSensVal() {
        float sum = 0.0;

        for (pros::Motor* motor : _drive->getStrafeMotors()) {
            sum += motor->get_position();
        }

        return sum / _drive->getStrafeMotors().size();
    }
}