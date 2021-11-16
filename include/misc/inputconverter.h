#ifndef WISCOPROS2122_MISC_INPUTCONVERTER_H_
#define WISCOPROS2122_MISC_INPUTCONVERTER_H_

#include "main/main.h"
#include "controllerinputs.h"

namespace input_converter {
    class InputConverter {
     public:
        static InputConverter& getInstance() {
            static InputConverter instance;
            return instance;
        }

        pros::controller_digital_e_t convertButton(controller_input input);
        pros::controller_analog_e_t convertJoy(controller_input input);

     private:
        InputConverter() {}

        // InputConverter(InputConverter const&);
        // void operator=(InputConverter const&);

    //  public:
    //     InputConverter(InputConverter const&) = delete;
    //     void operator=(InputConverter const&) = delete;     
    };
    
};

#endif  // WISCOPROS2122_MISC_INPUTCONVERTER_H_