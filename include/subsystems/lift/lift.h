#ifndef WISCOPROS2122_SUBSYSTEMS_LIFT_LIFT_H_
#define WISCOPROS2122_SUBSYSTEMS_LIFT_LIFT_H_

#include "main/main.h"
#include "subsystems/subsystem/subsystem.h"

namespace lift {
    enum PIDControllers {  // names for different pid controllers
        DEFAULT
    };

    class LiftBuilder;  // Forward declaration

    class Lift : public subsystem::Subsystem<Lift> {
        Lift() : subsystem::Subsystem<Lift>() {

        }
    };
}

#endif  // WISCOPROS2122_SUBSYSTEMS_LIFT_LIFT_H_