#ifndef WISCOPROS2122_SUBSYSTEMS_DRIVE_AUTONDRIVECONTROLLER_H_
#define WISCOPROS2122_SUBSYSTEMS_DRIVE_AUTONDRIVECONTROLLER_H_

#include "main/main.h"
#include "drivecontroller.h"
#include "misc/timer.h"

namespace auton_drive_controller {
    class AutonDriveController : public drive_controller::DriveController {
     public:
        AutonDriveController(drive::Drive *drive, pros::Controller *controller) : DriveController(drive) {
            this->controller = controller;
        }

        void turnInertPID(float target);
    
     private:
        pros::Controller *controller;
    };
}

#endif  // WISCOPROS2122_SUBSYSTEMS_DRIVE_AUTONDRIVECONTROLLER_H_