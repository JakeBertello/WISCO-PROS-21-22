#ifndef WISCOPROS2122_CONFIG_LIFTCONFIG_H_
#define WISCOPROS2122_CONFIG_LIFTCONFIG_H_

#include "subsystems/lift/opliftcontroller.h"
#include "config/config.h"
#include "main/main.h"
    
namespace lift_config {
    /********************************* LIFT_MOTORS *********************************/
    extern pros::Motor bassBoosterLeft;
    extern pros::Motor bassBoosterRight;

    extern pros::Motor normalLiftLeft;
    extern pros::Motor normalLiftRight;

    /********************************* LIFT_SENSORS *********************************/


    /********************************* LIFT_CONFIG *********************************/
    extern lift::Lift bassBooster;
    extern op_lift_controller::OpLiftController bassBoosterController;

    extern lift::Lift normalLift;
    extern op_lift_controller::OpLiftController normalLiftController;
}

#endif  // WISCOPROS2122_CONFIG_LIFTCONFIG_H_