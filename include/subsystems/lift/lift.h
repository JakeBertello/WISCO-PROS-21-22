#ifndef WISCOPROS2122_SUBSYSTEMS_LIFT_LIFT_H_
#define WISCOPROS2122_SUBSYSTEMS_LIFT_LIFT_H_

#include "main/main.h"

namespace lift
{
    enum PIDControllers {  // names for different pid controllers
        DEFAULT
    };

    class LiftBuilder;  // Forward declaration

    class Lift {
    public:
        friend class LiftBuilder;
        static LiftBuilder build();

        std::vector<pros::Motor*> getLeftMotors();
        std::vector<pros::Motor*> getRightMotors();
        pros::Rotation* getLeftRot();
        pros::Rotation* getRightRot();

    private:
        std::vector<pros::Motor*> leftMotors;
        std::vector<pros::Motor*> rightMotors;
        std::vector<pros::Motor*> strafeMotors;
        pros::Rotation *leftRot = nullptr;
        pros::Rotation *rightRot = nullptr;
        //addposition tracker and pid controllers
    };

    class LiftBuilder {
    public:
        LiftBuilder& withLeftMotor(pros::Motor *motor) {
            lift.leftMotors.push_back(motor);
            return *this;
        }

        LiftBuilder& withRightMotor(pros::Motor *motor) {
            lift.rightMotors.push_back(motor);
            return *this;
        }

        LiftBuilder& withLeftMotorV(std::vector<pros::Motor*> motors) {
            lift.leftMotors = motors;
            return *this;
        }

        LiftBuilder& withRightMotorV(std::vector<pros::Motor*> motors) {
            lift.rightMotors = motors;
            return *this;
        }
                
        LiftBuilder& withLeftRot(pros::Rotation *leftRot) {
            lift.leftRot = leftRot;
            return *this;
        }

        LiftBuilder& withRightRot(pros::Rotation *rightRot) {
            lift.rightRot = rightRot;
            return *this;
        }

        operator Lift&&() {
            return std::move(lift);
        }

    private:
        Lift lift;
    };
}

#endif  // WISCOPROS2122_SUBSYSTEMS_LIFT_LIFT_H_