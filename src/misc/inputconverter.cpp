#include "inputconverter.h"
namespace input_converter {
pros::controller_digital_e_t InputConverter::convertButton(controller_input input) {
        pros::controller_digital_e_t button;
        switch (input) {
            case R1:
                button = pros::E_CONTROLLER_DIGITAL_R1;
                break;
            
            case R2:
                button = pros::E_CONTROLLER_DIGITAL_R2;
                break;

            case L1:
                button = pros::E_CONTROLLER_DIGITAL_L1;
                break;
            
            case L2:
                button = pros::E_CONTROLLER_DIGITAL_L2;
                break;
            
            case A:
                button = pros::E_CONTROLLER_DIGITAL_A;
                break;
            
            case B:
                button = pros::E_CONTROLLER_DIGITAL_B;
                break;
                
            case Y:
                button = pros::E_CONTROLLER_DIGITAL_Y;
                break;
            
            case X:
                button = pros::E_CONTROLLER_DIGITAL_X;
                break;

            case LEFT:
                button = pros::E_CONTROLLER_DIGITAL_LEFT;
                break;
            
            case RIGHT:
                button = pros::E_CONTROLLER_DIGITAL_RIGHT;
                break;
                
            case UP:
                button = pros::E_CONTROLLER_DIGITAL_UP;
                break;
            
            case DOWN:
                button = pros::E_CONTROLLER_DIGITAL_DOWN;
                break;
        }
        return button;
    }

    pros::controller_analog_e_t InputConverter::convertJoy(controller_input input) {
        pros::controller_analog_e_t joy;
        switch (input) {
            case LJOYX:
                joy = pros::E_CONTROLLER_ANALOG_LEFT_X;
                break;
            
            case LJOYY:
                joy = pros::E_CONTROLLER_ANALOG_LEFT_Y;
                break;
                
            case RJOYX:
                joy = pros::E_CONTROLLER_ANALOG_RIGHT_X;
                break;
            
            case RJOYY:
                joy = pros::E_CONTROLLER_ANALOG_RIGHT_Y;
                break;
        }
        return joy;
    }
}
