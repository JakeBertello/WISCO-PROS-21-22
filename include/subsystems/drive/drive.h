#ifndef WISCOPROS2122_SUBSYSTEMS_DRIVE_DRIVE_H_
#define WISCOPROS2122_SUBSYSTEMS_DRIVE_DRIVE_H_

#include "main/main.h"
#include "pid/pidcontroller.h"

namespace drive
{
    enum PIDControllers {  // names for different pid controllers
        DEFAULT,
        SWEEP
    };

    class DriveBuilder;  // Forward declaration

    class Drive {
    public:
        friend class DriveBuilder;
        static DriveBuilder build();

        std::vector<pros::Motor*> getLeftMotors();
        std::vector<pros::Motor*> getRightMotors();
        std::vector<pros::Motor*> getStrafeMotors();
        pros::Rotation* getLeftRot();
        pros::Rotation* getRightRot();
        pros::Rotation* getStrafeRot();
        pros::Imu* getImu();
        pros::Distance* getLeftDistance();
        pros::Distance* getRightDistance();
        pid_controller::PIDController* getDriveStraightPidController();
        pid_controller::PIDController* getTurnShortPidController();
        pid_controller::PIDController* getTurnLongPidController();
        pid_controller::PIDController* getTurnSweepPidController();
        pid_controller::PIDController* getDriveCorrectionPidController();

    private:
        std::vector<pros::Motor*> leftMotors;
        std::vector<pros::Motor*> rightMotors;
        std::vector<pros::Motor*> strafeMotors;
        pros::Rotation *leftRot = nullptr;
        pros::Rotation *rightRot = nullptr;
        pros::Rotation *strafeRot = nullptr;
        pros::Imu *imu = nullptr;
        pros::Distance *leftDistance = nullptr;
        pros::Distance *rightDistance = nullptr;
        pid_controller::PIDController *driveStraightPidController = nullptr;
        pid_controller::PIDController *turnShortPidController = nullptr;
        pid_controller::PIDController *turnLongPidController = nullptr;
        pid_controller::PIDController *turnSweepPidController = nullptr;
        pid_controller::PIDController *driveCorrectionPidController = nullptr;
        //addposition tracker and pid controllers
    };

    class DriveBuilder {
    public:
        DriveBuilder& withLeftMotor(pros::Motor *motor) {
            drive.leftMotors.push_back(motor);
            return *this;
        }

        DriveBuilder& withRightMotor(pros::Motor *motor) {
            drive.rightMotors.push_back(motor);
            return *this;
        }

        DriveBuilder& withStrafeMotor(pros::Motor *motor) {
            drive.strafeMotors.push_back(motor);
            return *this;
        }

        DriveBuilder& withLeftMotorV(std::vector<pros::Motor*> motors) {
            drive.leftMotors = motors;
            return *this;
        }

        DriveBuilder& withRightMotorV(std::vector<pros::Motor*> motors) {
            drive.rightMotors = motors;
            return *this;
        }

        DriveBuilder& withStrafeMotorV(std::vector<pros::Motor*> motors) {
            drive.strafeMotors = motors;
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

        DriveBuilder& withDriveStraightPidController(pid_controller::PIDController *driveStraightPidController) {
            drive.driveStraightPidController = driveStraightPidController;
            return *this;
        }

        DriveBuilder& withTurnShortPidController(pid_controller::PIDController *turnShortPidController) {
            drive.turnShortPidController = turnShortPidController;
            return *this;
        }

        DriveBuilder& withTurnLongPidController(pid_controller::PIDController *turnLongPidController) {
            drive.turnLongPidController = turnLongPidController;
            return *this;
        }

        DriveBuilder& withTurnSweepPidController(pid_controller::PIDController *turnSweepPidController) {
            drive.turnSweepPidController = turnSweepPidController;
            return *this;
        }

        DriveBuilder& withDriveCorrectionPidController(pid_controller::PIDController *driveCorrectionPidController) {
            drive.driveCorrectionPidController = driveCorrectionPidController;
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