#include "opdrivecontroller.h"

namespace op_drive_controller {

    void OpDriveController::setDriveTank() {
        for (pros::Motor *motor : DriveController::drive->getLeftMotors()) {
            *motor = controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        }

        for (pros::Motor *motor : DriveController::drive->getRightMotors()) {
            *motor = controller->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        }
    }

    void OpDriveController::setDriveArcadeOneJoyRight() {
        for (pros::Motor *motor : DriveController::drive->getLeftMotors()) {
            *motor = controller->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) + controller->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        }

        for (pros::Motor *motor : DriveController::drive->getRightMotors()) {
            *motor = controller->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) - controller->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        }
    }

    void OpDriveController::setDriveArcadeOneJoyLeft() {
        for (pros::Motor *motor : DriveController::drive->getLeftMotors()) {
            *motor = controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) + controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        }

        for (pros::Motor *motor : DriveController::drive->getRightMotors()) {
            *motor = controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) - controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        }
    }    

    void OpDriveController::setDriveArcadeTwoJoy() {
        for (pros::Motor *motor : DriveController::drive->getLeftMotors()) {
            *motor = controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) + controller->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        }

        for (pros::Motor *motor : DriveController::drive->getRightMotors()) {
            *motor = controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) - controller->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        }
    }
}