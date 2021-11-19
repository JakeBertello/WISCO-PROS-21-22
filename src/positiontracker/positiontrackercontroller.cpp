#include "positiontrackercontroller.h"

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
        positionTracker->currStrafeEnc += deltaSEnc; 

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
}