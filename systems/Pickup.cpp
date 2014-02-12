#include "WPILib.h"
#include "Pickup.h"
#include "../utils/Constants.h"
#include "../utils/Controls.h"

Pickup* Pickup::m_instance = NULL;

Pickup* Pickup::GetInstance() {
  if (m_instance == NULL) {
    m_instance = new Pickup();
  }
  return m_instance;
}

Pickup::Pickup ()
{
    m_controls = Controls::GetInstance();

    m_IntakeMotor = new Talon(PICKUP_INTAKE_MOTOR);
    m_Pickuprm = new Talon(PICKUP_ARM_MOTOR);

    m_lowerArmLimit = 1024;
    m_upperArmLimit = 1024;

    buttonPressed = false;
}
void Pickup::EnableTeleopControls()
{
	/*
	 * if joystick input is positive && arm is under its upper limit, then move arm 
	 * else if joystick input is negative, and arm is over its lower limit, then move arm
	 * else stop moving arm
	 * 
	 * if pickup button is pressed && pickup motor is not moving, start pickup motor
	 * else if pickup button is pressed && pickup motor is moving, stop pickup motor
	 */
}

void Pickup::StartPickup()
{
	// Turn on pickup motor
	
    //m_pickupMotor->Set(1.0);
}

void Pickup::StopPickup()
{
	// Stop pickup motor
	
    //m_pickupMotor->Set(0.0);
}

void Pickup::MoveArm(float speed)
{
	// set Pickuprm motor to speed
	
    //m_Pickuprm->Set(speed);
}
