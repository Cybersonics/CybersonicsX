#include "WPILib.h"
#include "Shooter.h"
#include "../utils/Controls.h"
#include "../utils/Constants.h"

Shooter* Shooter::m_instance = NULL;

Shooter* Shooter::GetInstance() {
  if (m_instance == NULL) {
    m_instance = new Shooter();
  }
  return m_instance;
}

Shooter::Shooter ()
{
    m_controls = Controls::GetInstance();

    m_Launcher = new DoubleSolenoid(LAUNCHER_FORWARD_SOLENOID, LAUNCHER_REVERSE_SOLENOID);
    m_Trigger = new DoubleSolenoid(LAUNCHER_TRIGGER_FORWARD_SOLENOID, LAUNCHER_TRIGGER_REVERSE_SOLENOID);

    ShooterReset = Waiting;
    CheckReset(); // Make sure JackShooter is in the correct position (trigger on, firing Solenoids on)

}

void Shooter::EnableTeleopControls ()
{
	/*
	 * If shooter button is pressed and shooter is not resetting, then shoot
	 * else if shooter is resetting, then continue resetting
	 */
    
}

void Shooter::Reset() // Pulls 'firing' solenoids back
{
	/*
	 * if shooter just fired, begin to pull launcher solenoids back
	 * else if launcher solenoids finished resetting, then fire trigger to lock solenoids
	 * else if trigger has finished firing, then fire launcher solenoids
	 */
}

void Shooter::Shoot() // Pulls back trigger, set 'firing' solenoids launch ball
{
	// Pull back trigger
	// set shooterReset to firing
	
    //m_Trigger->Set(DoubleSolenoid::kReverse);
    //ShooterReset = Firing;

}

void Shooter::PullBackLauncher() 
{
	// Pull back launcher solenoids
	// set shooterReset to resetting
	
    //m_Launcher->Set(DoubleSolenoid::kReverse);
    //ShooterReset = Resetting;
}

void Shooter::Lock() 
{
	// Fire trigger solenoid to lock launching solenoid
	// set shooterReset to locking
	
    //m_Trigger->Set(DoubleSolenoid::kForward);
    //ShooterReset = Locking;
}

void Shooter::Set()
{
	// Fire launcher solenoids (note, not actually shooting the ball)
	// set shooterReset to waiting
	
    //m_Launcher->Set(DoubleSolenoid::kForward);
    //ShooterReset = Waiting;
}

void Shooter::CheckReset()
{
	/*
	 * if shooter is not resetting
	 * 		if launcher solenoid is fired && trigger is not fired, then call reset
	 * 		if launcher solenoid is not fired && trigger is not fired, then call lock
	 * 		else if trigger is fired, then call set
	 */
}
