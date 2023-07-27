#include "api.h"
using namespace pros;

//Motor Definitions
extern Motor leftMotor1;
extern Motor leftMotor2;
extern Motor leftMotor3;

extern Motor rightMotor1;
extern Motor rightMotor2;
extern Motor rightMotor3;

//MotorGroup Definitions
extern MotorGroup leftMotors;
extern MotorGroup rightMotors;

//LemLib

extern lemlib::Drivetrain_t drivetrain;
extern lemlib::ChassisController_t lateralController;
extern lemlib::ChassisController_t angularController;
extern lemlib::OdomSensors_t odomSensors;
extern lemlib::Chassis chassis;

//Sensor Definitions
extern IMU inertial;

//Controller Definitions
extern Controller master;