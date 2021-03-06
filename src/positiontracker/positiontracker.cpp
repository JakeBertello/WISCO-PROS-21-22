#include "positiontracker.h"

namespace position_tracker {
    PositionTracker::PositionTracker() {
        encTicksPerRotation = position_tracker_config::DEFAULT_ENC_TICKS_PER_ROTATION;

        leftEncWheelD = position_tracker_config::DEFAULT_ENC_WHEEL_D;
        rightEncWheelD = position_tracker_config::DEFAULT_ENC_WHEEL_D;
        strafeEncWheelD = position_tracker_config::DEFAULT_ENC_WHEEL_D;

        leftEncWheelDFromC = position_tracker_config::LEFT_ENC_DIST_FROM_C;
        rightEncWheelDFromC = position_tracker_config::RIGHT_ENC_DIST_FROM_C;
        strafeEncWheelDFromC = position_tracker_config::STRAFE_ENC_DIST_FROM_C;

        currLeftEnc = 0;
        currRightEnc = 0;
        currStrafeEnc = 0;

        prevLeftEnc = 0;
        prevRightEnc = 0;
        prevStrafeEnc = 0;

        globLeftEnc = 0;
        globRightEnc = 0;
        globStrafeEnc = 0;

        deltaL = 0;
        deltaR = 0;
        deltaS = 0;

        deltaA = 0;
        deltaX = 0;
        deltaY = 0;

        currX = 0;
        currY = 0;
        currA = 0;

        distTraveled = 0;
        distTraveledStrafe = 0;
    }
}