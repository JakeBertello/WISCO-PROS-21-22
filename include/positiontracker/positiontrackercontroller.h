#ifndef WISCOPROS2122_POSITIONTRACKER_POSITIONTRACKERCONTROLLER_H_
#define WISCOPROS2122_POSITIONTRACKER_POSITIONTRACKERCONTROLLER_H_

#include "main/main.h"
#include "drive/drive.h"

namespace position_tracker_controller {
    class PositionTrackerController {
     private:
        drive::Drive drive;
    };
}

#endif  // WISCOPROS2122_POSITIONTRACKER_POSITIONTRACKERCONTROLLER_H_