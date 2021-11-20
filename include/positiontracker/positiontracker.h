#ifndef WISCOPROS2122_POSITIONTRACKER_POSITIONTRACKER_H_
#define WISCOPROS2122_POSITIONTRACKER_POSITIONTRACKER_H_

#include "main/main.h"
#include "positiontracker/positiontrackerconfig.h"

namespace position_tracker {
    class PositionTracker {
     public: 
        PositionTracker();

        float encTicksPerRotation;
        
        float leftEncWheelD;
        float rightEncWheelD;
        float strafeEncWheelD;

        float leftEncWheelDFromC;
        float rightEncWheelDFromC;
        float strafeEncWheelDFromC;

        float currLeftEnc;
        float currRightEnc;
        float currStrafeEnc;

        float prevLeftEnc;
        float prevRightEnc;
        float prevStrafeEnc;

        float globLeftEnc;
        float globRightEnc;
        float globStrafeEnc;

        float deltaL;
        float deltaR;
        float deltaS;

        float deltaA;
        float deltaX;
        float deltaY;

        float currX;
        float currY;
        float currA;

        float distTraveled;
        float distTraveledStrafe;
    };
}

#endif  // WISCOPROS2122_POSITIONTRACKER_POSITIONTRACKER_H_