/**
 * @file driveconfig.h
 * @author Jacob Bertello
 * @brief This file sets up the configuration for the drivetrain of the robot
 * @version 1.0
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// Inclusion guard
#ifndef WISCOPROS2122_CONFIG_DRIVECONFIG_H_
#define WISCOPROS2122_CONFIG_DRIVECONFIG_H_

// Included libraries
#include "positiontracker/positiontracker.h"
#include "positiontracker/positiontrackercontroller.h"
#include "subsystems/drive/autondrivecontroller.h"
#include "subsystems/drive/opdrivecontroller.h"
#include "pid/pidcontroller.h"
#include "config/config.h"
#include "main/main.h"

/**
 * @brief Defines the namespace which contains the objects used to initialize the drive 
 * 
 */
namespace drive_config {

    /********************************* DRIVE_MOTORS *********************************/
    
    /**
     * @brief The front left motor on the drivetrain
     * 
     */
    extern pros::Motor frontLeftDrive;

    /**
     * @brief The middle left motor on the drivetrain
     * 
     */
    extern pros::Motor middleLeftDrive;

    /**
     * @brief The rear left motor on the drivetrain
     * 
     */
    extern pros::Motor backLeftDrive;

    /**
     * @brief The front right motor on the drivetrain
     * 
     */
    extern pros::Motor frontRightDrive;

    /**
     * @brief The middle right motor on the drivetrain
     * 
     */
    extern pros::Motor middleRightDrive;

    /**
     * @brief The rear right motor on the drivetrain
     * 
     */
    extern pros::Motor backRightDrive;

    /********************************* DRIVE_SENSORS *********************************/

    /**
     * @brief The rotation sensor on the left tracking wheel
     * 
     */
    extern pros::Rotation leftRot;

    /**
     * @brief The rotation sensor on the right tracking wheel
     * 
     */
    extern pros::Rotation rightRot;

    /**
     * @brief The rotation sensor on the strafe tracking wheel
     * 
     */
    extern pros::Rotation strafeRot;

    /**
     * @brief The inertial sensor
     * 
     */
    extern pros::Imu imu;

    /**
     * @brief The distance sensor on the left side of the robot
     * 
     */
    extern pros::Distance leftDistance;

    /**
     * @brief The distance sensor on the right side of the robot
     * 
     */
    extern pros::Distance rightDistance;

    /********************************* DRIVE_CONFIG *********************************/

    /**
     * @brief The object which defines the drivetrain
     * 
     */
    extern drive::Drive drive;

    /**
     * @brief The object in charge of managing the operator input drive control
     * 
     */
    extern op_drive_controller::OpDriveController driveController;

    /**
     * @brief The object which tracks the current position of the drive
     * 
     */
    extern position_tracker::PositionTracker positionTracker;

    /**
     * @brief The object which controls the position tracking system
     * 
     */
    extern position_tracker_controller::PositionTrackerController positionTrackerController;

    /**
     * @brief The object in charge of managing the autonomous drive control
     * 
     */
    extern auton_drive_controller::AutonDriveController autonDriveController;

    /**
     * @brief The task which updates the position tracker
     * 
     */
    extern pros::Task positionTrackerTask;

    /********************************** DRIVE_PID ***********************************/
    extern pid::PID turnLongPID;
    extern pid_controller::PIDController turnLongPIDController;

    extern pid::PID turnShortPID;
    extern pid_controller::PIDController turnShortPIDController;

    extern pid::PID turnSweepPID;
    extern pid_controller::PIDController turnSweepPIDController;

    extern pid::PID driveStraightPID;
    extern pid_controller::PIDController driveStraightPIDController;

    extern pid::PID driveCorrectionPid;
    extern pid_controller::PIDController driveCorrectionPidController;

    /********************************** DRIVE_METHODS ********************************/
    extern void configureDrives();

    void positionTrackerTaskFN(void* param);
}

#endif  // WISCOPROS2122_CONFIG_DRIVECONFIG_H_