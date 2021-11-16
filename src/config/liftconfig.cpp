#include "config/liftconfig.h"

namespace lift_config {
    
    /********************************* LIFT_MOTORS *********************************/
    pros::Motor bassBoosterLeft(14, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor bassBoosterRight(7, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Motor normalLiftLeft(16, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor normalLiftRight(6, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

    /********************************* LIFT_SENSORS *********************************/


    /********************************* LIFT_CONFIG *********************************/
    lift::Lift bassBooster = lift::Lift::build().withLeftMotor(&bassBoosterLeft)
                                                .withRightMotor(&bassBoosterRight);

    op_lift_controller::OpLiftController bassBoosterController(&bassBooster, &config::master);                                            


    lift::Lift normalLift = lift::Lift::build().withLeftMotor(&normalLiftLeft)
                                                .withRightMotor(&normalLiftRight);

    op_lift_controller::OpLiftController normalLiftController(&normalLift, &config::master);

    void configureLifts() {
        bassBoosterLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        bassBoosterRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

        normalLiftLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        normalLiftRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
}