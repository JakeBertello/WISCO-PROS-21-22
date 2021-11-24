#include "subsystems/drive/autondrivecontroller.h"
#include "config/driveconfig.h"
#include "misc/mathTools.h"
#include "config/liftconfig.h"

namespace auton_drive_controller {
    void AutonDriveController::turnInertPID(float target) {
        bool systemDone = false;
        timer.stopTimer();
        timer.zeroTimer();
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
                timer.startTimer();
            }
            if (timer.currentTime() > 300) {
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
        timer.stopTimer();
        timer.zeroTimer();
        float currA = getCurrA360(drive_config::positionTracker.currA*(180 / okapi::pi));
        float deltaA = targetA - currA;

        while (!systemDone) {
            currA = getCurrA360(drive_config::positionTracker.currA*(180 / okapi::pi));
            deltaA = targetA - currA;
            tankStraightDrive(drive->getTurnLongPidController()->setPID(targetA, currA),
                            -drive->getTurnLongPidController()->setPID(targetA, currA));
            printf("{targetA: %f, currA: %f, deltaA: %f, errorA: %f}\r\n", targetA, currA, deltaA, drive->getTurnLongPidController()->pid->error);
            if (fabsf(drive->getTurnLongPidController()->pid->error) <= 0.5) {
                timer.startTimer();
            }
            if (timer.currentTime() > 300) {
                tankStraightDrive(0, 0);
                systemDone = true;
            }
            pros::delay(10);
        }
        timer.stopTimer();
        timer.zeroTimer();
    }

    void AutonDriveController::turnToAngleShort(float targetA) {
        bool systemDone = false;
        timer.stopTimer();
        timer.zeroTimer();
        float currA = getCurrA360(drive_config::positionTracker.currA*(180 / okapi::pi));
        float deltaA = targetA - currA;

        while (!systemDone) {
            currA = getCurrA360(drive_config::positionTracker.currA*(180 / okapi::pi));
            tankStraightDrive(drive->getTurnShortPidController()->setPID(targetA, currA),
                            -drive->getTurnShortPidController()->setPID(targetA, currA));
            printf("{targetA: %f, currA: %f, deltaA: %f, errorA: %f}\r\n", targetA, currA, deltaA, drive->getTurnShortPidController()->pid->error);
            if (fabsf(drive->getTurnShortPidController()->pid->error) <= 0.5) {
                timer.startTimer();
            }
            
            if (timer.currentTime() > 300) {
                systemDone = true;
            }
            pros::delay(10);
        }
        timer.stopTimer();
        timer.zeroTimer();
    }

    float AutonDriveController::getCurrA360(float angle) {
        float currAIn360 = angle;
        if (currAIn360 > 360) {
            currAIn360 = fmodf(currAIn360, 360);
        } else if (currAIn360 < 0 && currAIn360 >= -360) {
            currAIn360 += 360;
        } else if (currAIn360 < -360) {
            currAIn360 = 360 + fmodf(currAIn360, 360);
        }
        return currAIn360;
    }

    float AutonDriveController::getNorthFacingAngleFromPoint(float x, float y) {
        float degrees = 90 - (atan2f(y, x) * 180 / okapi::pi);
        return degrees;
    }

    void AutonDriveController::turnToPoint(float targetX, float targetY) {
        float deltaX = targetX - drive_config::positionTracker.currX;
        float deltaY = targetY - drive_config::positionTracker.currY;

        float targetA = getNorthFacingAngleFromPoint(targetX, targetY);

        turnToAngle(targetA);
    }

    void AutonDriveController::turnToPointShort(float targetX, float targetY) {
        float deltaX = targetX - drive_config::positionTracker.currX;
        float deltaY = targetY - drive_config::positionTracker.currY;

        float targetA = getNorthFacingAngleFromPoint(targetX, targetY);

        turnToAngleShort(targetA);
    }

    void AutonDriveController::sweepTurnToAngle(float targetA) {
        float direction = targetA / fabsf(targetA);
        bool systemDone = false;
        timer.stopTimer();
        timer.zeroTimer();

        while (!systemDone) {
            if (direction > 0) {
                DriveController::tankStraightDrive(direction * drive->getTurnSweepPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)), 0);      
            } else if (direction < 0) {
                DriveController::tankStraightDrive(0, direction * -drive->getTurnSweepPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)));
            }
            
            if (drive->getTurnSweepPidController()->pid->error <= 0.5) {
                timer.startTimer();
            }
            if (timer.currentTime() > 300) {
                tankStraightDrive(0, 0);
                systemDone = true;
            }
            drive_config::positionTrackerController.updatePosition();
            pros::delay(10);
        }
        timer.stopTimer();
        timer.zeroTimer();
    }

    void AutonDriveController::arcTurnToAngle(float targetA, float innerMotorPower) {
        bool systemDone = false;
        timer.stopTimer();
        timer.zeroTimer();
        float left, right;
        while (!systemDone) {
            left = drive->getTurnSweepPidController()->setPID(targetA, drive_config::positionTracker.currA);
        }
        tankStraightDrive(left, right);
    }

    void AutonDriveController::driveToPoint(float targetX, float targetY) {
        bool systemDone = false;
        timer.stopTimer();
        timer.zeroTimer();

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
        float currPos = sqrt(pow(drive_config::positionTracker.currX, 2) + pow(drive_config::positionTracker.currY, 2));
        if (deltaX < 0 || deltaY < 0) {
            currPos = -currPos;
        }
        float left, right;
        timer.zeroTimer();
        while (!systemDone) {
            currPos = sqrt(pow(drive_config::positionTracker.currX, 2) + pow(drive_config::positionTracker.currY, 2));
            left = right = drive->getDriveStraightPidController()->setPID(targetDist, currPos);
            pros::lcd::print(0, "X = %8.4f", drive_config::positionTracker.currX);
            pros::lcd::print(1, "Y = %8.4f", drive_config::positionTracker.currY);
            pros::lcd::print(2, "A = %8.4f", drive_config::positionTracker.currA*(180 / (float)okapi::pi));
            pros::lcd::print(3, "target = %8.4f", drive->getDriveStraightPidController()->pid->target);
            pros::lcd::print(4, "error = %8.4f", drive->getDriveStraightPidController()->pid->error);
            pros::lcd::print(5, "currVal = %8.4f", drive->getDriveStraightPidController()->pid->currVal);
            pros::lcd::print(6, "targetDistance = %8.4f", targetDist);
            pros::lcd::print(7, "currentTime = %d", timer.currentTime());
            printf("leftBeforeCorrection = %8.4f\r\n", left);
            printf("rightBeforeCorrection = %8.4f\r\n", right);
            //left += (fabsf(left) * drive->getDriveCorrectionPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)));\
            printf("leftAfterCorrection = %8.4f\r\n", left);
            //right -= (fabsf(right) * drive->getDriveCorrectionPidController()->setPID(targetA, drive_config::positionTracker.currA*(180 / (float)okapi::pi)));
            printf("rightAfterCorrection = %8.4f\r\n", right);
            tankStraightDrive(left, right);

            if (fabsf(drive->getDriveStraightPidController()->pid->error) <= 0.5) {
                timer.startTimer();
            }
            if (timer.currentTime() > 200) {
                tankStraightDrive(0, 0);
                systemDone = true;
            }
            pros::delay(10);
        }
        timer.stopTimer();
        timer.zeroTimer();
    }

    void AutonDriveController::driveToPointAndRunHookers(float targetX, float targetY, float hookersTarget, float hookersSpeed) {
        bool systemDone = false;
        timer.stopTimer();
        timer.zeroTimer();

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
        timer.zeroTimer();
            
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
            pros::lcd::print(7, "currentTime = %d", timer.currentTime());
            printf("leftBeforeCorrection = %8.4f\r\n", left);
            printf("rightBeforeCorrection = %8.4f\r\n", right);
            printf("rightAfterCorrection = %8.4f\r\n", right);
            tankStraightDrive(left, right);

            if (fabsf(drive->getDriveStraightPidController()->pid->error) <= 0.5) {
                timer.startTimer();
            }
            if (timer.currentTime() > 200) {
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
        timer.stopTimer();
        timer.zeroTimer();
    }

    void AutonDriveController::driveToPoint2(float targetX, float targetY, bool reverse) {
        bool systemDone = false;
        timer.stopTimer();
        timer.zeroTimer();
        
        float distanceX, distanceY, distance, targetA, currVal, deltaA, left, right;
        distanceX = targetX - drive_config::positionTracker.currX;
        distanceY = targetY - drive_config::positionTracker.currY;
        distance = sqrtf(powf(distanceX, 2) + powf(distanceY, 2));
        currVal = sqrtf(powf(drive_config::positionTracker.currX, 2) + powf(drive_config::positionTracker.currY, 2));
        targetA = getNorthFacingAngleFromPoint(distanceX, distanceY);
        if (reverse) {
            targetA = -targetA;
        }
        turnToAngle(targetA);
        while (!systemDone) {
            // if (!reverse) {
            //     currVal = sqrtf(powf(drive_config::positionTracker.currX, 2) + powf(drive_config::positionTracker.currY, 2));
            //     left = right = drive->getDriveStraightPidController()->setPID(distance, currVal);
            //     if (drive_config::positionTracker.currA > 360 || drive_config::positionTracker.currA < -360) {
            //         deltaA = targetA - (fmodf(drive_config::positionTracker.currA, 360));
            //     } else {
            //         deltaA = targetA - drive_config::positionTracker.currA;
            //     }
            //     left += drive->getDriveCorrectionPidController()->setPID(deltaA, 0);
            //     right -= drive->getDriveCorrectionPidController()->setPID(deltaA, 0);
            // } else {
            //     currVal = sqrtf(powf(drive_config::positionTracker.currX, 2) + powf(drive_config::positionTracker.currY, 2));
            //     left = right = drive->getDriveStraightPidController()->setPID(distance, currVal);
            //     left -= drive->getDriveCorrectionPidController()->setPID(deltaA, 0);
            //     right += drive->getDriveCorrectionPidController()->setPID(deltaA, 0);
            // }
            printf("{distance: %f, currVal: %f, errorDist: %f, targetA: %f, currA: %f, errorTurn: %f}\r\n", 
            distance, currVal, drive->getDriveStraightPidController()->pid->error, 
            targetA, drive_config::positionTracker.currA * 180 / okapi::pi, drive->getDriveCorrectionPidController()->pid->error);
            currVal = sqrtf(powf(drive_config::positionTracker.currX, 2) + powf(drive_config::positionTracker.currY, 2));
            left = right = drive->getDriveStraightPidController()->setPID(distance, currVal);
            deltaA = targetA - getCurrA360(drive_config::positionTracker.currA);
            left -= drive->getDriveCorrectionPidController()->setPID(deltaA, getCurrA360(drive_config::positionTracker.currA));
            right += drive->getDriveCorrectionPidController()->setPID(deltaA, getCurrA360(drive_config::positionTracker.currA));
            tankStraightDrive(left, right);

            if (fabsf(drive->getDriveStraightPidController()->pid->error) <= 0.5) {
                timer.startTimer();
            }
            if (timer.currentTime() > 300) {
                tankStraightDrive(0, 0);
                systemDone = true;
            }
            pros::delay(10);
        }
        timer.stopTimer();
        timer.zeroTimer();
    }
}