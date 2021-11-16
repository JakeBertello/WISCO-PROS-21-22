#include "config/intakeconfig.h"

namespace intake_config {

    /********************************* INTAKE_MOTORS *********************************/
    pros::Motor grabberMotor(19, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);

    /********************************* INTAKE_SENSORS *********************************/

    /********************************* INTAKE_CONFIG *********************************/
    intake::Intake grabber = intake::Intake::build().withLeftMotor(&grabberMotor);

    op_intake_controller::OpIntakeController grabberController(&grabber, &config::master);
    
}