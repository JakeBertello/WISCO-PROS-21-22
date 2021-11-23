#include "subsystems/lift/autonliftcontroller.h"
#include "config/liftconfig.h"

namespace auton_lift_controller {
    void AutonLiftController::setHookersPos(float target, float speed) {
        float direction = target / fabsf(target);
        while (fabsf(lift_config::hookerController.getLeftSensVal()) < fabsf(target - 50) || fabsf(lift_config::hookerController.getLeftSensVal()) > fabsf(target + 50)) {
            moveHookers(speed * direction);
            pros::delay(10);
        }
        moveHookers(0);
    }
}