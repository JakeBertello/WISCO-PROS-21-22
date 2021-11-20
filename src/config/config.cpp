#include "config/config.h"

namespace config {
    pros::Controller master(pros::E_CONTROLLER_MASTER);

    void setAutonRunBtn(controller_input btn) {
        input_converter::InputConverter &inputConverter = input_converter::InputConverter::getInstance();
        if (master.get_digital(inputConverter.convertButton(btn))) {
            autonomous();
        }

        // if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
		// 	lcdCode::clearLCD();
		// 	pros::lcd::print(0, "Running autonomous %d", autonomousNS::autonomousMode);
		// 	switch (autonomousNS::autonomousMode) {
		// 		case 1:
		// 			autons::autonomous1();
		// 			break;
		// 		case 2:
		// 			autons::autonomous2();
		// 			break;
		// 		case 3:
		// 			autons::autonomous3();
		// 			break;
		// 		case 4:
		// 			autons::autonomous4();
		// 			break;
		// 		case 5:
		// 			autons::autonomous5();
		// 			break;
		// 		case 6:
		// 			autons::autonomous6();
		// 			break;
		// 		case 7:
		// 			autons::autonomous7();
		// 			break;
		// 		case 8:
		// 			autons::autonomous8();
		// 			break;
		// 		case 9:
		// 			autons::autonomous9();
		// 			break;
		// 		case 10:
		// 			autons::autonomous10();
		// 			break;
		// 		case 11:
		// 			autons::autonomous11();
		// 			break;
		// 		case 12:
		// 			autons::autonomous12();
		// 			break;
		// 		case 13:
		// 			autons::autonomous13();
		// 			break;
		// 		case 14:
		// 			autons::autonomous14();
		// 			break;
		// 		case 15:
		// 			autons::autonomous15();
		// 			break;
		// 		case 16:
		// 			autons::autonomous16();
		// 			break;
		// 	}
		// }
    }
}