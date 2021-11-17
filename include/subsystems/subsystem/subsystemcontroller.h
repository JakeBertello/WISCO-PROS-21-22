#ifndef WISCOPROS2122_SUBSYSTEMS_SUBSYSTEM_SUBSYSTEMCONTROLLER_H_
#define WISCOPROS2122_SUBSYSTEMS_SUBSYSTEM_SUBSYSTEMCONTROLLER_H_

#include "main/main.h"
#include "subsystems/subsystem/subsystem.h"
#include "subsystems/lift/opliftcontroller.h"

namespace subsystem_controller {

    template <class T>
    class SubsystemController {
     public:

        template <class T>
        SubsystemController<op_lift_controller::OpLiftController>(lift::Lift *subsystem) {
            this->subsystem = subsystem;
        }
        
     protected:
        float getLeftSensVal();
        float getRightSensVal();
        float getStrafeSensVal();
        float getImuSensVal();
        float getLeftDistSensVal();
        float getRightDistSensVal();
        subsystem::Subsystem<lift::Lift> *subsystem;

     private:
        float getAvgLeftSensVal();
        float getAvgRightSensVal();
        float getAvgStrafeSensVal();
        
    };

    template <class T>
    float SubsystemController<T>::getLeftSensVal() {
        float val = 0.0;
        if (subsystem->getLeftRot() != nullptr) {
            val = subsystem->getLeftRot()->get_position();
        } else {
            if (subsystem->getLeftMotors().size() != 0) {
                val = getAvgLeftSensVal();
            }
        }
        return val;
    }

    template <class T>
    float SubsystemController<T>::getRightSensVal() {
        float val = 0.0;
        if (subsystem->getRightRot() != nullptr) {
            val = subsystem->getRightRot()->get_position();
        } else {
            if (subsystem->getRightMotors().size() != 0) {
                val = getAvgRightSensVal();
            }
        }
        return val;
    }

    template <class T>
    float SubsystemController<T>::getAvgLeftSensVal() {
        float sum = 0.0;

        for (pros::Motor *motor : subsystem->getLeftMotors()) {
            sum += motor->get_position();
        }

        return sum / subsystem->getLeftMotors().size();
    }

    template <class T>
    float SubsystemController<T>::getAvgRightSensVal() {
        float sum = 0.0;

        for (pros::Motor *motor : subsystem->getRightMotors()) {
            sum += motor->get_direction();
        }

        return sum / subsystem->getRightMotors().size();
    }
}

#endif  // WISCOPROS2122_SUBSYSTEMS_SUBSYSTEM_SUBSYSTEMCONTROLLER_H_