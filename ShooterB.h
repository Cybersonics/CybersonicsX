#ifndef Shooter_2_H
#define Shooter_2_H

#include "WPILib.h"
#include "Controls.h"

class ShooterB {
	
private:
	static ShooterB* m_instance;

	Controls* m_controls;
	
	DoubleSolenoid* m_Trigger;
	
	Talon* m_shooterMotor;
	
	AnalogChannel* m_motorPot;
	
	Timer* timer;
	
	bool m_shooterLoading;
	
	int m_shooterLoadLimit;

public:
	static ShooterB* GetInstance();
	
	ShooterB();
	
	void Shoot();
	void Reset();
	void LoadShooter();
	bool IsShooterResetting();
	bool IsSolenoidReset();
	
	void EnableTeleopControls();

};

#endif
