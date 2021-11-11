#ifndef WISCOPROS2122_POSITIONTRACKER_POSITIONTRACKER_H_
#define WISCOPROS2122_POSITIONTRACKER_POSITIONTRACKER_H_

#include "main/main.h"

namespace position_tracker {
    class PositionTracker {
        float leftEncWheelD = DEFAULT_ENC_WHEEL_D;
        float rightEncWheelD = DEFAULT_ENC_WHEEL_D;
        float strafeEncWheelD = DEFAULT_ENC_WHEEL_D;

        float currLeftEnc = 0;
        float currRightEnc = 0;
        float currStrafeEnc = 0;

        float prevLeftEnc = 0;
        float prevRightEnc = 0;
        float prevStrafeEnc = 0;

        float globLeftEnc = 0;
        float globRightEnc = 0;
        float globStrafeEnc = 0;
        
        float deltaL = 0;
        float deltaR = 0;
        float deltaS = 0;

        float deltaA = 0;
        float deltaX = 0;
        float deltaY = 0;

        float currX = 0;
        float currY = 0;
        float currA = 0;

        float distTraveled = 0;
        float distTraveledStrafe = 0;

        // bool positionTrackerFirstRun = true;

    public:
        void reset();

        float getCurrLeftEnc();
        float getCurrRightEnc();
        float getCurrStrafeEnc();

        float getCurrX();
        float getCurrY();
        float getCurrA();


    private: 
        float distWheelMoved(float ticks, float wheelD, float ticksPerRotation);

    };
}

#endif  // WISCOPROS2122_POSITIONTRACKER_POSITIONTRACKER_H_