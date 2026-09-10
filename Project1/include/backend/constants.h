/**
 * \file constants.h
 *
 * Contains constants used throughout the robot.
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H
 #include <stdio.h>

/* - - - - - - - - - - - - - - [PORTS] - - - - - - - - - - - - - - */

constexpr int PARALLEL_TRACKING_WHEEL_PORT = 6;
constexpr int PERPENDICULAR_TRACKING_WHEEL_PORT = 10;

// TODO: Fix these ports to match your robot's configuration. The left and right drive wheel ports order does not matter, but left vs right does.
#define LEFT_DRIVE_WHEEL_PORTS {-11, -12, -13}
#define RIGHT_DRIVE_WHEEL_PORTS {18, 19, 20}

constexpr int INITIAL_INTAKE_PORT = 1;
constexpr int INITIAL_INTAKE_PORT2 = -17;
constexpr int LEVER_ONE_PORT = -9;
constexpr int LEVER_TWO_PORT = 14;

// TODO: Fix these ports to match your robot's configuration. The IMU port should be the port number of the IMU sensor.
constexpr char IMU_PORT = 1; 

constexpr char BALL_BLOCKER_PORT = 'A';
constexpr char SCORING_LIFTER = 'B';
constexpr char MATCHLOADER_PORT = 'C';
constexpr char DESCORE_PORT = 'D'; 

/* - - - - - - - - - - - - - - [ODOMETRY] - - - - - - - - - - - - - - */

// diameter of tracking wheels in inches
constexpr double PARALLEL_TRACKING_WHEEL_DIAMETER = 2.03895;
constexpr double PERPENDICULAR_TRACKING_WHEEL_DIAMETER = 2.0425;

// distance from tracking center to wheels
constexpr double PARALLEL_TRACKING_WHEEL_OFFSET = 0.0; // positive is to the right of tracking center
constexpr double PERPINDICULAR_TRACKING_WHEEL_OFFSET = 0.0; // positive is behind tracking center

/* - - - - - - - - - - - - - - [ROBOT DIMS] - - - - - - - - - - - - - - */

constexpr double DRIVE_WHEEL_DIAMETER_INCHES = 3.25;

/* - - - - - - - - - - - - - - [DRIVE] - - - - - - - - - - - - - - */

constexpr int DEADZONE = 2;

/* - - - - - - - - - - - - - - [GENERAL] - - - - - - - - - - - - - - */

constexpr int MAX_VOLTAGE = 127;
constexpr int HIGH_VOLTAGE = 100;
constexpr int MID_VOLTAGE = 60;
constexpr int LOW_VOLTAGE = 40;
constexpr int STOP = 0;

/* - - - - - - - - - - - - - - [PIDS] - - - - - - - - - - - - - - */

constexpr double DISTANCE_KP = 4.25;
constexpr double DISTANCE_KI = 0.0; 
constexpr double DISTANCE_KD = 0.0; 
constexpr double DISTANCE_KI_THRESHOLD = 1.0;

constexpr double HEADING_KP = 0.01; 
constexpr double HEADING_KI = 0.0;
constexpr double HEADING_KD = 0.0;  
constexpr double HEADING_KI_THRESHOLD = 0.0;

// Tune the turn PID gains in src/turnPID.cpp.


/* - - - - - - - - - - - - - - [Motion Controllers] - - - - - - - - - - - - - - */
constexpr double END_TOLERANCE = 0.5;

enum class DriveType {
    SPLIT_ARCADE,
    TANK
};


#endif
