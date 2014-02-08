#include "WPILib.h"
#include "ShooterA.h"
#include "../utils/Controls.h"
#include "../utils/Constants.h"

ShooterA* ShooterA::m_instance = NULL;

ShooterA* ShooterA::GetInstance() {
  if (m_instance == NULL) {
    m_instance = new ShooterA();
  }
  return m_instance;
}

ShooterA::ShooterA ()
{
    m_controls = Controls::GetInstance();

    m_LauncherA = new DoubleSolenoid(LAUNCHER_A_A_FORWARD_CHAN, LAUNCHER_A_A_REVERSE_CHAN);
    m_LauncherB = new DoubleSolenoid(LAUNCHER_A_B_FORWARD_CHAN, LAUNCHER_A_B_REVERSE_CHAN);
    m_Trigger = new DoubleSolenoid(LAUNCHER_A_TRIGGER_FORWARD_CHAN, LAUNCHER_A_TRIGGER_REVERSE_CHAN);

    ShooterReset = Waiting;
    CheckReset(); // Make sure JackShooter is in the correct position (trigger on, firing Solenoids on)

}

void ShooterA::EnableTeleopControls ()
{
	/*
	 * If shooter button is pressed and shooter is not resetting, then shoot
	 * else if shooter is resetting, then continue resetting
	 */
    
}

void ShooterA::Reset() // Pulls 'firing' solenoids back
{
	/*
	 * if shooter just fired, begin to pull launcher solenoids back
	 * else if launcher solenoids finished resetting, then fire trigger to lock solenoids
	 * else if trigger has finished firing, then fire launcher solenoids
	 */
}

void ShooterA::Shoot() // Pulls back trigger, set 'firing' solenoids launch ball
{
	// Pull back trigger
	// set shooterReset to firing
	
    //m_Trigger->Set(DoubleSolenoid::kReverse);
    //ShooterReset = Firing;

}

void ShooterA::PullBackLauncher() 
{
	// Pull back launcher solenoids
	// set shooterReset to resetting
	
    //m_Launcher->Set(DoubleSolenoid::kReverse);
    //ShooterReset = Resetting;
}

void ShooterA::Lock() 
{
	// Fire trigger solenoid to lock launching solenoid
	// set shooterReset to locking
	
    //m_Trigger->Set(DoubleSolenoid::kForward);
    //ShooterReset = Locking;
}

void ShooterA::Set()
{
	// Fire launcher solenoids (note, not actually shooting the ball)
	// set shooterReset to waiting
	
    //m_Launcher->Set(DoubleSolenoid::kForward);
    //ShooterReset = Waiting;
}

void ShooterA::CheckReset()
{
	/*
	 * if shooter is not resetting
	 * 		if launcher solenoid is fired && trigger is not fired, then call reset
	 * 		if launcher solenoid is not fired && trigger is not fired, then call lock
	 * 		else if trigger is fired, then call set
	 */
}
