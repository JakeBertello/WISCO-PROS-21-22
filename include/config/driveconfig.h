#ifndef WISCOPROS2122_CONFIG_DRIVECONFIG_H_
#define WISCOPROS2122_CONFIG_DRIVECONFIG_H_

#include "subsystems/drive/opdrivecontroller.h"
#include "pid/pidcontroller.h"
#include "config/config.h"
#include "main/main.h"


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

    extern pid::PID turnLongPID;
    extern pid_controller::PIDController turnLongPIDController;

    extern void configureDrives();
}

#endif  // WISCOPROS2122_CONFIG_DRIVECONFIG_H_