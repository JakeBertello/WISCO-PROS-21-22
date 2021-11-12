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

        std::vector<pros::Motor*>* getLeftMotors();
        std::vector<pros::Motor*>* getRightMotors();
        pros::Rotation* getLeftRot();
        pros::Rotation* getRightRot();
        pros::Rotation* getStrafeRot();
        pros::Imu* getImu();
        pros::Distance* getLeftDistance();
        pros::Distance* getRightDistance();

    private:
        Drive() : leftMotors(nullptr),
                rightMotors(nullptr) {
                //addposition tracker and pid controllers
        }

        std::vector<pros::Motor*> *leftMotors;
        std::vector<pros::Motor*> *rightMotors;
        pros::Rotation *leftRot = nullptr;
        pros::Rotation *rightRot = nullptr;
        pros::Rotation *strafeRot = nullptr;
        pros::Imu *imu = nullptr;
        pros::Distance *leftDistance = nullptr;
        pros::Distance *rightDistance = nullptr;
    };

    class DriveBuilder {
    public:
        DriveBuilder& withLeftMotor(pros::Motor *motor) {
            drive.leftMotors->push_back(motor);
            return *this;
        }

        DriveBuilder& withRightMotor(pros::Motor *motor) {
            drive.rightMotors->push_back(motor);
            return *this;
        }

        DriveBuilder& withLeftMotorV(std::vector<pros::Motor*> *motors) {
            drive.leftMotors = motors;
            return *this;
        }

        DriveBuilder& withRightMotorV(std::vector<pros::Motor*> *motors) {
            drive.rightMotors = motors;
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