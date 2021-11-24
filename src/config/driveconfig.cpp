#include "config/driveconfig.h"

namespace drive_config {
    
    /********************************* DRIVE_MOTORS *********************************/
    //ORANGE
    pros::Motor frontLeftDrive(11, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor middleLeftDrive(12, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor backLeftDrive(13, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor frontRightDrive(1, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor middleRightDrive(2, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor backRightDrive(4, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);

    //BLUE
    // pros::Motor frontLeftDrive(11, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
    // pros::Motor middleLeftDrive(12, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
    // pros::Motor backLeftDrive(13, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
    // pros::Motor frontRightDrive(1, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
    // pros::Motor middleRightDrive(2, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
    // pros::Motor backRightDrive(3, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);

    /********************************* DRIVE_SENSORS *********************************/

    //ORANGE
    pros::Rotation leftRot(14);
    pros::Rotation rightRot(5);
    pros::Rotation strafeRot(8);

    pros::Imu imu(15);
    pros::Distance leftDistance(8);
    pros::Distance rightDistance(9);

    //BLUE
    // pros::Rotation leftRot(14);
    // pros::Rotation rightRot(4);
    // pros::Rotation strafeRot(5);

    // pros::Imu imu(20);
    // pros::Distance leftDistance(8);
    // pros::Distance rightDistance(9);

    /********************************* DRIVE_CONFIG *********************************/

    pid::PID turnLongPID(1.7, 0.04, 0, 0, 254, -1000, 1000);
    pid_controller::PIDController turnLongPIDController(&turnLongPID);

    pid::PID turnShortPID(3, 0.5, 0, 0, 254, -1000, 1000);
    pid_controller::PIDController turnShortPIDController(&turnShortPID);

    pid::PID turnSweepPID(1.5, 1, 0.02, 0, 254, -1000, 1000);
    pid_controller::PIDController turnSweepPIDController(&turnSweepPID);

    pid::PID driveStraightPID(6.5, .1, 0, 0, 254, -1000, 1000);
    pid_controller::PIDController driveStraightPIDController(&driveStraightPID);

    pid::PID driveCorrectionPid(0.1, 0.01, 0.01, 0, 254, -1000, 1000);
    pid_controller::PIDController driveCorrectionPidController(&driveCorrectionPid);

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
                                .withTurnLongPidController(&turnLongPIDController)
                                .withTurnShortPidController(&turnShortPIDController)
                                .withTurnSweepPidController(&turnSweepPIDController)
                                .withDriveStraightPidController(&driveStraightPIDController)
                                .withDriveCorrectionPidController(&driveCorrectionPidController);

    position_tracker::PositionTracker positionTracker;
    position_tracker_controller::PositionTrackerController positionTrackerController(&positionTracker, &drive);

    op_drive_controller::OpDriveController driveController(&drive, &config::master);

    auton_drive_controller::AutonDriveController autonDriveController(&drive, &config::master);

    //TASKS
    pros::Task positionTrackerTask (positionTrackerTaskFN, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "positionTrackerTask");

    void positionTrackerTaskFN(void* param)
    {
        while (true)
        {
            drive_config::positionTrackerController.updatePosition();
            pros::delay(10);
        }
    }

    void configureDrives() {
        imu.reset();
        while (imu.is_calibrating()) {
            pros::lcd::print(0, "Imu is calibrating");
        }
        pros::lcd::clear_line(0);
        rightRot.set_reversed(true);
        driveController.resetDriveSens();
        positionTrackerController.reset();
        frontLeftDrive.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        middleLeftDrive.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        backLeftDrive.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        frontRightDrive.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        middleRightDrive.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        backRightDrive.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    }
}
