#include "subsystems/drive/autondrivecontroller.h"
#include "config/driveconfig.h"
#include "misc/mathTools.h"
#include "config/liftconfig.h"

namespace auton_drive_controller {
    void AutonDriveController::turnInertPID(float target) {
        drive->getImu()->set_heading(0);
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
            pros::lcd::print(4, "imuHeading = %8.4f", drive->getImu()->get_heading());
            if (fabsf(drive->getTurnLongPidController()->pid->error) > 45) {
                DriveController::tankStraightDrive(drive->getTurnLongPidController()->setPID(target, drive->getImu()->get_heading()),
                            drive->getTurnLongPidController()->setPID(target, drive->getImu()->get_heading()));
            } else {
                DriveController::tankStraightDrive(drive->getTurnShortPidController()->setPID(target, drive->getImu()->get_heading()),
                            drive->getTurnShortPidController()->setPID(target, drive->getImu()->get_heading()));
            }
            
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
        bool systemDone = false;
        timer::Timer pidTimer;
        pidTimer.stopTimer();
        pidTimer.zeroTimer();

        while (!systemDone) {
            
            if (fabsf(drive->getTurnLongPidController()->pid->error) > 45) {
                pros::lcd::print(0, "X = %8.4f", drive_config::positionTracker.currX);
                pros::lcd::print(1, "Y = %8.4f", drive_config::positionTracker.currY);
                pros::lcd::print(2, "A = %8.4f", drive_config::positionTracker.currA*(180 / (float)okapi::pi));
                pros::lcd::print(3, "target = %8.4f", drive_config::drive.getTurnLongPidController()->pid->target);
                pros::lcd::print(4, "error = %8.4f", drive_config::drive.getTurnLongPidController()->pid->error);
                DriveController::tankStraightDrive(drive->getTurnLongPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)),
                            -drive->getTurnLongPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)));
            } else {
                pros::lcd::print(0, "X = %8.4f", drive_config::positionTracker.currX);
                pros::lcd::print(1, "Y = %8.4f", drive_config::positionTracker.currY);
                pros::lcd::print(2, "A = %8.4f", drive_config::positionTracker.currA*(180 / (float)okapi::pi));
                pros::lcd::print(3, "target = %8.4f", drive_config::drive.getTurnShortPidController()->pid->target);
                pros::lcd::print(4, "error = %8.4f", drive_config::drive.getTurnShortPidController()->pid->error);
                DriveController::tankStraightDrive(drive->getTurnShortPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)),
                            -drive->getTurnShortPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)));
            }
            

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

        float targetDist = sqrt(pow(targetX, 2) + pow(targetY, 2));

        float targetA;
        if (deltaX == 0) {
            targetA = drive_config::positionTracker.currA;
        } else {
            targetA = atan(deltaY / deltaX);
        }

        if (fabsf(targetA - drive_config::positionTracker.currA) > 5) {
            turnToAngle(targetA);
        }
        
        float distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
        float currPos = sqrt(pow(drive_config::positionTracker.currX, 2) + pow(drive_config::positionTracker.currY, 2));
        if (deltaX < 0 || deltaY < 0) {
            distance = -distance;
            currPos = -currPos;
        }
        float left, right;
        pidTimer.zeroTimer();
        while (!systemDone) {
            currPos = sqrt(pow(drive_config::positionTracker.currX, 2) + pow(drive_config::positionTracker.currY, 2));
            left = right = drive->getDriveStraightPidController()->setPID(targetDist, currPos);
            pros::lcd::print(0, "X = %8.4f", drive_config::positionTracker.currX);
            pros::lcd::print(1, "Y = %8.4f", drive_config::positionTracker.currY);
            pros::lcd::print(2, "A = %8.4f", drive_config::positionTracker.currA*(180 / (float)okapi::pi));
            pros::lcd::print(3, "target = %8.4f", drive->getDriveStraightPidController()->pid->target);
            pros::lcd::print(4, "error = %8.4f", drive->getDriveStraightPidController()->pid->error);
            pros::lcd::print(5, "currVal = %8.4f", drive->getDriveStraightPidController()->pid->currVal);
            pros::lcd::print(6, "distance = %8.4f", distance);
            pros::lcd::print(7, "currentTime = %d", pidTimer.currentTime());
            printf("leftBeforeCorrection = %8.4f\r\n", left);
            printf("rightBeforeCorrection = %8.4f\r\n", right);
            //left += (fabsf(left) * drive->getDriveCorrectionPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)));\
            printf("leftAfterCorrection = %8.4f\r\n", left);
            //right -= (fabsf(right) * drive->getDriveCorrectionPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)));
            printf("rightAfterCorrection = %8.4f\r\n", right);
            tankStraightDrive(left, right);

            if (fabsf(drive->getDriveStraightPidController()->pid->error) <= 0.5) {
                pidTimer.startTimer();
            }
            if (pidTimer.currentTime() > 200) {
                tankStraightDrive(0, 0);
                systemDone = true;
            }
            // if (fabs(drive->getDriveStraightPidController()->pid->error) <=0.5) {
            //     tankStraightDrive(0, 0);
            //     systemDone = true;
            // }
            pros::delay(10);
        }
    }

    void AutonDriveController::driveToPointAndRunHookers(float targetX, float targetY, float hookersTarget, float hookersSpeed) {
        bool systemDone = false;
        timer::Timer pidTimer;
        pidTimer.stopTimer();
        pidTimer.zeroTimer();

        float deltaX = targetX - drive_config::positionTracker.currX;
        float deltaY = targetY - drive_config::positionTracker.currY;

        float targetDist = sqrt(pow(targetX, 2) + pow(targetY, 2));

        float targetA;
        if (deltaX == 0) {
            targetA = drive_config::positionTracker.currA;
        } else {
            targetA = atan(deltaY / deltaX);
        }

        if (fabsf(targetA - drive_config::positionTracker.currA) > 5) {
            turnToAngle(targetA);
        }
        
        float distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
        float currPos = sqrt(pow(drive_config::positionTracker.currX, 2) + pow(drive_config::positionTracker.currY, 2));
        if (deltaX < 0 || deltaY < 0) {
            distance = -distance;
            currPos = -currPos;
        }
        float left, right;
        pidTimer.zeroTimer();
            
        float direction = hookersTarget / fabsf(hookersTarget);
        while (!systemDone) {
            if (fabsf(lift_config::hookerController.getLeftSensVal()) <= fabsf(hookersTarget - 50) || fabsf(lift_config::hookerController.getLeftSensVal()) >= fabsf(hookersTarget + 50)) {
                lift_config::autonHookerController.moveHookers(direction * hookersSpeed);
            } else {
                lift_config::autonHookerController.moveHookers(0);
            }
            currPos = sqrt(pow(drive_config::positionTracker.currX, 2) + pow(drive_config::positionTracker.currY, 2));
            left = right = drive->getDriveStraightPidController()->setPID(targetDist, currPos);
            pros::lcd::print(0, "X = %8.4f", drive_config::positionTracker.currX);
            pros::lcd::print(1, "Y = %8.4f", drive_config::positionTracker.currY);
            pros::lcd::print(2, "A = %8.4f", drive_config::positionTracker.currA*(180 / (float)okapi::pi));
            pros::lcd::print(3, "target = %8.4f", drive->getDriveStraightPidController()->pid->target);
            pros::lcd::print(4, "error = %8.4f", drive->getDriveStraightPidController()->pid->error);
            pros::lcd::print(5, "currVal = %8.4f", drive->getDriveStraightPidController()->pid->currVal);
            pros::lcd::print(6, "distance = %8.4f", distance);
            pros::lcd::print(7, "currentTime = %d", pidTimer.currentTime());
            printf("leftBeforeCorrection = %8.4f\r\n", left);
            printf("rightBeforeCorrection = %8.4f\r\n", right);
            //left += (fabsf(left) * drive->getDriveCorrectionPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)));\
            printf("leftAfterCorrection = %8.4f\r\n", left);
            //right -= (fabsf(right) * drive->getDriveCorrectionPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)));
            printf("rightAfterCorrection = %8.4f\r\n", right);
            tankStraightDrive(left, right);

            if (fabsf(drive->getDriveStraightPidController()->pid->error) <= 0.5) {
                pidTimer.startTimer();
            }
            if (pidTimer.currentTime() > 200) {
                lift_config::autonHookerController.moveHookers(0);
                tankStraightDrive(0, 0);
                systemDone = true;
            }
            // if (fabs(drive->getDriveStraightPidController()->pid->error) <=0.5) {
            //     tankStraightDrive(0, 0);
            //     systemDone = true;
            // }
            pros::delay(10);
        }
    }

    void AutonDriveController::driveToPoint2(float targetX, float targetY, float targetAngle) {
        bool systemDone = false;
        timer::Timer pidTimer;
        pidTimer.stopTimer();
        pidTimer.zeroTimer();

        float deltaX = targetX - drive_config::positionTracker.currX;
        float deltaY = targetY - drive_config::positionTracker.currY;

        float targetA;
        if (deltaX == 0) {
            targetA = drive_config::positionTracker.currA;
        } else {
            targetA = atan(deltaY / deltaX);
        }
        
        float distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
        float currPos;

        float left, right;
        while (!systemDone) {
            deltaX = targetX - drive_config::positionTracker.currX;
            deltaY = targetY - drive_config::positionTracker.currY;
            double movementAngle = (atan2f(deltaX, deltaY) * okapi::pi) / 180;


            currPos = sqrt(pow(drive_config::positionTracker.currX, 2) + pow(drive_config::positionTracker.currY, 2));
            left = right = drive->getDriveStraightPidController()->setPID((float)distance, (float)currPos);
            pros::lcd::print(0, "X = %8.4f", drive_config::positionTracker.currX);
            pros::lcd::print(1, "Y = %8.4f", drive_config::positionTracker.currY);
            pros::lcd::print(2, "A = %8.4f", drive_config::positionTracker.currA*(180 / (float)okapi::pi));
            pros::lcd::print(3, "target = %8.4f", drive->getDriveStraightPidController()->pid->target);
            pros::lcd::print(4, "error = %8.4f", drive->getDriveStraightPidController()->pid->error);
            pros::lcd::print(5, "currVal = %8.4f", drive->getDriveStraightPidController()->pid->currVal);
            printf("leftBeforeCorrection = %8.4f\r\n", left);
            printf("rightBeforeCorrection = %8.4f\r\n", right);
            //left += (fabsf(left) * drive->getDriveCorrectionPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)));\
            printf("leftAfterCorrection = %8.4f\r\n", left);
            //right -= (fabsf(right) * drive->getDriveCorrectionPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)));
            printf("rightAfterCorrection = %8.4f\r\n", right);
            tankStraightDrive(left, right);

            if (drive->getDriveStraightPidController()->pid->error <= 0.5) {
                pidTimer.startTimer();
            }
            if (pidTimer.currentTime() > 300) {
                tankStraightDrive(0, 0);
                systemDone = true;
            }
            pros::delay(10);
        }
    }
}