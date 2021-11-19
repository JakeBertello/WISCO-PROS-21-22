#ifndef WISCOPROS2122_SUBSYSTEMS_SUBSYSTEM_SUBSYSTEMCONTROLLER_H_
#define WISCOPROS2122_SUBSYSTEMS_SUBSYSTEM_SUBSYSTEMCONTROLLER_H_

#include "main/main.h"
#include "subsystems/subsystem/subsystem.h"

namespace subsystem_controller {
    class SubsystemController {
     public:
        SubsystemController(subsystem::Subsystem *subsystem) {
            this->subsystem = subsystem;
        }
        
     protected:
        float getLeftSensVal();
        float getRightSensVal();
        float getStrafeSensVal();
        float getImuSensVal();
        float getLeftDistSensVal();
        float getRightDistSensVal();
        subsystem::Subsystem *subsystem;

     private:
        float getAvgLeftSensVal();
        float getAvgRightSensVal();
        float getAvgStrafeSensVal();
        
    };




}

#endif  // WISCOPROS2122_SUBSYSTEMS_SUBSYSTEM_SUBSYSTEMCONTROLLER_H_