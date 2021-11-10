#ifndef WISCOPROS2122_MISC_CONFIG_H_
#define WISCOPROS2122_MISC_CONFIG_H_

#include "main/main.h"

namespace config {

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

    /********************************* BASS_BOOSTER_MOTORS *********************************/

    /********************************* NORMAL_LIFT_MOTORS *********************************/
}

#endif  // WISCOPROS2122_MISC_CONFIG_H_