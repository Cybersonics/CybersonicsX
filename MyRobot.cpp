#include "WPILib.h"
#include "systems/Drivetrain.h"
#include "systems/Pickup.h"
#include "systems/Shooter.h"
#include "utils/Controls.h"
#include "utils/Constants.h"
 
class CybersonicX : public SimpleRobot
{	
	Drivetrain* drivetrain;
	Controls* controls;
	
	Relay* compressor;
	DigitalInput* pressureSwitch;

public:
	CybersonicX(void){
		drivetrain = Drivetrain::GetInstance();
		controls = Controls::GetInstance();
		
		compressor = new Relay(COMPRESSOR_RELAY_CHAN, Relay::kForwardOnly);
		pressureSwitch = new DigitalInput(PRESSURE_SWITCH_CHAN);
		
		GetWatchdog().Kill();
	}

	void Autonomous()
	{
		compressor->Set(Relay::kOn);
		while(IsAutonomous() && IsEnabled()){

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

