#include "turnPID.hpp"
#include "backend/odometry.hpp"
#include "backend/subsystems.hpp"
#include <algorithm>
#include <chrono>
#include <cmath>

// * You may modify the implementation of any function within this file

// TODO: Tune PID values
constexpr double KP = 0.0;
constexpr double KI = 0.0;
constexpr double KD = 0.0;

// ! HINT: READ include/backend/odometry.hpp for how to get the current heading of the robot using odom.getYaw().
// ! THE OTHER ODOMETRY FUNCTIONS WILL NOT WORK. THAT IS CONFIGURED FOR A DIFFERENT ROBOT. DO NOT USE THEM. ONLY USE odom.getYaw() TO GET THE CURRENT HEADING OF THE ROBOT.

turnPID::turnPID() : m_config{KP, KI, KD} {}

motorValues turnPID::update(double target, double current) {
    double error, derivative = 0.0;

    auto now = std::chrono::steady_clock::now();
    double dt = std::chrono::duration<double>(now - m_prevUpdateTime).count();
    m_prevUpdateTime = now;

    error = std::remainder(target - current, 2.0 * M_PI);
    m_integral += error * dt;
    if (dt > 0.0) {
        derivative = std::remainder(error - m_prevError, 2.0 * M_PI) / dt;
    }
    m_prevError = error;

    double output = m_config.m_kp * error 
        + m_config.m_ki * m_integral
        + m_config.m_kd * derivative;

    output = std::clamp(output, -127.0, 127.0);

    // Positive heading error requires a counterclockwise turn.
    return {-output, output};
}

void turnPID::turnAbsolute(double target) {
    const double targetRadians = target * M_PI / 180.0;
    reset();
    m_prevError = std::remainder(targetRadians - odom.getYaw(), 2.0 * M_PI);
    
    // Stop after 100 ms within one degree, or after 3 seconds.
    const auto start = pros::millis();
    int settled = 0;
    double currentHeading;
    while (pros::millis() - start < 3000 && settled < 10) {
        currentHeading = odom.getYaw();
        if (!std::isfinite(currentHeading) || std::abs(currentHeading) > M_PI
            || !std::isfinite(targetRadians)) break;
        const motorValues values = update(targetRadians, currentHeading);
        settled = std::abs(m_prevError) < M_PI / 180.0 ? settled + 1 : 0;
        leftMotors.move(values.left);
        rightMotors.move(values.right);
        pros::delay(10);
    }

    leftMotors.move(0);
    rightMotors.move(0);
}

void turnPID::turnRelative(double target) {
    // TODO: Fill this out with your logic to turn the robot by a relative angle using the PID controller.

    // Calculate targetRadians once as the starting heading plus target converted to radians.
    // Reset, then set m_prevError to the initial angle error in radians.
    // Repeat until settled or timeout:
    //   1. Read current heading in radians from odom.getYaw().
    //   2. Call update(targetRadians, currentHeading); it calculates dt internally.
    //   3. Apply returned values to the drive motors.
    //   4. Delay briefly before the next iteration.
    //   5. Stop both drive motors after the loop

    double currentHeading = odom.getYaw();
    double currentDegrees = currentHeading * 180.0 / M_PI;

    turnAbsolute(currentDegrees + target);
}

void turnPID::reset() {
    m_integral = 0.0;
    m_prevError = 0.0;
    m_prevUpdateTime = std::chrono::steady_clock::now();
}
