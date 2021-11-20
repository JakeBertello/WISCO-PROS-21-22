#include "subsystems/drive/autondrivecontroller.h"
#include "config/driveconfig.h"

namespace auton_drive_controller {
    void AutonDriveController::turnInertPID(float target) {
        float direction = target / fabsf(target);
        bool systemDone = false;
        timer::Timer pidTimer;
        pros::lcd::clear_line(6);
        pros::lcd::clear_line(7);
        pidTimer.stopTimer();
        pidTimer.zeroTimer();
        while (!systemDone) {
            pros::lcd::print(0, "errorDrive = %8.4f", drive->getTurnLongPidController()->pid->error);
            pros::lcd::print(1, "integral = %8.4f", drive->getTurnLongPidController()->pid->integral);
            pros::lcd::print(2, "derivative = %8.4f", drive->getTurnLongPidController()->pid->derivative);
            pros::lcd::print(3, "target = %8.4f", drive->getTurnLongPidController()->pid->target);
            pros::lcd::print(4, "heading = %8.4f", drive->getImu()->get_heading());
            pros::lcd::print(5, "rotation = %8.4f", drive->getImu()->get_rotation());
            DriveController::tankStraightDrive(direction * drive->getTurnLongPidController()->setPID(target, drive->getImu()->get_heading()),
                            direction * -drive->getTurnLongPidController()->setPID(target, drive->getImu()->get_heading()));
            if (drive->getTurnLongPidController()->pid->error <= 0.5) {
                pidTimer.startTimer();
            }
            if (pidTimer.currentTime() > 300) {
                tankStraightDrive(0, 0);
                pros::lcd::print(6, "error and time limit reached");
                systemDone = true;
            }
            pros::delay(10);
        }
        pros::lcd::print(7, "exited loop");
        tankStraightDrive(0, 0);
    }

    void AutonDriveController::turnToAngle(float targetA) {
        float direction = targetA / fabsf(targetA);
        bool systemDone = false;
        timer::Timer pidTimer;
        pidTimer.stopTimer();
        pidTimer.zeroTimer();

        while (!systemDone) {
            DriveController::tankStraightDrive(direction * -drive->getTurnLongPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)),
                            direction * drive->getTurnLongPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)));

            if (drive->getTurnLongPidController()->pid->error <= 0.5) {
                pidTimer.startTimer();
            }
            if (pidTimer.currentTime() > 300) {
                tankStraightDrive(0, 0);
                pros::lcd::print(6, "error and time limit reached");
                systemDone = true;
            }

            pros::delay(10);
            drive_config::positionTrackerController.updatePosition();
        }
        tankStraightDrive(0, 0);
    }

    void AutonDriveController::turnToPoint(float targetX, float targetY) {
        float deltaX = targetX - drive_config::positionTracker.currX;
        float deltaY = targetY - drive_config::positionTracker.currY;

        float targetA = atan(deltaY / deltaX);

        turnToAngle(targetA);
    }

    void AutonDriveController::sweepTurnToAngle(float targetA) {
        float direction = targetA / fabsf(targetA);
        bool systemDone = false;
        timer::Timer pidTimer;
        pidTimer.stopTimer();
        pidTimer.zeroTimer();

        while (!systemDone) {
            if (direction > 0) {
                DriveController::tankStraightDrive(direction * drive->getTurnSweepPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)), 0);      
            } else if (direction < 0) {
                DriveController::tankStraightDrive(0, direction * -drive->getTurnSweepPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)));
            }
            
            if (drive->getTurnSweepPidController()->pid->error <= 0.5) {
                pidTimer.startTimer();
            }
            if (pidTimer.currentTime() > 300) {
                tankStraightDrive(0, 0);
                pros::lcd::print(6, "error and time limit reached");
                systemDone = true;
            }
            drive_config::positionTrackerController.updatePosition();
            pros::delay(10);
        }
    }

    void AutonDriveController::driveToPoint(float targetX, float targetY) {
        bool systemDone = false;
        timer::Timer pidTimer;
        pidTimer.stopTimer();
        pidTimer.zeroTimer();

        float deltaX = targetX - drive_config::positionTracker.currX;
        float deltaY = targetY - drive_config::positionTracker.currY;

        float targetA = atan(deltaY / deltaX);

        float distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
        
        float currPos;

        float left, right;
        while (!systemDone) {
            currPos = sqrt(pow(drive_config::positionTracker.currX, 2) + pow(drive_config::positionTracker.currY, 2));
            left = right = drive->getDriveStraightPidController()->setPID(distance, currPos);
            left -= (fabsf(left) * drive->getDriveCorrectionPidController()->setPID(0, drive_config::positionTracker.currA*(180 / (float)okapi::pi)));\
            right += (fabsf(right) * drive->getDriveCorrectionPidController()->setPID(0, drive_config::positionTracker.currA*(180 / (float)okapi::pi)));
            tankStraightDrive(left, right);

            if (drive->getDriveStraightPidController()->pid->error <= 0.5) {
                pidTimer.startTimer();
            }
            if (pidTimer.currentTime() > 300) {
                tankStraightDrive(0, 0);
                pros::lcd::print(6, "error and time limit reached");
                systemDone = true;
            }
            drive_config::positionTrackerController.updatePosition();
            pros::delay(10);
        }
    }
}