#include "WPILib.h"
#include "AutoController.h"
#include "Constants.h"
#include "HelperFunctions.h"

AutoController* AutoController::m_instance = NULL;

AutoController* AutoController::GetInstance() {
  if (m_instance == NULL) {
    m_instance = new AutoController();
  }
  return m_instance;
}

AutoController::AutoController() {
	drivetrain = Drivetrain::GetInstance();
	shooter = Shooter::GetInstance();
	pickup = Pickup::GetInstance();
	
	m_timer = new Timer();
	m_step = 0;
}

void AutoController::Reset() {
	m_step = 0;
}

void AutoController::Test() {
	drivetrain->SetSpeed(0.0);
}

void AutoController::DoNothing() {
	drivetrain->SetSpeed(0.0);
}
