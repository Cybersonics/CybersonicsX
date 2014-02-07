#ifndef CONSTANTS_H
#define CONSTANTS_H

#define CybersonicA

#ifdef CybersonicA
	#define ROBOT "A"
	//Any other robot A specific constants
#endif

#ifdef CybersonicB
	#define ROBOT "B"
	//Any other robot B specific constants
#endif

// PNEUMATICS

static const int COMPRESSOR_RELAY_CHAN = 1;
static const int PRESSURE_SWITCH_CHAN = 14;

static const int SHIFTER_FORWARD_CHAN = 1;
static const int SHIFTER_REVERSE_CHAN = 2;

static const int BRAKES_FORWARD_CHAN = 3;
static const int BRAKES_REVERSE_CHAN = 4;

// SHOOTER A (JACK'S SHOOTER)
static const int LAUNCHER_A_FORWARD_SOLENOID = 1024;
static const int LAUNCHER_A_REVERSE_SOLENOID = 1024;
static const int LAUNCHER_A_TRIGGER_FORWARD_SOLENOID = 1024;
static const int LAUNCHER_A_TRIGGER_REVERSE_SOLENOID = 1024
		
// SHOOTER B (WILLMAN'S SHOOTER_
static const int LAUNCHER_B_TRIGGER_FORWARD_SOLENOID = 1024;
static const int LAUNCHER_B_TRIGGER_REVERSE_SOLENOID = 1024;


// MOTORS

static const int LEFT_DRIVE_PWM = 1;
static const int RIGHT_DRIVE_PWM = 2;

static const int PICKUP_PWM = 4;


// CONTROLS

static const int LEFT_JOYSTICK_PORT = 1;
static const int RIGHT_JOYSTICK_PORT = 2;
static const int SHOOTER_JOYSTICK_PORT = 3;

//STRING POT

static const int TILT_POT_CHAN = 3;
static const int MAST_POT_CHAN = 4;

// SENSORS

static const int LEFT_ENCODER_A = 1;
static const int LEFT_ENCODER_B = 2;
static const int RIGHT_ENCODER_A = 3;
static const int RIGHT_ENCODER_B = 4;

static const int GYRO_CHANNEL = 1;
static const float GYRO_SENSITIVITY = 0.007; // 7 mV/deg/sec

static const int ULTRASONIC_CHANNEL = 2;

// ENCODER PID
static const float LEFT_ENCODER_P = 0.015;
static const float LEFT_ENCODER_I = 0.0;
static const float LEFT_ENCODER_D = 0.0;

static const float RIGHT_ENCODER_P = 0.013;
static const float RIGHT_ENCODER_I = 0.0;
static const float RIGHT_ENCODER_D = 0.0;

// GYRO PID
static const float GYRO_P = 0.013022;
static const float GYRO_I = 0.0;
static const float GYRO_D = 0.002116;

// DRIVE STRAIGHT
static const float DRIVE_STRAIGHT_P = 0.0002;

// Encoders are geared at a 1:1 ratio.
// TODO: Configuration for left and right sides of drivetrain.
static const double TIRE_CIRCUMFERENCE = 27.75; 	// in inches
static const double COUNTS_PER_REVOLUTION = 128.0;
static const double INCHES_PER_COUNT = TIRE_CIRCUMFERENCE / COUNTS_PER_REVOLUTION;

#endif
