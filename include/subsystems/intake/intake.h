#ifndef WISCOPROS2122_SUBSYSTEMS_INTAKE_INTAKE_H_
#define WISCOPROS2122_SUBSYSTEMS_INTAKE_INTAKE_H_

#include "main/main.h"

namespace intake
{
    enum PIDControllers {  // ames for different pid controllers
        DEFAULT
    };

    class IntakeBuilder;  // Forward declaration

    class Intake {
    public:
        friend class IntakeBuilder;
        static IntakeBuilder build();

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

    class IntakeBuilder {
    public:
        IntakeBuilder& withLeftMotor(pros::Motor *motor) {
            intake.leftMotors.push_back(motor);
            return *this;
        }

        IntakeBuilder& withRightMotor(pros::Motor *motor) {
            intake.rightMotors.push_back(motor);
            return *this;
        }

        IntakeBuilder& withLeftMotorV(std::vector<pros::Motor*> motors) {
            intake.leftMotors = motors;
            return *this;
        }

        IntakeBuilder& withRightMotorV(std::vector<pros::Motor*> motors) {
            intake.rightMotors = motors;
            return *this;
        }
                
        IntakeBuilder& withLeftRot(pros::Rotation *leftRot) {
            intake.leftRot = leftRot;
            return *this;
        }

        IntakeBuilder& withRightRot(pros::Rotation *rightRot) {
            intake.rightRot = rightRot;
            return *this;
        }

        operator Intake&&() {
            return std::move(intake);
        }

    private:
        Intake intake;
    };
}

#endif  // WISCOPROS2122_SUBSYSTEMS_INTAKE_INTAKE_H_