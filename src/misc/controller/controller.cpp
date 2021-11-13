#include "misc/controller/controller.h"

namespace controller {
    int Controller::leftJoyX() {
        return pros::Controller::get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
    }

    int Controller::leftJoyY() {
        return pros::Controller::get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    }

    int Controller::rightJoyX() {
        return pros::Controller::get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);        
    }

    int Controller::rightJoyY() {
        return pros::Controller::get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    }

    int Controller::l1() {
        return pros::Controller::get_digital(pros::E_CONTROLLER_DIGITAL_L1);
    }

    int Controller::l2() {
        return pros::Controller::get_digital(pros::E_CONTROLLER_DIGITAL_L2);
    }

    int Controller::r1() {
        return pros::Controller::get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    }

    int Controller::r2() {
        return pros::Controller::get_digital(pros::E_CONTROLLER_DIGITAL_R2);
    }

    int Controller::up() {
        return pros::Controller::get_digital(pros::E_CONTROLLER_DIGITAL_UP);
    }

    int Controller::down() {
        return pros::Controller::get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
    }

    int Controller::left() {
        return pros::Controller::get_digital(pros::E_CONTROLLER_DIGITAL_LEFT);
    }

    int Controller::right() {
        return pros::Controller::get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT);
    }

    int Controller::x() {
        return pros::Controller::get_digital(pros::E_CONTROLLER_DIGITAL_X);
    }

    int Controller::y() {
        return pros::Controller::get_digital(pros::E_CONTROLLER_DIGITAL_Y);
    }

    int Controller::b() {
        return pros::Controller::get_digital(pros::E_CONTROLLER_DIGITAL_B);
    }

    int Controller::a() {
        return pros::Controller::get_digital(pros::E_CONTROLLER_DIGITAL_A);
    }
}
