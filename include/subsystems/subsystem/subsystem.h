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

    template<class T>
    SubsystemBuilder<T> Subsystem<T>::build() {
        return SubsystemBuilder<T>();
    }

    template<class T>
    std::vector<pros::Motor*> Subsystem<T>::getLeftMotors() {
        return Subsystem::leftMotors;
    }

    template<class T>
    std::vector<pros::Motor*> Subsystem<T>::getRightMotors() {
        return Subsystem::rightMotors;
    }

    template<class T>
    pros::Rotation* Subsystem<T>::getLeftRot() {
        return Subsystem::leftRot;
    }

    template<class T>
    pros::Rotation* Subsystem<T>::getRightRot() {
        return Subsystem::rightRot;
    }

    template <class T>
    class SubsystemBuilder {
     public:
        SubsystemBuilder<T>& withLeftMotor(pros::Motor *motor) {
            _subsystem.leftMotors.push_back(motor);
            return *this;
        }

        SubsystemBuilder<T>& withRightMotor(pros::Motor *motor) {
            _subsystem.rightMotors.push_back(motor);
            return *this;
        }

        SubsystemBuilder<T>& withLeftMotorV(std::vector<pros::Motor*> motors) {
            _subsystem.leftMotors = motors;
            return *this;
        }

        SubsystemBuilder<T>& withRightMotorV(std::vector<pros::Motor*> motors) {
            _subsystem.rightMotors = motors;
            return *this;
        }
                
        SubsystemBuilder<T>& withLeftRot(pros::Rotation *leftRot) {
            _subsystem.leftRot = leftRot;
            return *this;
        }

        SubsystemBuilder<T>& withRightRot(pros::Rotation *rightRot) {
            _subsystem.rightRot = rightRot;
            return *this;
        }

        operator Subsystem<T>&&() {
            return std::move(_subsystem);
        }

     private:
        T _subsystem;
    };
}


#endif  // WISCOPROS2122_SUBSYSTEMS_SUBSYSTEM_SUBSYSTEM_H_