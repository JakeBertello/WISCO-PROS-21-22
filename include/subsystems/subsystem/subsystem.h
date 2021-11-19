#ifndef WISCOPROS2122_SUBSYSTEMS_SUBSYSTEM_SUBSYSTEM_H_
#define WISCOPROS2122_SUBSYSTEMS_SUBSYSTEM_SUBSYSTEM_H_

#include "main/main.h"
#include "subsystems/drive/drive.h"


namespace subsystem {

    class SubsystemBuilder;
    
    class Subsystem {
     public:
        friend class SubsystemBuilder;
        static SubsystemBuilder build();

        std::vector<pros::Motor*> getLeftMotors();
        std::vector<pros::Motor*> getRightMotors();
        pros::Rotation* getLeftRot();
        pros::Rotation* getRightRot();
    
     private:
        std::vector<pros::Motor*> leftMotors;
        std::vector<pros::Motor*> rightMotors;
        pros::Rotation *leftRot = nullptr;
        pros::Rotation *rightRot = nullptr;
        //addposition tracker and pid controllers
    };

    class SubsystemBuilder {
     public:
        SubsystemBuilder& withLeftMotor(pros::Motor *motor) {
            _subsystem.leftMotors.push_back(motor);
            return *this;
        }

        SubsystemBuilder& withRightMotor(pros::Motor *motor) {
            _subsystem.rightMotors.push_back(motor);
            return *this;
        }

        SubsystemBuilder& withLeftMotorV(std::vector<pros::Motor*> motors) {
            _subsystem.leftMotors = motors;
            return *this;
        }

        SubsystemBuilder& withRightMotorV(std::vector<pros::Motor*> motors) {
            _subsystem.rightMotors = motors;
            return *this;
        }
                
        SubsystemBuilder& withLeftRot(pros::Rotation *leftRot) {
            _subsystem.leftRot = leftRot;
            return *this;
        }

        SubsystemBuilder& withRightRot(pros::Rotation *rightRot) {
            _subsystem.rightRot = rightRot;
            return *this;
        }

        operator Subsystem&&() {
            return std::move(_subsystem);
        }

     private:
        Subsystem _subsystem;
    };
}


#endif  // WISCOPROS2122_SUBSYSTEMS_SUBSYSTEM_SUBSYSTEM_H_