#include "WPILib.h"
#include "Math.h"
#include "Drivetrain.h"
#include "../utils/Constants.h"
#include "../utils/HelperFunctions.h"


Drivetrain* Drivetrain::m_instance = NULL;

Drivetrain* Drivetrain::GetInstance() {
  if (m_instance == NULL) {
    m_instance = new Drivetrain();
  }
  return m_instance;
}

Drivetrain::Drivetrain() {
	m_controls = Controls::GetInstance();
	
	m_leftDriveA = new Talon(LEFT_DRIVE_A_PWM);
	m_leftDriveB = new Talon(LEFT_DRIVE_B_PWM);
	m_rightDriveA = new Talon(RIGHT_DRIVE_A_PWM);
	m_rightDriveA = new Talon(RIGHT_DRIVE_B_PWM);

	// Encoders
	m_leftEncoder = new Encoder(LEFT_ENCODER_A, LEFT_ENCODER_B);
	m_rightEncoder = new Encoder(RIGHT_ENCODER_A, RIGHT_ENCODER_B, true);
	
	m_leftEncoder->SetDistancePerPulse(INCHES_PER_COUNT);
	m_rightEncoder->SetDistancePerPulse(INCHES_PER_COUNT);
	
	m_leftEncoderControllerA = new PIDController(0.0, 0.0, 0.0, m_leftEncoder, m_leftDriveA);
	m_leftEncoderControllerB = new PIDController(0.0, 0.0, 0.0, m_leftEncoder, m_leftDriveB);
	m_rightEncoderControllerA = new PIDController(0.0, 0.0, 0.0, m_rightEncoder, m_rightDriveA);
	m_rightEncoderControllerB = new PIDController(0.0, 0.0, 0.0, m_rightEncoder, m_rightDriveB);
	
	m_leftEncoderControllerA->SetPID(LEFT_ENCODER_P, LEFT_ENCODER_I, LEFT_ENCODER_D);
	m_leftEncoderControllerB->SetPID(LEFT_ENCODER_P, LEFT_ENCODER_I, LEFT_ENCODER_D);
	m_rightEncoderControllerA->SetPID(RIGHT_ENCODER_P, RIGHT_ENCODER_I, RIGHT_ENCODER_D);
	m_rightEncoderControllerB->SetPID(RIGHT_ENCODER_P, RIGHT_ENCODER_I, RIGHT_ENCODER_D);
	
	//Pneumatics
	m_Shifter = new DoubleSolenoid(SHIFTER_FORWARD_CHAN, SHIFTER_REVERSE_CHAN);
	m_Brakes = new DoubleSolenoid(BRAKES_FORWARD_CHAN, SHIFTER_REVERSE_CHAN);
	
	m_timer = new Timer();
	m_timerStopped = false;
}

void Drivetrain::EnableTeleopControls() {
	m_leftDriveA->Set(m_controls->GetLeftY());
	m_leftDriveB->Set(m_controls->GetLeftY());
	m_rightDriveA->Set(m_controls->GetRightY());
	m_rightDriveB->Set(m_controls->GetRightY());
}

void Drivetrain::SetSpeed(float speed) {
	m_leftDriveA->Set(speed);
	m_leftDriveB->Set(speed);
	m_rightDriveA->Set(speed);
	m_rightDriveB->Set(speed);
}

void Drivetrain::SetLeftSpeed(float speed) {
	m_leftDriveA->Set(speed);
	m_leftDriveB->Set(speed);
}

void Drivetrain::SetRightSpeed(float speed) {
	m_rightDriveA->Set(speed);
	m_rightDriveB->Set(speed);
}

float Drivetrain::GetLeftSpeed() {
	return ((m_leftDriveA->Get())+(m_leftDriveB->Get()))/2;
}

float Drivetrain::GetRightSpeed() {
	return ((m_rightDriveA->Get())+(m_rightDriveB->Get()))/2;
}

void Drivetrain::ShiftHigh() {
	m_Shifter->Set(DoubleSolenoid::kForward);
}

void Drivetrain::ShiftLow() {
	m_Shifter->Set(DoubleSolenoid::kReverse);
}

void Drivetrain::BrakesOn() {
	m_Brakes->Set(DoubleSolenoid::kForward);
}

void Drivetrain::BrakesOff() {
	m_Brakes->Set(DoubleSolenoid::kReverse);

}

bool Drivetrain::brakesLocked() {
	if(m_Brakes->Get()== DoubleSolenoid::kForward){
		return true;
	}
	return false;
}

int Drivetrain::GetLeftEncoderCount() {
	m_leftEncoder->Start();
	return m_leftEncoder->Get();
}

int Drivetrain::GetRightEncoderCount() {
	m_rightEncoder->Start();
	return m_rightEncoder->Get();
}

void Drivetrain::ResetEncoders() {
	m_leftEncoder->Reset();
	m_rightEncoder->Reset();
}

void Drivetrain::SetEncoderSetpoint(float inches) {
	m_leftEncoderControllerA->SetSetpoint(inches);
	m_leftEncoderControllerB->SetSetpoint(inches);
	m_rightEncoderControllerA->SetSetpoint(inches);
	m_rightEncoderControllerB->SetSetpoint(inches);
}

void Drivetrain::EnableEncoderPid() {
	m_leftEncoderControllerA->Enable();
	m_leftEncoderControllerB->Enable();
	m_rightEncoderControllerA->Enable();
	m_rightEncoderControllerB->Enable();
}

void Drivetrain::DisableEncoderPid() {
	m_leftEncoderControllerA->Disable();
	m_leftEncoderControllerB->Disable();
	m_rightEncoderControllerA->Disable();
	m_rightEncoderControllerB->Disable();
}

bool Drivetrain::EncoderPidIsEnabled() {
	return  m_leftEncoderControllerA->IsEnabled() &&
			m_leftEncoderControllerB->IsEnabled() &&
			m_rightEncoderControllerA->IsEnabled() &&
			m_rightEncoderControllerB->IsEnabled();
}

// TODO: REMOVE
void Drivetrain::SetEncoderPID(float p, float i, float d) {
	m_leftEncoderControllerA->SetPID(p,i,d);
	m_leftEncoderControllerB->SetPID(p,i,d);
	m_rightEncoderControllerA->SetPID(p,i,d);
	m_rightEncoderControllerB->SetPID(p,i,d);
}

void Drivetrain::SetLeftEncoderPID(float p, float i, float d) {
	m_leftEncoderControllerA->SetPID(p, i, d);
	m_leftEncoderControllerB->SetPID(p, i, d);
}

void Drivetrain::SetRightEncoderPID(float p, float i, float d) {
	m_rightEncoderControllerA->SetPID(p, i, d);
	m_rightEncoderControllerB->SetPID(p, i, d);
}
