#ifndef PROS_SUBSYSTEMS_DRIVE_DRIVE_H_
#define PROS_SUBSYSTEMS_DRIVE_DRIVE_H_

#include "main/main.h"

class Drive {
 private:
    std::vector<pros::Motor> leftDriveMotors;
    std::vector<pros::Motor> rightDriveMotors;
    std::vector<pros::Motor> allDriveMotors;
    pros::Rotation leftRot;
    pros::Rotation rightRot;
    pros::Rotation strafeRot;

 public:
    static class DriveBuilder {
        std::vector<pros::Motor> *leftDriveMotors;
        std::vector<pros::Motor> *rightDriveMotors;
        std::vector<pros::Motor> *allDriveMotors;
        pros::Rotation *leftRot;
        pros::Rotation *rightRot;
        pros::Rotation *strafeRot;
        
        DriveBuilder* withLeftDriveMotor(pros::Motor leftDriveMotor) {
            this->leftDriveMotors->push_back(leftDriveMotor);
            return this;
        }

        DriveBuilder* withRightDriveMotor(pros::Motor rightDriveMotor) {
            this->rightDriveMotors->push_back(rightDriveMotor);
            return this;
        }

        DriveBuilder* withLeftRot(pros::Rotation *leftRot) {
            this->leftRot = leftRot;
            return this;
        }

        DriveBuilder* withRightRot(pros::Rotation *rightRot) {
            this->rightRot = rightRot;
            return this;
        }

        DriveBuilder* withStrafeRot(pros::Rotation *strafeRot) {
            this->strafeRot = strafeRot;
            return this;
        }

        DriveBuilder* build() {
            return this;
        }
    };
};

#endif  // PROS_SUBSYSTEMS_DRIVE_DRIVE_H_