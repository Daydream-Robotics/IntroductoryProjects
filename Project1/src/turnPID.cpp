#include "turnPID.hpp"

// TODO: Tune PID values
constexpr double KP = 0.0;
constexpr double KI = 0.0;
constexpr double KD = 0.0;
constexpr double KI_LIMIT = 0.0;


// ! READ include/backend/odometry.hpp for how to get the current heading of the robot using odom.getYaw().
// ! THE OTHER ODOMETRY FUNCTIONS WILL NOT WORK. THAT IS CONFIGURED FOR A DIFFERENT ROBOT. DO NOT USE THEM. ONLY USE odom.getYaw() TO GET THE CURRENT HEADING OF THE ROBOT.

turnPID::turnPID() : m_config{KP, KI, KD, KI_LIMIT} {}

/**
 * @brief Updates the PID controller
 * @param target Target value
 * @param current Current value
 * @param dt Time step
 * @return Motor values
 */
motorValues turnPID::update(double target, double current, double dt) {
    // TODO: Fill this out with your PID control logic to calculate the motor values based on the target and current angles.
}

/**
 * @brief Turns the robot to an absolute angle
 * @param target Target angle
 */
void turnPID::turnAbsolute(double target) {
    // TODO: Fill this out with your logic to turn the robot to an absolute angle using the PID controller.

    // Repeat until settled or timeout:
    //   1. Read current heading from odom.getYaw().
    //   2. Calculate elapsed time dt in seconds.
    //   3. Call update(targetDegrees, currentHeading, dt).
    //   4. Apply returned values to the drive motors.
    //   5. Delay briefly before the next iteration.
}

/**
 * @brief Turns the robot by a relative angle
 * @param target Relative angle to turn
 */
void turnPID::turnRelative(double target) {
    // TODO: Fill this out with your logic to turn the robot by a relative angle using the PID controller.

    // Repeat until settled or timeout:
    //   1. Read current heading from odom.getYaw().
    //   2. Calculate elapsed time dt in seconds.
    //   3. Call update(targetDegrees, currentHeading, dt).
    //   4. Apply returned values to the drive motors.
    //   5. Delay briefly before the next iteration.
}

void turnPID::reset() {
    m_integral = 0.0;
    m_prevError = 0.0;
}