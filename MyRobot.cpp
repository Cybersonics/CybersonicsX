#include "WPILib.h"
#include "systems/Drivetrain.h"
#include "systems/Pickup.h"
#include "systems/Shooter.h"
#include "utils/AutoController.h"
#include "utils/Controls.h"
#include "utils/Constants.h"
 
class CybersonicX : public SimpleRobot
{
	AutoController* autoController;
	
	Drivetrain* drivetrain;
	Controls* controls;
	
	Relay* compressor;
	DigitalInput* pressureSwitch;

	SendableChooser *autoSelector;
public:
	CybersonicX(void){
		autoController = AutoController::GetInstance();
		drivetrain = Drivetrain::GetInstance();
		controls = Controls::GetInstance();
		
		compressor = new Relay(COMPRESSOR_RELAY_CHAN, Relay::kForwardOnly);
		pressureSwitch = new DigitalInput(PRESSURE_SWITCH_CHAN);
		
		autoSelector = new SendableChooser();
		autoSelector->AddDefault("0. DEFAULT - Do Nothing", (void*)0);
		autoSelector->AddObject("1. Test - Test Auton", (void*)1);
		
		SmartDashboard::init();
		SmartDashboard::PutData("Autonomous Mode", autoSelector);
	}

	void Autonomous()
	{
		compressor->Set(Relay::kOn);
		int selectedAutoMode = (int)(autoSelector->GetSelected());
		while(IsAutonomous() && IsEnabled()){
			switch(selectedAutoMode){
				case 0: autoController->DoNothing(); break;
				case 1: autoController->Test(); break;
			}
		}

	}

	void OperatorControl()
	{
		while (IsOperatorControl() && IsEnabled())
		{
			drivetrain->EnableTeleopControls();
			
			if(pressureSwitch->Get() == 1){
				compressor->Set(Relay::kOff);
			} else {
				compressor->Set(Relay::kOn);
			}
			
		}
	}
	
	void Test() {

	}
};

START_ROBOT_CLASS(CybersonicX);

