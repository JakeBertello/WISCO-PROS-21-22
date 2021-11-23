#include "drive.h"

namespace drive {
    DriveBuilder Drive::build() {
        return DriveBuilder();
    }

    std::vector<pros::Motor*> Drive::getLeftMotors() {
        return Drive::leftMotors;
    }

    std::vector<pros::Motor*> Drive::getRightMotors() {
        return Drive::rightMotors;
    }

    std::vector<pros::Motor*> Drive::getStrafeMotors() {
        return Drive::strafeMotors;
    }

    pros::Rotation* Drive::getLeftRot() {
        return Drive::leftRot;
    }

    pros::Rotation* Drive::getRightRot() {
        return Drive::rightRot;
    }

    pros::Rotation* Drive::getStrafeRot() {
        return Drive::strafeRot;
    }

    pros::Imu* Drive::getImu() {
        return Drive::imu;
    }

    pros::Distance* Drive::getLeftDistance() {
        return Drive::leftDistance;
    }

    pros::Distance* Drive::getRightDistance() {
        return Drive::rightDistance;
    }

    pid_controller::PIDController* Drive::getDriveStraightPidController() {
        return Drive::driveStraightPidController;
    }

    pid_controller::PIDController* Drive::getTurnShortPidController() {
        return Drive::turnShortPidController;
    }

    pid_controller::PIDController* Drive::getTurnLongPidController() {
        return Drive::turnLongPidController;
    }

    pid_controller::PIDController* Drive::getDriveCorrectionPidController() {
        return Drive::driveCorrectionPidController;
    }
}