#include "autons.h"

namespace autons {
    void autonomous1() {
        drive_config::autonDriveController.driveToPoint(0, 26);
        pros::delay(1000);
        drive_config::autonDriveController.driveToPoint(0, 0);
    }
}