#ifndef PICKUPA_H
#define PICKUPA_H

#include "WPILib.h"
#include "../utils/Controls.h"

class PickupA {

private:
	static PickupA* m_instance;

    Talon* m_IntakeMotor;
    Talon* m_pickupArm;

    Controls* m_controls;

    int m_lowerArmLimit;
    int m_upperArmLimit;

    bool buttonPressed;

    //Solenoid* m_armSolenoid;

	
public:
	static PickupA* GetInstance();
	PickupA();

    void EnableTeleopControls();

    void MoveArm(float speed);
    void StartPickup();
    void StopPickup();
};

#endif
