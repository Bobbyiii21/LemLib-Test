#include "main.h"

using namespace pros;

//Motor Definitions
Motor leftMotor1(2, E_MOTOR_GEARSET_06, true); // PORT 2, 600 RPM, REVERSED
Motor leftMotor2(3, E_MOTOR_GEARSET_06, true); // PORT 3, 600 RPM, REVERSED
Motor leftMotor3(5, E_MOTOR_GEARSET_06,true); // PORT 5, 600 RPM, REVERSED

Motor rightMotor1(1, E_MOTOR_GEARSET_06, false); // PORT 1, 600 RPM, NOT REVERSED
Motor rightMotor2(4, E_MOTOR_GEARSET_06, false); // PORT 4, 600 RPM, NOT REVERSED
Motor rightMotor3(6, E_MOTOR_GEARSET_06, false); // PORT 6, 600 RPM, NOT REVERSED

//MotorGroup Definitions
MotorGroup leftMotors({leftMotor1, leftMotor2, leftMotor3});
MotorGroup rightMotors({rightMotor1, rightMotor2, rightMotor3});

//LemLib
lemlib::Drivetrain_t drivetrain {
    &leftMotors, //Left Motors
    &rightMotors, //Right Motors
    10, //Track Width
    3.25, //Wheel Diameter
    360, //Wheel RPM

};

//Lateral Motion Controller
lemlib::ChassisController_t lateralController {
    10, //kp
    30, //KD
    1, //Small Error
    100, //Small Error Timeout
    3, //large Error
	500, //Large Error Timeout
	20 //slew

};

lemlib::ChassisController_t angularController {
	2, //kp
	10, //kd
	1, //small error
	100, //small error timeout
	3, //large error
	500, //large error timeout
	3 //slew
};

lemlib::OdomSensors_t sensors {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &inertial
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);

//Sensor Definitions
IMU inertial(7); // PORT 7, INERTIAL SENSOR

//Controller Definitions
Controller master(E_CONTROLLER_MASTER); // MASTER CONTROLLER