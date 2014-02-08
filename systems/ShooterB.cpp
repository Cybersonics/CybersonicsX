#include "WPILib.h"
#include "ShooterB.h"
#include "../utils/Controls.h"
#include "../utils/Constants.h"

ShooterB* ShooterB::m_instance = NULL;

ShooterB* ShooterB::GetInstance() {
  if (m_instance == NULL) {
    m_instance = new ShooterB();
  }
  return m_instance;
}

ShooterB::ShooterB ()
{
    m_controls = Controls::GetInstance();

    m_Trigger = new DoubleSolenoid(LAUNCHER_B_TRIGGER_FORWARD_SOLENOID, LAUNCHER_B_TRIGGER_REVERSE_SOLENOID);

    m_shooterMotor = new Talon(SHOOTER_B_MOTOR);

    //m_motorPot = new AnalogChannel(SHOOTER_B_MOTOR_POT);

    m_shooterWenchLimit = 1024;

    m_shooterWenching = false;

    timer = new Timer();

}

void ShooterB::EnableTeleopControls ()
{
	/*
	 * If shooter button is pressed && trigger is not released, then shoot
	 * else if wench button pressed or if launcher is already being wenched and the trigger is engaged, then continue wenching
	 * 
	 * If trigger is not engaged and launcher finished firing, then reengage trigger
	 */
}

void ShooterB::Shoot()
{
	// Release trigger
	// reset wench encoder?
}

void ShooterB::Reset()
{
	// Reengage trigger
	
    //m_Trigger->Set(DoubleSolenoid::kForward);
}

void ShooterB::LoadShooter()
{
	/*
	 * If the motor exceeds its wenching limit or if the limit switch goes off, stop the motor
	 * else then continue wenching
	 */
}

bool ShooterB::IsShooterResetting()
{
	// return value of m_shooterWenching
	
    //return m_shooterWenching;
}

bool ShooterB::IsTriggerEngaged()
{
	// Return value of trigger solenoid
}
