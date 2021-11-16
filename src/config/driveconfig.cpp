#include "config/driveconfig.h"

namespace drive_config {
    
    /********************************* DRIVE_MOTORS *********************************/
    pros::Motor frontLeftDrive(11, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor middleLeftDrive(12, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor backLeftDrive(13, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor frontRightDrive(1, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor middleRightDrive(2, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor backRightDrive(4, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);

    /********************************* DRIVE_SENSORS *********************************/
    pros::Rotation leftRot(18);
    pros::Rotation rightRot(8);
    pros::Rotation strafeRot(5);
    pros::Imu imu(17);
    pros::Distance leftDistance(11);
    pros::Distance rightDistance(12);

    /********************************* DRIVE_CONFIG *********************************/
    drive::Drive drive = drive::Drive::build()
                                .withLeftMotor(&drive_config::backLeftDrive)
                                .withLeftMotor(&drive_config::middleLeftDrive)
                                .withLeftMotor(&drive_config::backLeftDrive)
                                .withRightMotor(&drive_config::frontRightDrive)
                                .withRightMotor(&drive_config::middleRightDrive)
                                .withRightMotor(&drive_config::backRightDrive)
                                .withLeftRot(&drive_config::leftRot)
                                .withRightRot(&drive_config::rightRot)
                                .withStrafeRot(&drive_config::strafeRot)
                                .withImu(&drive_config::imu);

    op_drive_controller::OpDriveController driveController(&drive, &config::master);
}