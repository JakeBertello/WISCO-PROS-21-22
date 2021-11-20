#ifndef WISCOPROS2122_CONFIG_CONFIG_H_
#define WISCOPROS2122_CONFIG_CONFIG_H_

#include "main/main.h"
#include "misc/controllerinputs.h"
#include "misc/inputconverter.h"

namespace config {
    extern pros::Controller master;

    extern void setAutonRunBtn(controller_input btn);
}

#endif  // WISCOPROS2122_CONFIG_CONFIG_H_