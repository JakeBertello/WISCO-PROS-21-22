#include "autons.h"

namespace autons {
    void autonomous1() {
        drive_config::autonDriveController.driveToPointAndRunHookers(0, 27.5, 600, 127);
        drive_config::autonDriveController.driveToPointAndRunHookers(0, 0, -200, 127);
    }

    void autonomous2() {
        drive_config::autonDriveController.driveToPoint2(0, 15, 0);
        pros::delay(1000);
        drive_config::autonDriveController.driveToPoint2(15, 15, 0);
        pros::delay(1000);
        drive_config::autonDriveController.driveToPoint2(15, 0, 0);
        pros::delay(1000);
        drive_config::autonDriveController.driveToPoint2(0, 0, 0);
    }
}