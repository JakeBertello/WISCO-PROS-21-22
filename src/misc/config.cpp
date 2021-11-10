#include "misc/config.h"

namespace config {
    
    /********************************* DRIVE_MOTORS *********************************/
    pros::Motor frontLeftDrive(1);
    pros::Motor middleLeftDrive(2);
    pros::Motor backLeftDrive(3);
    pros::Motor frontRightDrive(4);
    pros::Motor middleRightDrive(5);
    pros::Motor backRightDrive(6);

    /********************************* DRIVE_SENSORS *********************************/
    pros::Rotation leftRot(7);
    pros::Rotation rightRot(8);
    pros::Rotation strafeRot(9);
    pros::Imu imu(10);
    pros::Distance leftDistance(11);
    pros::Distance rightDistance(12);
}
