#ifndef WISCOPROS2122_MISC_DRIVE_CONTROLLER_CONTROLLER_H_
#define WISCOPROS2122_MISC_DRIVE_CONTROLLER_CONTROLLER_H_

#include "main/main.h"

namespace controller {
    class Controller : public pros::Controller {
     public:
        int leftJoyX();
        int leftJoyY();
        int rightJoyX();
        int rightJoyY();

        int l1();
        int l2();
        int r1();
        int r2();
        int up();
        int down();
        int left();
        int right();
        int x();
        int y();
        int b();
        int a();
    };
}

#endif  // WISCOPROS2122_MISC_DRIVE_CONTROLLER_CONTROLLER_H_