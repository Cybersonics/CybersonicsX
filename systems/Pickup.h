#ifndef Pickup_H
#define Pickup_H

#include "WPILib.h"
#include "../utils/Controls.h"

class Pickup {

private:
	static Pickup* m_instance;

    Talon* m_IntakeMotor;
    Talon* m_Pickuprm;

    Controls* m_controls;

    int m_lowerArmLimit;
    int m_upperArmLimit;

    bool buttonPressed;

    //Solenoid* m_armSolenoid;

	
public:
	static Pickup* GetInstance();
	Pickup();

    void EnableTeleopControls();

    void MoveArm(float speed);
    void StartPickup();
    void StopPickup();
};

#endif
