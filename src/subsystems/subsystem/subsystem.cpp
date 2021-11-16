#include "subsystems/subsystem/subsystem.h"

namespace subsystem {
    template<class T>
    SubsystemBuilder<T> Subsystem<T>::build() {
        return SubsystemBuilder<T>();
    }

    template<class T>
    std::vector<pros::Motor*> Subsystem<T>::getLeftMotors() {
        return Subsystem::leftMotors;
    }

    template<class T>
    std::vector<pros::Motor*> Subsystem<T>::getRightMotors() {
        return Subsystem::rightMotors;
    }

    template<class T>
    pros::Rotation* Subsystem<T>::getLeftRot() {
        return Subsystem::leftRot;
    }

    template<class T>
    pros::Rotation* Subsystem<T>::getRightRot() {
        return Subsystem::rightRot;
    }
}