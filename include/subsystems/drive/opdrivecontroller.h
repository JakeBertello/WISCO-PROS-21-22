#ifndef WISCOPROS2122_SUBSYSTEMS_DRIVE_OPDRIVECONTROLLER_H_
#define WISCOPROS2122_SUBSYSTEMS_DRIVE_OPDRIVECONTROLLER_H_

#include "main/main.h"
#include "drivecontroller.h"

namespace op_drive_controller {
    class OpDriveController : public drive_controller::DriveController {
     public:
        OpDriveController(drive::Drive *drive, pros::Controller *controller) : DriveController(drive) {
            this->controller = controller;
        }

        void setDriveTank();
        void setDriveArcadeOneJoyRight();
        void setDriveArcadeOneJoyLeft();
        void setDriveArcadeTwoJoy();

     private:
        
                                
        pros::Controller *controller;
    };
}


#endif  // WISCOPROS2122_SUBSYSTEMS_DRIVE_OPDRIVECONTROLLER_H_