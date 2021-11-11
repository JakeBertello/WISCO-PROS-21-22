#ifndef WISCOPROS2122_SUBSYSTEMS_DRIVECONTROLLER_DRIVE_H_
#define WISCOPROS2122_SUBSYSTEMS_DRIVECONTROLLER_DRIVE_H_

#include "main/main.h"
#include "subsystems/drive/drive.h"

namespace drive_controller {
    class DriveController {
     public:
        DriveController(drive::Drive *drive) {
            this->drive = drive;
        }

     protected:
        float getLeftSensVal();
        float getRightSensVal();
        float getStrafeSensVal();
        float getImuSensVal();
        float getLeftDistSensVal();

     private:
        drive::Drive *drive;
    };
}

#endif  // WISCOPROS2122_SUBSYSTEMS_DRIVECONTROLLER_DRIVE_H_