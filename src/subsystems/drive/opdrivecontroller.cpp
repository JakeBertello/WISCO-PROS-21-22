#include "opdrivecontroller.h"

namespace op_drive_controller {

    void OpDriveController::setDriveTank() {
        for (pros::Motor *motor : DriveController::drive.getLeftMotors()) {
            *motor = controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        }

        for (pros::Motor *motor : DriveController::drive.getRightMotors()) {
            *motor = controller->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        }
    }
}