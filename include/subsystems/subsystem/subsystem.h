#ifndef WISCOPROS2122_SUBSYSTEMS_SUBSYSTEM_SUBSYSTEM_H_
#define WISCOPROS2122_SUBSYSTEMS_SUBSYSTEM_SUBSYSTEM_H_

#include "main/main.h"
#include "subsystems/drive/drive.h"


namespace subsystem {

    template <class T>
    class SubsystemBuilder;
    
    template <class T>
    class Subsystem {
     public:
        friend class SubsystemBuilder<T>;
        static SubsystemBuilder<T> build();

        Subsystem(T *inSubsystem) {
            this->inSubsystem = inSubsystem;
        }

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
        T *inSubsystem;
    };

    template <class T>
    class SubsystemBuilder {
     public:
        SubsystemBuilder& withLeftMotor(pros::Motor *motor) {
            sys.leftMotors.push_back(motor);
            return *this;
        }

        SubsystemBuilder& withRightMotor(pros::Motor *motor) {
            sys.rightMotors.push_back(motor);
            return *this;
        }

        SubsystemBuilder& withLeftMotorV(std::vector<pros::Motor*> motors) {
            sys.leftMotors = motors;
            return *this;
        }

        SubsystemBuilder& withRightMotorV(std::vector<pros::Motor*> motors) {
            sys.rightMotors = motors;
            return *this;
        }
                
        SubsystemBuilder& withLeftRot(pros::Rotation *leftRot) {
            sys.leftRot = leftRot;
            return *this;
        }

        SubsystemBuilder& withRightRot(pros::Rotation *rightRot) {
            sys.rightRot = rightRot;
            return *this;
        }

        operator Subsystem<drive::Drive>&&() {
            return std::move(sys);
        }

     private:
        Subsystem<T> sys = *inSubsystem;
    };
}


#endif  // WISCOPROS2122_SUBSYSTEMS_SUBSYSTEM_SUBSYSTEM_H_