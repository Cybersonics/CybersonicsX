#include "WPILib.h"
#include "ShooterA.h"
#include "Controls.h"
#include "utils/Constants.h"

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

    m_Launcher = new DoubleSolenoid(LAUNCHER_FORWARD_SOLENOID, LAUNCHER_REVERSE_SOLENOID);
    m_Trigger = new DoubleSolenoid(LAUNCHER_TRIGGER_FORWARD_SOLENOID, LAUNCHER_TRIGGER_REVERSE_SOLENOID);

    ShooterReset = Waiting;
    CheckReset(); // Make sure JackShooter is in the correct position (trigger on, firing Solenoids on)

}

void ShooterA::EnableTeleopControls ()
{
    if (m_controls->GetShooterButton(SHOOTER_BUTTON) && ShooterReset == Waiting) {
        Shoot();
    } else if (ShooterReset != Waiting) {
    	Reset();
    }
    
}

void ShooterA::Reset() // Pulls 'firing' solenoids back
{
	if (ShooterReset == Firing && m_Launcher->Get() == DoubleSolenoid::kForward) { // May need to check if Get value is taken from  the last command recieved or current state
        PullBackLauncher();
    } else if (ShooterReset == Resetting && m_Launcher->Get() == DoubleSolenoid::kForward) {
        Lock();
    } else if (ShooterReset == Locking && m_Trigger->Get() == DoubleSolenoid::kForward) {
        Set();
    }
}

void ShooterA::Shoot() // Pulls back trigger, set 'firing' solenoids launch ball
{
    m_Trigger->Set(DoubleSolenoid::kReverse);
    ShooterReset = Firing;

}

void ShooterA::PullBackLauncher() 
{
    m_Launcher->Set(DoubleSolenoid::kReverse);
    ShooterReset = Resetting;
}

void ShooterA::Lock() // Fires trigger, to lock 'firing' solenoids
{
    m_Trigger->Set(DoubleSolenoid::kForward);
    ShooterReset = Locking;
}

void ShooterA::Set() // Fires 'firing' solenoids to prepare the launcher
{
    m_Launcher->Set(DoubleSolenoid::kForward);
    ShooterReset = Waiting;
}

void ShooterA::CheckReset()
{
    if (ShooterReset != false) {
        if (m_Launcher->Get() == DoubleSolenoid::kForward) {
            if (m_Trigger->Get() == DoubleSolenoid::kReverse) {
                Reset();
            } else {
                // Ready to fire
            }
        } else if (m_Launcher->Get() == DoubleSolenoid::kForward) {
            if (m_Trigger->Get() == DoubleSolenoid::kReverse) {
                Lock();
            } else {
                Set();
            }
        } else {
            // Something is wrong.
            Reset();
        }
    } else {
        // Shooter is already being reset
    }
}
