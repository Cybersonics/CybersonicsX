#ifndef DRIVETRAIN_H_
#define DRIVETRAIN_H_

#include "WPILib.h"
#include "../utils/Controls.h"

class Drivetrain {

private:
	static Drivetrain* m_instance;
	
	Controls* m_controls;
	
	Talon* m_leftDriveA;
	Talon* m_leftDriveB;
	Talon* m_rightDriveA;
	Talon* m_rightDriveB;
	
	Encoder* m_leftEncoder;
	Encoder* m_rightEncoder;
	
	PIDController* m_leftEncoderControllerA;
	PIDController* m_leftEncoderControllerB;
	PIDController* m_rightEncoderControllerA;
	PIDController* m_rightEncoderControllerB;
	
	DoubleSolenoid* m_Shifter;
	DoubleSolenoid* m_Brakes;
	
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
	
	void SetEncoderPID(float p, float i, float d);
	void SetLeftEncoderPID(float p, float i, float d);
	void SetRightEncoderPID(float p, float i, float d);
};

#endif
