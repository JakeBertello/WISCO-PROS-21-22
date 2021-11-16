#include "misc/config.h"

namespace config {
    
    pros::Controller master(pros::E_CONTROLLER_MASTER);

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
                                .withLeftMotor(&config::backLeftDrive)
                                .withLeftMotor(&config::middleLeftDrive)
                                .withLeftMotor(&config::backLeftDrive)
                                .withRightMotor(&config::frontRightDrive)
                                .withRightMotor(&config::middleRightDrive)
                                .withRightMotor(&config::backRightDrive)
                                .withLeftRot(&config::leftRot)
                                .withRightRot(&config::rightRot)
                                .withStrafeRot(&config::strafeRot)
                                .withImu(&config::imu);

    op_drive_controller::OpDriveController driveController(&drive, &config::master);

    /********************************* LIFT_MOTORS *********************************/
    pros::Motor bassBoosterLeft(14, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor bassBoosterRight(7, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Motor normalLiftLeft(16, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor normalLiftRight(6, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

    /********************************* LIFT_SENSORS *********************************/


    /********************************* LIFT_CONFIG *********************************/
    lift::Lift bassBooster = lift::Lift::build().withLeftMotor(&bassBoosterLeft)
                                                .withRightMotor(&bassBoosterRight);

    op_lift_controller::OpLiftController bassBoosterController(&bassBooster, &config::master);                                            


    lift::Lift normalLift = lift::Lift::build().withLeftMotor(&normalLiftLeft)
                                                .withRightMotor(&normalLiftRight);

    op_lift_controller::OpLiftController normalLiftController(&normalLift, &config::master);
    

}
