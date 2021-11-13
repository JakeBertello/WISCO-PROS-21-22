#ifndef WISCOPROS2122_SUBSYSTEMS_DRIVE_OPDRIVECONTROLLER_H_
#define WISCOPROS2122_SUBSYSTEMS_DRIVE_OPDRIVECONTROLLER_H_

#include "main/main.h"
#include "drivecontroller.h"

class OpDriveController : public drive_controller::DriveController {
 public:
    OpDriveController(drive::Drive *drive) : DriveController(drive) {}

 private:
};

#endif  // WISCOPROS2122_SUBSYSTEMS_DRIVE_OPDRIVECONTROLLER_H_