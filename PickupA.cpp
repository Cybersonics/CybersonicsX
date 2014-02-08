#include "WPILib.h"
#include "PickupA.h"
#include "utils/Constants.h"
#include "utils/Controls.h"

PickupA* PickupA::m_instance = NULL;

PickupA* PickupA::GetInstance() {
  if (m_instance == NULL) {
    m_instance = new PickupA();
  }
  return m_instance;
}

PickupA::PickupA ()
{
    m_controls = Controls::GetInstance();

    m_pickupMotor = new Talon(PICKUP_A_MOTOR);
    m_pickupArm = new Talon(PICKUP_A_ARM_MOTOR);

    m_lowerArmLimit = 1024;
    m_upperArmLimit = 1024;

    buttonPressed = false;
}
void PickupA::EnableTeleopControls()
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

void PickupA::StartPickup()
{
	// Turn on pickup motor
	
    //m_pickupMotor->Set(1.0);
}

void PickupA::StopPickup()
{
	// Stop pickup motor
	
    //m_pickupMotor->Set(0.0);
}

void PickupA::MoveArm(float speed)
{
	// set pickupArm motor to speed
	
    //m_pickupArm->Set(speed);
}
