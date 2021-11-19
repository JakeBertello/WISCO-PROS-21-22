#include "drivecontroller.h"

namespace drive_controller {
    float DriveController::getLeftSensVal() {
        float val = 0.0;
        if (drive->getLeftRot() != nullptr) {
            val = drive->getLeftRot()->get_position();
        } else {
            if (drive->getLeftMotors().size() != 0) {
                val = getAvgLeftSensVal();
            }
        }
        return val;
    }

    float DriveController::getRightSensVal() {
        float val = 0.0;
        if (drive->getRightRot() != nullptr) {
            val = drive->getRightRot()->get_position();
        } else {
            if (drive->getRightMotors().size() != 0) {
                val = getAvgRightSensVal();
            }
        }
        return val;
    }

    float DriveController::getStrafeSensVal() {
        float val = 0.0;
        if (drive->getStrafeRot() != nullptr) {
            val = drive->getStrafeRot()->get_position();
        } else {
            if (drive->getStrafeMotors().size() != 0) {
                val = getAvgStrafeSensVal();
            }
        }
        return val;
    }

    float DriveController::getImuSensVal() {
        float val = 0.0;
        if (drive->getImu() != nullptr) {
            val = drive->getImu()->get_heading();
        }
        return val;
    }

    float DriveController::getLeftDistSensVal() {
        float val = 0.0;
        if (drive->getLeftDistance() != nullptr) {
            val = drive->getLeftDistance()->get();
        }
        return val;
    }

    float DriveController::getRightDistSensVal() {
        float val = 0.0;
        if (drive->getRightDistance() != nullptr) {
            val = drive->getRightDistance()->get();
        }
        return val;
    }
  
    void DriveController::resetDriveSens() {
        drive->getLeftRot()->reset();
        drive->getLeftRot()->reset_position();
        drive->getRightRot()->reset();
        drive->getRightRot()->reset_position();
        drive->getStrafeRot()->reset();
        drive->getStrafeRot()->reset_position();
    }

    float DriveController::getAvgLeftSensVal() {
        float sum = 0.0;

        for (pros::Motor *motor : drive->getLeftMotors()) {
            sum += motor->get_position();
        }

        return sum / drive->getLeftMotors().size();
    }

    float DriveController::getAvgRightSensVal() {
        float sum = 0.0;

        for (pros::Motor *motor : drive->getRightMotors()) {
            sum += motor->get_direction();
        }

        return sum / drive->getRightMotors().size();
    }

    float DriveController::getAvgStrafeSensVal() {
        float sum = 0.0;

        for (pros::Motor *motor : drive->getStrafeMotors()) {
            sum += motor->get_position();
        }

        return sum / drive->getStrafeMotors().size();
    }
}