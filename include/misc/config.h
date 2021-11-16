#ifndef WISCOPROS2122_MISC_CONFIG_H_
#define WISCOPROS2122_MISC_CONFIG_H_

#include "subsystems/drive/opdrivecontroller.h"
#include "subsystems/lift/opliftcontroller.h"
#include "main/main.h"

namespace config {
    extern pros::Controller master;

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

    /********************************* LIFT_MOTORS *********************************/
    extern pros::Motor bassBoosterLeft;
    extern pros::Motor bassBoosterRight;

    extern pros::Motor normalLiftLeft;
    extern pros::Motor normalLiftRight;

    /********************************* LIFT_SENSORS *********************************/


    /********************************* LIFT_CONFIG *********************************/
    extern lift::Lift bassBooster;
    extern op_lift_controller::OpLiftController bassBoosterController;

    extern lift::Lift normalLift;
    extern op_lift_controller::OpLiftController normalLiftController;
}

#endif  // WISCOPROS2122_MISC_CONFIG_H_