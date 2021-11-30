// Inclusion guard
#ifndef WISCOPROS2122_CONFIG_LIFTCONFIG_H_
#define WISCOPROS2122_CONFIG_LIFTCONFIG_H_

// Included libraries
#include "subsystems/lift/opliftcontroller.h"
#include "subsystems/lift/autonliftcontroller.h"
#include "config/config.h"
#include "main/main.h"
    
// Defined namespace for the lift
namespace lift_config {
    /********************************* LIFT_MOTORS *********************************/
    extern pros::Motor bassBoosterLeft;
    extern pros::Motor bassBoosterRight;

    extern pros::Motor updogLeft;
    extern pros::Motor updogRight;

    extern pros::Motor leftHooker;
    extern pros::Motor rightHooker;

    /********************************* LIFT_SENSORS *********************************/


    /********************************* LIFT_CONFIG *********************************/
    extern lift::Lift bassBooster;
    extern op_lift_controller::OpLiftController bassBoosterController;

    extern lift::Lift updog;
    extern op_lift_controller::OpLiftController updogController;

    extern lift::Lift hooker;
    extern op_lift_controller::OpLiftController hookerController;
    extern auton_lift_controller::AutonLiftController autonHookerController;

    extern void configureLifts();
}

#endif  // WISCOPROS2122_CONFIG_LIFTCONFIG_H_