// Inclusion guard
#ifndef WISCOPROS2122_CONFIG_DRIVECONFIG_H_
#define WISCOPROS2122_CONFIG_DRIVECONFIG_H_

// Included libraries
#include "positiontracker/positiontracker.h"
#include "positiontracker/positiontrackercontroller.h"
#include "subsystems/drive/autondrivecontroller.h"
#include "subsystems/drive/opdrivecontroller.h"
#include "pid/pidcontroller.h"
#include "config/config.h"
#include "main/main.h"

// Defines a namespace for the listed items
namespace drive_config {

    /********************************* DRIVE_MOTORS *********************************/
    extern pros::Motor frontLeftDrive;
    extern pros::Motor middleLeftDrive;
    extern pros::Motor backLeftDrive;
    extern pros::Motor frontRightDrive;
    extern pros::Motor middleRightDrive;
    extern pros::Motor backRightDrive;

    /********************************* DRIVE_SENSORS *********************************/
    extern pros::Rotation leftRot;
    extern pros::Rotation rightRot;
    extern pros::Rotation strafeRot;
    extern pros::Imu imu;
    extern pros::Distance leftDistance;
    extern pros::Distance rightDistance;

    /********************************* DRIVE_CONFIG *********************************/
    extern drive::Drive drive;
    extern op_drive_controller::OpDriveController driveController;
    extern position_tracker::PositionTracker positionTracker;
    extern position_tracker_controller::PositionTrackerController positionTrackerController;

    extern auton_drive_controller::AutonDriveController autonDriveController;

    extern pros::Task positionTrackerTask;

    /********************************** DRIVE_PID ***********************************/
    extern pid::PID turnLongPID;
    extern pid_controller::PIDController turnLongPIDController;

    extern pid::PID turnShortPID;
    extern pid_controller::PIDController turnShortPIDController;

    extern pid::PID turnSweepPID;
    extern pid_controller::PIDController turnSweepPIDController;

    extern pid::PID driveStraightPID;
    extern pid_controller::PIDController driveStraightPIDController;

    extern pid::PID driveCorrectionPid;
    extern pid_controller::PIDController driveCorrectionPidController;

    /********************************** DRIVE_METHODS ********************************/
    extern void configureDrives();

    void positionTrackerTaskFN(void* param);
}

#endif  // WISCOPROS2122_CONFIG_DRIVECONFIG_H_