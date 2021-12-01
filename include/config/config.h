/**
 * @file config.h
 * @author Jacob Bertello
 * @brief This file contains the configuration for the controller
 * @version 1.0
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// Inclusion guard
#ifndef WISCOPROS2122_CONFIG_CONFIG_H_
#define WISCOPROS2122_CONFIG_CONFIG_H_

// Included libraries
#include "main/main.h"
#include "misc/controllerinputs.h"
#include "misc/inputconverter.h"

/**
 * @brief This namespace contains the configuration items/methods for the system.
 * 
 */
namespace config 
{
    /**
     * @brief The controller which allows the user to control the system
     * 
     */
    extern pros::Controller master;

    /**
     * @brief Set which button runs the autonomous routine
     * 
     * @param btn The button being set to run the auton
     */
    extern void setAutonRunBtn(controller_input btn);
}

#endif  // WISCOPROS2122_CONFIG_CONFIG_H_