#include "intakecontroller.h"

// namespace intake_controller {
//     float IntakeController::getLeftSensVal() {
//         float val = 0.0;
//         if (intake->getLeftRot() != nullptr) {
//             val = intake->getLeftRot()->get_position();
//         } else {
//             if (intake->getLeftMotors().size() != 0) {
//                 val = getAvgLeftSensVal();
//             }
//         }
//         return val;
//     }

//     float IntakeController::getRightSensVal() {
//         float val = 0.0;
//         if (intake->getRightRot() != nullptr) {
//             val = intake->getRightRot()->get_position();
//         } else {
//             if (intake->getRightMotors().size() != 0) {
//                 val = getAvgRightSensVal();
//             }
//         }
//         return val;
//     }

//     float IntakeController::getAvgLeftSensVal() {
//         float sum = 0.0;

//         for (pros::Motor *motor : intake->getLeftMotors()) {
//             sum += motor->get_position();
//         }

//         return sum / intake->getLeftMotors().size();
//     }

//     float IntakeController::getAvgRightSensVal() {
//         float sum = 0.0;

//         for (pros::Motor *motor : intake->getRightMotors()) {
//             sum += motor->get_direction();
//         }

//         return sum / intake->getRightMotors().size();
//     }
// }