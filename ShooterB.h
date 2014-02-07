#ifndef Shooter_2_H
#define Shooter_2_H

#include "WPILib.h"
#include "utils/Controls.h"

class ShooterB {
	
private:
	static ShooterB* m_instance;

	Controls* m_controls;
	
	DoubleSolenoid* m_Trigger;
	
	Talon* m_shooterMotor;
	
	AnalogChannel* m_motorPot;
	
	Timer* timer;
	
	bool m_shooterWenching;
	
	int m_shooterWenchLimit;

public:
	static ShooterB* GetInstance();
	
	ShooterB();
	
	void Shoot();
	void Reset();
	void LoadShooter();
	bool IsShooterResetting();
	bool IsTriggerEngaged();
	
	void EnableTeleopControls();

};

#endif
