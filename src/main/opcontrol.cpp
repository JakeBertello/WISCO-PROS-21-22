#include "opcontrol.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    drive_config::autonDriveController.turnInertPID(90);
    while(true) {
        drive_config::driveController.setDriveTank();
        lift_config::bassBoosterController.setLiftUpAndDownButtons(B, DOWN);
        lift_config::updogController.setLiftUpAndDownButtons(R1, R2);
        lift_config::hookerController.setLiftUpAndDownButtons(LEFT, A);
        intake_config::grabberController.setIntakeUpAndDownButtons(L1, L2);

        drive_config::positionTrackerController.updatePosition();
        pros::lcd::print(0, "X = %8.4f", drive_config::positionTracker.currX);
        pros::lcd::print(1, "Y = %8.4f", drive_config::positionTracker.currY);
        pros::lcd::print(2, "A = %8.4f", drive_config::positionTracker.currA*(180 / (float)okapi::pi));
        pros::lcd::print(3, "rightRotValue = %d", drive_config::rightRot.get_position());
        pros::lcd::print(4, "leftRotValue = %d", drive_config::leftRot.get_position());
        pros::lcd::print(5, "strafeRotValue = %d", drive_config::strafeRot.get_position());
        pros::delay(10);
    }
}