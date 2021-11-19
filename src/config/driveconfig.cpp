#include "config/driveconfig.h"

namespace drive_config {
    
    /********************************* DRIVE_MOTORS *********************************/
    pros::Motor frontLeftDrive(11, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor middleLeftDrive(12, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor backLeftDrive(13, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor frontRightDrive(1, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor middleRightDrive(2, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor backRightDrive(3, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);

    /********************************* DRIVE_SENSORS *********************************/
    pros::Rotation leftRot(14);
    pros::Rotation rightRot(4);
    pros::Rotation strafeRot(5);
    pros::Imu imu(19);
    pros::Distance leftDistance(8);
    pros::Distance rightDistance(9);

    /********************************* DRIVE_CONFIG *********************************/

    pid::PID turnLongPID(1.5, 1, 0.02, 0, 254, -1000, 1000);
    pid_controller::PIDController turnLongPIDController(&turnLongPID);

    drive::Drive drive = drive::Drive::build().withLeftMotor(&drive_config::frontLeftDrive)
                                .withLeftMotor(&drive_config::backLeftDrive)
                                .withLeftMotor(&drive_config::middleLeftDrive)
                                .withLeftMotor(&drive_config::backLeftDrive)
                                .withRightMotor(&drive_config::frontRightDrive)
                                .withRightMotor(&drive_config::middleRightDrive)
                                .withRightMotor(&drive_config::backRightDrive)
                                .withLeftRot(&drive_config::leftRot)
                                .withRightRot(&drive_config::rightRot)
                                .withStrafeRot(&drive_config::strafeRot)
                                .withImu(&drive_config::imu)
                                .withTurnLongPidController(&turnLongPIDController);

    op_drive_controller::OpDriveController driveController(&drive, &config::master);

    auton_drive_controller::AutonDriveController autonDriveController(&drive, &config::master);

    void configureDrives() {
        imu.reset();
        while (imu.is_calibrating()) {
            pros::lcd::print(0, "Imu is calibrating");
        }
        pros::lcd::clear_line(0);
        frontLeftDrive.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        middleLeftDrive.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        backLeftDrive.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        frontRightDrive.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        middleRightDrive.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        backRightDrive.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    }
}
