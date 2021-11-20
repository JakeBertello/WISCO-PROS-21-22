#include "autons.h"

namespace autons {
    void autonomous1() {
        drive_config::autonDriveController.driveToPoint(0, 40);
    }
}