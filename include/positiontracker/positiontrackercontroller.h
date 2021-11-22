#ifndef WISCOPROS2122_POSITIONTRACKER_POSITIONTRACKERCONTROLLER_H_
#define WISCOPROS2122_POSITIONTRACKER_POSITIONTRACKERCONTROLLER_H_

#include "main/main.h"
#include "subsystems/drive/drive.h"
#include "positiontracker/positiontracker.h"
#include <cmath>

namespace position_tracker_controller {
    class PositionTrackerController {
     public:
        PositionTrackerController(position_tracker::PositionTracker *positionTracker, drive::Drive *drive) {
            this->positionTracker = positionTracker;
            this->drive = drive;
        }

        void updatePosition();
        void reset();
        void calibrateConstants(float turnDegrees);

     private:
        float distWheelMoved(float ticks, float wheelD, float ticksPerRotation);
        position_tracker::PositionTracker *positionTracker;
        drive::Drive *drive;
    };
}

#endif  // WISCOPROS2122_POSITIONTRACKER_POSITIONTRACKERCONTROLLER_H_