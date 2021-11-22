#include "positiontrackercontroller.h"
#include "config/driveconfig.h"

namespace position_tracker_controller {
    void PositionTrackerController::updatePosition() {
        positionTracker->currLeftEnc = drive->getLeftRot()->get_position();
        positionTracker->currRightEnc = drive->getRightRot()->get_position();
        positionTracker->currStrafeEnc = drive->getStrafeRot()->get_position();

        float deltaLEnc = positionTracker->currLeftEnc - positionTracker->prevLeftEnc;
        float deltaREnc = positionTracker->currRightEnc - positionTracker->prevRightEnc;
        float deltaSEnc = positionTracker->currStrafeEnc - positionTracker->prevStrafeEnc;

        positionTracker->deltaL = distWheelMoved(deltaLEnc, positionTracker->leftEncWheelD, positionTracker->encTicksPerRotation);
        positionTracker->deltaR = distWheelMoved(deltaREnc, positionTracker->rightEncWheelD, positionTracker->encTicksPerRotation);
        positionTracker->deltaS = distWheelMoved(deltaSEnc, positionTracker->strafeEncWheelD, positionTracker->encTicksPerRotation);

        positionTracker->prevLeftEnc = positionTracker->currLeftEnc;
        positionTracker->prevRightEnc = positionTracker->currRightEnc;
        positionTracker->prevStrafeEnc = positionTracker->currStrafeEnc;

        positionTracker->globLeftEnc += deltaLEnc;
        positionTracker->globRightEnc += deltaREnc;
        positionTracker->globStrafeEnc += deltaSEnc; 

        // if (positionTrackerFirstRun)
        // {
        //     positionTrackerFirstRun = false;
        //     return;
        // }
        positionTracker->deltaA = (positionTracker->deltaL - positionTracker->deltaR) / (positionTracker->leftEncWheelDFromC + positionTracker->rightEncWheelDFromC);

        if (positionTracker->deltaA == 0)
        {
            positionTracker->distTraveledStrafe = positionTracker->deltaS;
            positionTracker->distTraveled = positionTracker->deltaR;
        }
        else
        {
            positionTracker->distTraveledStrafe = (2 * sin(positionTracker->deltaA / 2) * ((positionTracker->deltaS / positionTracker->deltaA) + positionTracker->strafeEncWheelDFromC));
            positionTracker->distTraveled = (2 * sin(positionTracker->deltaA / 2) * ((positionTracker->deltaR / positionTracker->deltaA) + positionTracker->rightEncWheelDFromC));
        }

        positionTracker->currX += positionTracker->distTraveled * sin(positionTracker->currA + (positionTracker->deltaA / 2));
        positionTracker->currY += positionTracker->distTraveled * cos(positionTracker->currA + (positionTracker->deltaA / 2));
        
        positionTracker->currX += positionTracker->distTraveledStrafe * cos(positionTracker->currA + (positionTracker->deltaA / 2));
        positionTracker->currY += positionTracker->distTraveledStrafe * -sin(positionTracker->currA + (positionTracker->deltaA / 2));
        
        positionTracker->currA += positionTracker->deltaA;
    }

    float PositionTrackerController::distWheelMoved(float ticks, float wheelD, float ticksPerRotation) {
        return (ticks / ticksPerRotation) * (wheelD * (float)okapi::pi);
    }

    void PositionTrackerController::reset() {
        positionTracker->currLeftEnc = 0;
        positionTracker->currRightEnc = 0;
        positionTracker->currStrafeEnc = 0;
        positionTracker->prevLeftEnc = 0;
        positionTracker->prevRightEnc = 0;
        positionTracker->prevStrafeEnc = 0;
        positionTracker->globLeftEnc = 0;
        positionTracker->globRightEnc = 0;
        positionTracker->globStrafeEnc = 0;
        positionTracker->deltaL = 0;
        positionTracker->deltaR = 0;
        positionTracker->deltaS = 0;
        positionTracker->deltaA = 0;
        positionTracker->deltaX = 0;
        positionTracker->deltaY = 0;
        positionTracker->currX = 0;
        positionTracker->currY = 0;
        positionTracker->currA = 0;
        positionTracker->distTraveled = 0;
        positionTracker->distTraveledStrafe = 0;
    }

    void PositionTrackerController::calibrateConstants(float turnDegrees) {
        drive_config::autonDriveController.turnInertPID(turnDegrees);
        float angle = drive_config::driveController.getImuSensVal();

        float circumferenceOfRotWheel = okapi::pi * position_tracker_config::DEFAULT_ENC_WHEEL_D;
        float countsPerRotationPerInch = position_tracker_config::DEFAULT_ENC_TICKS_PER_ROTATION / circumferenceOfRotWheel;
        float turnDegreesInRadians = (turnDegrees * okapi::pi) / 180;

        float rotSum = drive_config::driveController.getLeftSensVal() + drive_config::driveController.getRightSensVal();

        float encoderTickOffsetPerDegree = rotSum / angle;
        float distanceBetweenLeftAndRightRot = (2 * turnDegrees * encoderTickOffsetPerDegree) / (okapi::pi * countsPerRotationPerInch);
        float distanceFromCenterStrafeRot = ((drive_config::driveController.getStrafeSensVal() / position_tracker_config::DEFAULT_ENC_TICKS_PER_ROTATION) 
                                        * circumferenceOfRotWheel) / turnDegreesInRadians;
        printf("distBetweenLeftAndRight = %8.4f\r\n", distanceBetweenLeftAndRightRot);
        printf("distFromLeft = %8.4f\r\n", distanceBetweenLeftAndRightRot / 2);
        printf("distFromRight = %8.4f\r\n", distanceBetweenLeftAndRightRot / 2);
        printf("distFromCenterStrafe = %8.4f\r\n", distanceFromCenterStrafeRot);
    }
}