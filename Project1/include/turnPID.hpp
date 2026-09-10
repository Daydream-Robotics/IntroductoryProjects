#pragma once

#include <chrono>

struct motorValues {
    double left;
    double right;
};

struct turnPIDConfig {
    double m_kp;
    double m_ki;
    double m_kd;
};

class turnPID {
    public:
        /** 
         * @brief Constructor for the turnPID class
        */
        turnPID();

        /** 
         * @brief Updates the PID controller
         * @param target Target value 
         * @param current Current value
         * @note dt is measured internally in milliseconds.
         * @return Motor values
         */
        motorValues update(double target, double current);

        /** 
         * @brief Turns the robot to a heading relative to the IMU's zero reference.
         * @param target Target angle in degrees
         */
        void turnAbsolute(double target);

        /** 
         * @brief Turns the robot by an angle relative to the robot's current orientation.
         * @param target Relative angle to turn in degrees
         */
        void turnRelative(double target);

        /** 
         * @brief Resets the PID controller and its timing history
         */
        void reset();

    private:
        turnPIDConfig m_config;
        double m_prevError = 0.0;
        double m_integral = 0.0;
        std::chrono::steady_clock::time_point m_prevUpdateTime = std::chrono::steady_clock::now();

        // * you may add additional member variables if needed
};
