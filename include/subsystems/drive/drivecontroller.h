#ifndef WISCOPROS2122_SUBSYSTEMS_DRIVE_DRIVECONTROLLER_H_
#define WISCOPROS2122_SUBSYSTEMS_DRIVE_DRIVECONTROLLER_H_

#include "main/main.h"
#include "subsystems/drive/drive.h"

namespace drive_controller {
    class DriveController {
     public:
        DriveController(drive::Drive *drive) {
            this->drive = drive;
        }

        void resetDriveSens();

     protected:
        float getLeftSensVal();
        float getRightSensVal();
        float getStrafeSensVal();
        float getImuSensVal();
        float getLeftDistSensVal();
        float getRightDistSensVal();
        
        drive::Drive *drive;

     private:
        float getAvgLeftSensVal();
        float getAvgRightSensVal();
        float getAvgStrafeSensVal();
        
    };
}

#endif  // WISCOPROS2122_SUBSYSTEMS_DRIVE_DRIVECONTROLLER_H_