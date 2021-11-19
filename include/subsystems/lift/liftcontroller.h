#ifndef WISCOPROS2122_SUBSYSTEMS_LIFT_LIFTCONTROLLER_H_
#define WISCOPROS2122_SUBSYSTEMS_LIFT_LIFTCONTROLLER_H_

#include "main/main.h"
#include "subsystems/lift/lift.h"

namespace lift_controller {
    class LiftController {
     public:
        LiftController(lift::Lift *lift) {
            this->lift = lift;
        }

     protected:
        float getLeftSensVal();
        float getRightSensVal();
        float getStrafeSensVal();
        float getImuSensVal();
        float getLeftDistSensVal();
        float getRightDistSensVal();
        lift::Lift *lift;

     private:
        float getAvgLeftSensVal();
        float getAvgRightSensVal();
        float getAvgStrafeSensVal();
        
    };
}

#endif  // WISCOPROS2122_SUBSYSTEMS_LIFT_LIFTCONTROLLER_H_