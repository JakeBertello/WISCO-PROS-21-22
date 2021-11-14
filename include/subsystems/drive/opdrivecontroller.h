#ifndef WISCOPROS2122_SUBSYSTEMS_DRIVE_OPDRIVECONTROLLER_H_
#define WISCOPROS2122_SUBSYSTEMS_DRIVE_OPDRIVECONTROLLER_H_

#include "main/main.h"
#include "drivecontroller.h"
#include "misc/config.h"

namespace op_drive_controller {
    class OpDriveController : public drive_controller::DriveController {
     public:
        OpDriveController(pros::Controller *controller) : DriveController(&drive) {
            this->controller = controller;
        }

        void setDriveTank();
        void setDriveArcadeOneJoyRight();
        void setDriveArcadeOneJoyLeft();
        void setDriveArcadeTwoJoy();

     private:
        drive::Drive drive = drive::Drive::build()
                                .withLeftMotor(&config::backLeftDrive)
                                .withLeftMotor(&config::middleLeftDrive)
                                .withLeftMotor(&config::backLeftDrive)
                                .withRightMotor(&config::frontRightDrive)
                                .withRightMotor(&config::middleRightDrive)
                                .withRightMotor(&config::backRightDrive)
                                .withLeftRot(&config::leftRot)
                                .withRightRot(&config::rightRot)
                                .withStrafeRot(&config::strafeRot)
                                .withImu(&config::imu);
                                
        pros::Controller *controller;
    };
}


#endif  // WISCOPROS2122_SUBSYSTEMS_DRIVE_OPDRIVECONTROLLER_H_