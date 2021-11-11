#include "main.h"
#include "subsystems/drive/drive.h"
#include "initialize.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    drive::Drive drive = drive::Drive::build().withLeftMotor(&config::backLeftDrive)
                                .withLeftMotor(&config::middleLeftDrive)
                                .withLeftMotor(&config::backLeftDrive)
                                .withRightMotor(&config::frontRightDrive)
                                .withRightMotor(&config::middleRightDrive)
                                .withRightMotor(&config::backRightDrive)
                                .withLeftRot(&config::leftRot)
                                .withRightRot(&config::rightRot)
                                .withStrafeRot(&config::strafeRot)
                                .withImu(&config::imu);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}