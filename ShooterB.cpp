#include "WPILib.h"
#include "ShooterB.h"
#include "Controls.h"
#include "Constants.h"

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

    m_Trigger = new Solenoid(LAUNCHER_B_TRIGGER_FORWARD_SOLENOID, LAUNCHER_B_TRIGGER_REVERSE_SOLENOID);

    m_shooterMotor = new Talon(SHOOTER_MOTOR);

    m_motorPot = new AnalogChannel(SHOOTER_MOTOR_POT);

    m_shooterLoadLimit = 1024;

    m_shooterLoading = false;

    timer = new Timer();

}

void ShooterB::EnableTeleopControls ()
{
    if (m_controls->GetShooterButton(SHOOTER_BUTTON) && IsSolenoidReset()) { // Cannot fire until solenoid is reset
        Shoot();
    } else if (( m_controls->GetShooterButton(SHOOTER_RESET_BUTTON) || m_shooterLoading ) && IsSolenoidReset() ) {
        LoadShooter();
    }

    if (!IsSolenoidReset() && timer->HasPeriodPassed(0.5)) { // Automatically reengage SuperShifter. Timer is just there so it isn't reset mid-shot.
        Reset();
        timer->Stop();
        timer->Reset();
    }
}

void ShooterB::Shoot()
{
    m_Trigger->Set(DoubleSolenoid::kReverse);
    //Reset motor pot?

    timer->Reset();
    timer->Start();
}

void ShooterB::Reset()
{
    m_Trigger->Set(DoubleSolenoid::kForward);
}

void ShooterB::LoadShooter()
{
    int motorValue = m_motorPot->GetValue();
    if (motorValue < m_shooterLoadLimit) {
        m_shooterMotor->Set(0.5);
        m_shooterLoading = true;
    } else {
        m_shooterMotor->Set(0.0);
        m_shooterLoading = false;
    }
}

bool ShooterB::IsShooterResetting()
{
    return m_shooterLoading;
}

bool ShooterB::IsSolenoidReset()
{
	bool isReset = false;
	if (m_Trigger->Get() == DoubleSolenoid::kReverse) {
		isReset = false;
	} else {
		isReset = true;
	}
    return isReset;
}
