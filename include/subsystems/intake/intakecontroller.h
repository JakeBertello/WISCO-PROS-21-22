#ifndef WISCOPROS2122_SUBSYSTEMS_INTAKE_INTAKECONTROLLER_H_
#define WISCOPROS2122_SUBSYSTEMS_INTAKE_INTAKECONTROLLER_H_

#include "main/main.h"
#include "intake.h"

namespace intake_controller {
    class IntakeController {
     public:
        IntakeController(intake::Intake *intake) {
            this->intake = intake;
        }

     protected:
        float getLeftSensVal();
        float getRightSensVal();
        float getStrafeSensVal();
        float getImuSensVal();
        float getLeftDistSensVal();
        float getRightDistSensVal();
        intake::Intake *intake;

     private:
        float getAvgLeftSensVal();
        float getAvgRightSensVal();
        float getAvgStrafeSensVal();
        
    };
}

#endif  // WISCOPROS2122_SUBSYSTEMS_INTAKE_INTAKECONTROLLER_H_