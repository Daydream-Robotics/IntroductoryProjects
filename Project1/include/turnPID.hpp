#pragma once

struct motorValues {
    double left;
    double right;
};

struct turnPIDConfig {
    double m_kp;
    double m_ki;
    double m_kd;
    double m_kiLimit;
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
         * @param dt Time step
         * @return Motor values
         */
        motorValues update(double target, double current, double dt);

        /** 
         * @brief Turns the robot to an absolute angle
         * @param target Target angle
         */
        void turnAbsolute(double target);

        /** 
         * @brief Turns the robot by a relative angle
         * @param target Relative angle to turn
         */
        void turnRelative(double target);

        /** 
         * 5@brief Resets the PID controller
         */
        void reset();

    private:
        turnPIDConfig m_config;
        double m_prevError = 0.0;
        double m_integral = 0.0;

};