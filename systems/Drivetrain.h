#ifndef DRIVETRAIN_H_
#define DRIVETRAIN_H_

#include "WPILib.h"
#include "../utils/Controls.h"

class Drivetrain {

private:
	static Drivetrain* m_instance;
	
	Controls* m_controls;
	
	Talon* m_leftDrive;
	Talon* m_rightDrive;
	
	Encoder* m_leftEncoder;
	Encoder* m_rightEncoder;
	
	DoubleSolenoid* m_Shifter;
	
	DoubleSolenoid* m_Brakes;
	
	PIDController* m_leftEncoderController;
	PIDController* m_rightEncoderController;
	
	Gyro* m_gyro;
	
	AnalogChannel* m_ultrasonic;
		
	PIDController* m_gyroController;
	
	bool m_isTurning;
	bool m_isDrivingStraight;
	
	Timer* m_timer;
	bool m_timerStopped;

public:
	static Drivetrain* GetInstance();
	Drivetrain();
	void EnableTeleopControls();
	
	void SetSpeed(float speed);
	void SetLeftSpeed(float speed);
	void SetRightSpeed(float speed);
	
	float GetLeftSpeed();
	float GetRightSpeed();
	
	void ShiftHigh();
	void ShiftLow();
	
	void BrakesOn();
	void BrakesOff();
	bool brakesLocked();
	
	int GetLeftEncoderCount();
	int GetRightEncoderCount();
	void ResetEncoders();
	
	void SetEncoderSetpoint(float inches);
	void EnableEncoderPid();
	void DisableEncoderPid();
	bool EncoderPidIsEnabled();
	
	void ResetGyro();
	float GetGyroAngle();
	bool Turn(float setpoint, float tolerance, float maxSpeed = 1.0);
	bool IsTurning();
	void EnableGyroPid();
	void DisableGyroPid();
	void SetGyroSetpoint(float angle);
	
	float Drivetrain::GetUltrasonicDistance();
	
	// TODO: REMOVE HACK
	PIDController* GetGyroController();
	void SetEncoderPID(float p, float i, float d);
	void SetLeftEncoderPID(float p, float i, float d);
	void SetRightEncoderPID(float p, float i, float d);
	
	bool DriveStraight(float setpoint, float tolerance, float p, float maxSpeed = 1.0);
	bool DriveForward(float setpoint, float tolerance);
};

#endif