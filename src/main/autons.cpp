#include "autons.h"

namespace autons {
    void autonomous1() {
        // drive_config::autonDriveController.driveToPoint(0, 26);
        // pros::delay(250);
        // drive_config::autonDriveController.driveToPoint(0, 0);
        drive_config::autonDriveController.driveToPointAndRunHookers(0, 27.5, 600, 127);
        drive_config::autonDriveController.driveToPointAndRunHookers(0, 0, -200, 127);
    }
}