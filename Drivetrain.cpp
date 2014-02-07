#include "WPILib.h"
#include "utils/HelperFunctions.h"
#include "Drivetrain.h"
#include "utils/Constants.h"
#include "Math.h"

Drivetrain* Drivetrain::m_instance = NULL;

Drivetrain* Drivetrain::GetInstance() {
  if (m_instance == NULL) {
    m_instance = new Drivetrain();
  }
  return m_instance;
}

Drivetrain::Drivetrain() {
	m_controls = Controls::GetInstance();
	
	// Remember to change these to Talons
	m_leftDrive = new Talon(LEFT_DRIVE_PWM);
	m_rightDrive = new Talon(RIGHT_DRIVE_PWM);

	// Encoders
	m_leftEncoder = new Encoder(LEFT_ENCODER_A, LEFT_ENCODER_B);
	m_rightEncoder = new Encoder(RIGHT_ENCODER_A, RIGHT_ENCODER_B, true);
	
	m_leftEncoder->SetDistancePerPulse(INCHES_PER_COUNT);
	m_rightEncoder->SetDistancePerPulse(INCHES_PER_COUNT);
	
	m_leftEncoderController = new PIDController(0.0, 0.0, 0.0, m_leftEncoder, m_leftDrive);
	m_rightEncoderController = new PIDController(0.0, 0.0, 0.0, m_rightEncoder, m_rightDrive);
	
	m_leftEncoderController->SetPID(LEFT_ENCODER_P, LEFT_ENCODER_I, LEFT_ENCODER_D);
	m_rightEncoderController->SetPID(RIGHT_ENCODER_P, RIGHT_ENCODER_I, RIGHT_ENCODER_D);
	
	//Pneumatics
	m_Shifter = new DoubleSolenoid(SHIFTER_FORWARD_CHAN, SHIFTER_REVERSE_CHAN);
	m_Brakes = new DoubleSolenoid(BRAKES_FORWARD_CHAN, SHIFTER_REVERSE_CHAN);
	
	// Gyro
	m_gyro = new Gyro(GYRO_CHANNEL);
	m_gyro->SetSensitivity(GYRO_SENSITIVITY);

	// Ultrasonic
	m_ultrasonic = new AnalogChannel(ULTRASONIC_CHANNEL);
		
	m_gyroController = new PIDController(0.0, 0.0, 0.0, m_gyro, m_leftDrive);
	m_gyroController->SetPID(GYRO_P, GYRO_I, GYRO_D);
	
	m_isTurning = false;
	m_isDrivingStraight = false;
	
	m_timer = new Timer();
	m_timerStopped = false;
}

void Drivetrain::EnableTeleopControls() {
	m_leftDrive->Set(m_controls->GetLeftY());
	m_rightDrive->Set(m_controls->GetRightY());
	if(m_controls->GetLeftTrigger()){
		ShiftHigh();
	}
	if(m_controls->GetRightTrigger()){
		ShiftLow();
	}
	if(m_controls->GetLeftButton()){
		BrakesOn();
	}
	if(m_controls->GetRightButton()){
		BrakesOff();
	}
	
}

void Drivetrain::SetSpeed(float speed) {
	m_leftDrive->Set(speed);
	m_rightDrive->Set(speed);
}

void Drivetrain::SetLeftSpeed(float speed) {
	m_leftDrive->Set(speed);
}

void Drivetrain::SetRightSpeed(float speed) {
	m_rightDrive->Set(speed);
}

float Drivetrain::GetLeftSpeed() {
	return m_leftDrive->Get();
}

float Drivetrain::GetRightSpeed() {
	return m_rightDrive->Get();
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
	m_leftEncoderController->SetSetpoint(inches);
	m_rightEncoderController->SetSetpoint(inches);
}

void Drivetrain::EnableEncoderPid() {
	m_leftEncoderController->Enable();
	m_rightEncoderController->Enable();
}

void Drivetrain::DisableEncoderPid() {
	m_leftEncoderController->Disable();
	m_rightEncoderController->Disable();
}

bool Drivetrain::EncoderPidIsEnabled() {
	return m_leftEncoderController->IsEnabled() && m_rightEncoderController->IsEnabled();
}

void Drivetrain::ResetGyro() {
	m_gyro->Reset();
}

float Drivetrain::GetGyroAngle() {
	return m_gyro->GetAngle();
}

float Drivetrain::GetUltrasonicDistance() {
	return m_ultrasonic->GetValue();
}



/**
 * Turn using dead reckoning and the gyro to know when to stop.
 */
bool Drivetrain::Turn(float setpoint, float tolerance, float maxSpeed) {
	if (!m_isTurning) {
		if (setpoint > 0 ) {
			m_leftDrive->Set(maxSpeed);
			m_rightDrive->Set(-1.0 * maxSpeed);
		} else if (setpoint < 0) {
			m_leftDrive->Set(-1.0 * maxSpeed);
			m_rightDrive->Set(maxSpeed);
		} 
		m_isTurning = true;
	}
	
	if (m_isTurning) {
		if ((setpoint > 0 && m_gyro->GetAngle() > setpoint) || (setpoint < 0 && m_gyro->GetAngle() < setpoint)) {
			SetSpeed(0.0);
			m_isTurning = false;
			return true;
		}
	}
	return false;
}

bool Drivetrain::IsTurning() {
	return m_isTurning;
}

void Drivetrain::EnableGyroPid() {
	m_gyroController->Enable();
}

void Drivetrain::DisableGyroPid() {
	m_gyroController->Disable();
}

void Drivetrain::SetGyroSetpoint(float angle) {
	m_gyroController->SetSetpoint(angle);
}

// TODO: REMOVE
PIDController* Drivetrain::GetGyroController() {
	return m_gyroController;
}

// TODO: REMOVE
void Drivetrain::SetEncoderPID(float p, float i, float d) {
	m_leftEncoderController->SetPID(p,i,d);
	m_rightEncoderController->SetPID(p,i,d);
}

void Drivetrain::SetLeftEncoderPID(float p, float i, float d) {
	m_leftEncoderController->SetPID(p, i, d);
}

void Drivetrain::SetRightEncoderPID(float p, float i, float d) {
	m_rightEncoderController->SetPID(p, i, d);
}

/**
 * Important: Reset the gyro before calling this function.
 * @param {float} setpoint - The setpoint for the encoders in inches.
 * @param {float} tolerance - The tolerance for the encoders in inches.
 */
bool Drivetrain::DriveStraight(float setpoint, float tolerance, float p, float maxSpeed) {
	if (!m_isDrivingStraight) {
		m_leftEncoderController->SetOutputRange(-1.0, maxSpeed);
		m_rightEncoderController->SetOutputRange(-1.0, maxSpeed);
		SetEncoderSetpoint(setpoint);
		EnableEncoderPid();
		m_rightDrive->Set(m_leftEncoderController->Get());
		
		// TODO: Get rid of reset Gyro?
		m_gyro->Reset();
		m_isDrivingStraight = true;
	}
	
	if (m_isDrivingStraight) {
		float angleError = m_gyro->GetAngle();
		
		float leftSpeed = m_leftDrive->Get() + (angleError * p);
		float rightSpeed = m_rightDrive->Get() - (angleError * p);
				
		if (leftSpeed > 1.0) {
			leftSpeed = 1.0;
		} else if (leftSpeed < -1.0) {
			leftSpeed = -1.0;
		}
		
		if (rightSpeed > 1.0) {
			rightSpeed = 1.0;
		} else if (rightSpeed < -1.0) {
			rightSpeed = -1.0;
		}
		
		m_leftDrive->Set(leftSpeed);
		m_rightDrive->Set(rightSpeed);
		
		if (setpoint > 0) {
			if ((encoderCountToInches(m_leftEncoder->Get()) >= setpoint) || (encoderCountToInches(m_rightEncoder->Get()) >= setpoint)) {
				DisableEncoderPid();
				m_isDrivingStraight = false;
				return true;
			}
		} else {
			if ((encoderCountToInches(m_leftEncoder->Get()) <= setpoint) || (encoderCountToInches(m_rightEncoder->Get()) <= setpoint)) {
				DisableEncoderPid();
				m_isDrivingStraight = false;
				return true;
			}
		}
	}
	return false;
}

bool Drivetrain::DriveForward(float setpoint, float tolerance) {
	if (!m_isDrivingStraight) {
		SetEncoderSetpoint(setpoint);
		EnableEncoderPid();
		m_isDrivingStraight = true;
	}
	
	if (m_isDrivingStraight) {
		
		// Determine when to disable PID
		bool leftOnTarget = fabs(setpoint - encoderCountToInches(m_leftEncoder->Get())) < tolerance;
		bool rightOnTarget = fabs(setpoint - encoderCountToInches(m_rightEncoder->Get())) < tolerance;
		
		
		if (leftOnTarget && rightOnTarget) {
			DisableEncoderPid();
			m_isDrivingStraight = false;
			return true;
		}
	}
	return false;
}
