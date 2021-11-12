#include "subsystems/drive/drivecontroller.h"

namespace drive_controller {
    float DriveController::getLeftSensVal() {
        if (_drive->getLeftRot() != nullptr) {
            
        } else {
            if (_drive->getLeftMotors() != nullptr) {
                
            }
        }
    }

    float DriveController::getAvgLeftSensVal() {
        int sum = 0;
        for (pros::Motor* motor: _drive->getLeftMotors()) {

        }
    }
}