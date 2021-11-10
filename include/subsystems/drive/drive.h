#ifndef WISCOPROS2122_SUBSYSTEMS_DRIVE_DRIVE_H_
#define WISCOPROS2122_SUBSYSTEMS_DRIVE_DRIVE_H_

#include "main/main.h"
namespace drive
{
    enum PIDControllers {  // ames for different pid controllers
        DEFAULT,
        SWEEP
    };

    class DriveBuilder;  // Forward declaration

    class Drive {
    public:
        friend class DriveBuilder;
        static DriveBuilder build();

    private:
        Drive() : leftDriveMotors(std::vector<pros::Motor*>()),
                rightDriveMotors(std::vector<pros::Motor*>()),
                leftRot(nullptr),
                rightRot(nullptr),
                strafeRot(nullptr),
                imu(nullptr),
                leftDistance(nullptr),
                rightDistance(nullptr) {
                //addposition tracker and pid controllers
        }

        std::vector<pros::Motor*> leftDriveMotors;
        std::vector<pros::Motor*> rightDriveMotors;
        pros::Rotation *leftRot;
        pros::Rotation *rightRot;
        pros::Rotation *strafeRot;
        pros::Imu *imu;
        pros::Distance *leftDistance;
        pros::Distance *rightDistance;
    };

    class DriveBuilder {
    public:
        DriveBuilder& withLeftDriveMotor(pros::Motor *motor) {
            drive.leftDriveMotors.push_back(motor);
            return *this;
        }

        DriveBuilder& withRightDriveMotor(pros::Motor *motor) {
            drive.rightDriveMotors.push_back(motor);
            return *this;
        }

        DriveBuilder& withLeftRot(pros::Rotation *leftRot) {
            drive.leftRot = leftRot;
            return *this;
        }

        DriveBuilder& withRightRot(pros::Rotation *rightRot) {
            drive.rightRot = rightRot;
            return *this;
        }

        DriveBuilder& withStrafeRot(pros::Rotation *strafeRot) {
            drive.strafeRot = strafeRot;
            return *this;
        }

        DriveBuilder& withImu(pros::Imu *imu) {
            drive.imu = imu;
            return *this;
        }

        DriveBuilder& withLeftDistance(pros::Distance *leftDistance) {
            drive.leftDistance = leftDistance;
            return *this;
        }

        DriveBuilder& withRightDistance(pros::Distance *rightDistance) {
            drive.rightDistance = rightDistance;
            return *this;
        }

        operator Drive&&() {
            return std::move(drive);
        }

    private:
        Drive drive;
    };
}
#endif  // WISCOPROS2122_SUBSYSTEMS_DRIVE_DRIVE_H_