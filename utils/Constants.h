#ifndef CONSTANTS_H
#define CONSTANTS_H

// PNEUMATICS

static const int COMPRESSOR_RELAY_CHAN = 1;
static const int PRESSURE_SWITCH_CHAN = 14;

static const int SHIFTER_FORWARD_CHAN = 1;
static const int SHIFTER_REVERSE_CHAN = 2;

static const int BRAKES_FORWARD_CHAN = 3;
static const int BRAKES_REVERSE_CHAN = 4;

static const int LAUNCHER_FORWARD_SOLENOID = 5;
static const int LAUNCHER_REVERSE_SOLENOID = 6;
static const int LAUNCHER_TRIGGER_FORWARD_SOLENOID = 7;
static const int LAUNCHER_TRIGGER_REVERSE_SOLENOID = 8;

// MOTORS

static const int LEFT_DRIVE_A_PWM = 1;
static const int LEFT_DRIVE_B_PWM = 2;
static const int RIGHT_DRIVE_A_PWM = 3;
static const int RIGHT_DRIVE_B_PWM = 4;

static const int PICKUP_INTAKE_MOTOR = 5;
static const int PICKUP_ARM_MOTOR = 6;


// CONTROLS

static const int LEFT_JOYSTICK_PORT = 1;
static const int RIGHT_JOYSTICK_PORT = 2;
static const int SHOOTER_JOYSTICK_PORT = 3;

// SENSORS

static const int LEFT_ENCODER_A = 1;
static const int LEFT_ENCODER_B = 2;
static const int RIGHT_ENCODER_A = 3;
static const int RIGHT_ENCODER_B = 4;


// ENCODER PID
static const float LEFT_ENCODER_P = 0.015;
static const float LEFT_ENCODER_I = 0.0;
static const float LEFT_ENCODER_D = 0.0;

static const float RIGHT_ENCODER_P = 0.013;
static const float RIGHT_ENCODER_I = 0.0;
static const float RIGHT_ENCODER_D = 0.0;


// DRIVE STRAIGHT
static const float DRIVE_STRAIGHT_P = 0.0002;

// Encoders are geared at a 1:1 ratio.
// TODO: Configuration for left and right sides of drivetrain.
static const double TIRE_CIRCUMFERENCE = 27.75; 	// in inches
static const double COUNTS_PER_REVOLUTION = 128.0;
static const double INCHES_PER_COUNT = TIRE_CIRCUMFERENCE / COUNTS_PER_REVOLUTION;

#endif
