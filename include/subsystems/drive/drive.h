#ifndef PROS_SUBSYSTEMS_DRIVE_DRIVE_H_
#define PROS_SUBSYSTEMS_DRIVE_DRIVE_H_

#include "main/main.h"

class DriveBuilder;

class Drive {
 public:
    friend class DriveBuilder;
    static DriveBuilder build();

 private:
    Drive() = default;

    std::vector<pros::Motor> leftDriveMotors;
    std::vector<pros::Motor> rightDriveMotors;
    // pros::Rotation leftRot;
    // pros::Rotation rightRot;
    // pros::Rotation strafeRot;
};

class DriveBuilder {
 public:
    DriveBuilder& withLeftDriveMotor(const pros::Motor &motor) {
        _drive.leftDriveMotors.push_back(motor);
        return *this;
    }

    DriveBuilder& withRightDriveMotor(const pros::Motor &motor) {
        _drive.rightDriveMotors.push_back(motor);
        return *this;
    }

    operator Drive&&() {
        return std::move(_drive);
    }

 private:
    Drive _drive;
};

#endif  // PROS_SUBSYSTEMS_DRIVE_DRIVE_H_