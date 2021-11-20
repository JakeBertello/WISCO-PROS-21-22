#include "config/liftconfig.h"

namespace lift_config {
    
    /********************************* LIFT_MOTORS *********************************/
    pros::Motor bassBoosterLeft(16, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor bassBoosterRight(6, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Motor updogLeft(17, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor updogRight(7, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Motor leftHooker(10, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightHooker(18, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);

    /********************************* LIFT_SENSORS *********************************/


    /********************************* LIFT_CONFIG *********************************/
    lift::Lift bassBooster = lift::Lift::build().withLeftMotor(&bassBoosterLeft)
                                                .withRightMotor(&bassBoosterRight);

    op_lift_controller::OpLiftController bassBoosterController(&bassBooster, &config::master);                                            


    lift::Lift updog = lift::Lift::build().withLeftMotor(&updogLeft)
                                                .withRightMotor(&updogRight);

    op_lift_controller::OpLiftController updogController(&updog, &config::master);

    lift::Lift hooker = lift::Lift::build().withLeftMotor(&leftHooker)
                                            .withRightMotor(&rightHooker);

    op_lift_controller::OpLiftController hookerController(&hooker, &config::master);

    void configureLifts() {
        bassBoosterLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        bassBoosterRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

        updogLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        updogRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

        leftHooker.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        rightHooker.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
}