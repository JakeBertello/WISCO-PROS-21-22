#include "subsystems/drive/autondrivecontroller.h"

namespace auton_drive_controller {
    void AutonDriveController::turnInertPID(float target) {
        bool systemDone = false;
        timer::Timer intakeTimer;
        pros::lcd::clear_line(6);
        pros::lcd::clear_line(7);
        intakeTimer.stopTimer();
        intakeTimer.zeroTimer();
        while (!systemDone)
        {
            pros::lcd::print(0, "errorDrive = %8.4f", drive->getTurnLongPidController()->pid->error);
            pros::lcd::print(1, "integral = %8.4f", drive->getTurnLongPidController()->pid->integral);
            pros::lcd::print(2, "derivative = %8.4f", drive->getTurnLongPidController()->pid->derivative);
            pros::lcd::print(3, "target = %8.4f", drive->getTurnLongPidController()->pid->target);
            DriveController::tankStraightDrive(drive->getTurnLongPidController()->setPID(target, drive->getImu()->get_heading()),
                            -drive->getTurnLongPidController()->setPID(target, drive->getImu()->get_heading()));
            if (drive->getTurnLongPidController()->pid->error <= 0.5)
            {
                intakeTimer.startTimer();
            }
            if (intakeTimer.currentTime() > 300)
            {
                tankStraightDrive(0, 0);
                pros::lcd::print(6, "error and time limit reached");
                systemDone = true;
            }
            pros::delay(10);
        }
        systemDone = false;
        pros::lcd::print(7, "exited loop");
        tankStraightDrive(0, 0);
    }
}