#include "autons.h"

namespace autons {
    void autonomous1() {
        drive_config::autonDriveController.driveToPointAndRunHookers(0, 27.5, 600, 127);
        drive_config::autonDriveController.driveToPointAndRunHookers(0, 0, -200, 127);
    }

    void autonomous2() {
        drive_config::autonDriveController.turnToPoint(15, 15);
        pros::delay(1000);
        drive_config::autonDriveController.turnToPoint(-15, -15);
        pros::delay(1000);
        drive_config::autonDriveController.turnToPoint(0, 15);
    }
}