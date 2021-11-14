#include "misc/config.h"

namespace config {
    
    /********************************* DRIVE_MOTORS *********************************/
    pros::Motor frontLeftDrive(1, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor middleLeftDrive(2, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor backLeftDrive(3, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor frontRightDrive(4, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor middleRightDrive(5, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor backRightDrive(6, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);

    /********************************* DRIVE_SENSORS *********************************/
    pros::Rotation leftRot(7);
    pros::Rotation rightRot(8);
    pros::Rotation strafeRot(9);
    pros::Imu imu(10);
    pros::Distance leftDistance(11);
    pros::Distance rightDistance(12);
}
