#include "turnPID.hpp"
#include <chrono>

// * You may modify the implementation of any function within this file

// TODO: Tune PID values
constexpr double KP = 0.0;
constexpr double KI = 0.0;
constexpr double KD = 0.0;

// ! HINT: READ include/backend/odometry.hpp for how to get the current heading of the robot using odom.getYaw().
// ! THE OTHER ODOMETRY FUNCTIONS WILL NOT WORK. THAT IS CONFIGURED FOR A DIFFERENT ROBOT. DO NOT USE THEM. ONLY USE odom.getYaw() TO GET THE CURRENT HEADING OF THE ROBOT.

turnPID::turnPID() : m_config{KP, KI, KD} {}

motorValues turnPID::update(double target, double current) {
    // TODO: Calculate dt in ms
    // * HINT: steady_clock::now() and std::chrono::duration<double, std::milli>

    // TODO: Fill this out with your PID control logic to calculate the motor values based on the target and current angles.
    // pid_output = (error * kp) + (integral * ki) + (derivative * kd)

    return {0.0, 0.0}; // Replace with the calculated motor values.
}

void turnPID::turnAbsolute(double target) {
    // TODO: Fill this out with your logic to turn the robot to an absolute angle using the PID controller.

    // Reset, then set m_prevError to the initial angle error.
    // Repeat until settled or timeout:
    //   1. Read current heading from odom.getYaw() and convert radians to degrees.
    //   2. Call update(target, currentHeading); it calculates dt internally.
    //   3. Apply returned values to the drive motors.
    //   4. Delay briefly before the next iteration.
    //   5. Stop both drive motors after the loop
}

void turnPID::turnRelative(double target) {
    // TODO: Fill this out with your logic to turn the robot by a relative angle using the PID controller.

    // Calculate targetDegrees once as the starting heading plus the relative target.
    // Reset, then set m_prevError to the initial angle error.
    // Repeat until settled or timeout:
    //   1. Read current heading from odom.getYaw() and convert radians to degrees.
    //   2. Call update(targetDegrees, currentHeading); it calculates dt internally.
    //   3. Apply returned values to the drive motors.
    //   4. Delay briefly before the next iteration.
    //   5. Stop both drive motors after the loop
}

void turnPID::reset() {
    m_integral = 0.0;
    m_prevError = 0.0;
    m_prevUpdateTime = std::chrono::steady_clock::now();
}
