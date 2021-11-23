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

        void turnToPoint(float targetX, float targetY);

        void turnToAngle(float targetA);

        void sweepTurnToAngle(float targetA);

        void driveToPoint(float targetX, float targetY);

        void driveToPoint2(float targetX, float targetY, float targetAngle);

        void driveToPointAndRunHookers(float targetX, float targetY, float hookersTarget, float hookersSpeed);
    
     private:
        pros::Controller *controller;
    };
}

#endif  // WISCOPROS2122_SUBSYSTEMS_DRIVE_AUTONDRIVECONTROLLER_H_