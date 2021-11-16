#ifndef WISCOPROS2122_CONFIG_INTAKECONFIG_H_
#define WISCOPROS2122_CONFIG_INTAKECONFIG_H_

#include "subsystems/intake/opintakecontroller.h"
#include "config/config.h"
#include "main/main.h"

namespace intake_config {
    /********************************* INTAKE_MOTORS *********************************/
    extern pros::Motor grabberMotor;

    /********************************* INTAKE_SENSORS *********************************/

    /********************************* INTAKE_CONFIG *********************************/
    extern intake::Intake grabber;

    extern op_intake_controller::OpIntakeController grabberController;

    extern void configureIntakes();
}

#endif // WISCOPROS2122_CONFIG_INTAKECONFIG_H_