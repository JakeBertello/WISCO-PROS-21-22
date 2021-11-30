// Inclusion guard
#ifndef WISCOPROS2122_CONFIG_CONFIG_H_
#define WISCOPROS2122_CONFIG_CONFIG_H_

// Included libraries
#include "main/main.h"
#include "misc/controllerinputs.h"
#include "misc/inputconverter.h"

// Defines a namespace for the listed items
namespace config {
    extern pros::Controller master;

    extern void setAutonRunBtn(controller_input btn);
}

#endif  // WISCOPROS2122_CONFIG_CONFIG_H_