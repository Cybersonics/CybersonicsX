#include "WPILib.h"
#include "systems/Drivetrain.h"
#include "systems/Pickup.h"
#include "systems/Shooter.h"
#include "utils/Controls.h"
#include "utils/Constants.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
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
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous()
	{
		compressor->Set(Relay::kOn);

	}

	/**
	 * Runs the motors with arcade steering. 
	 */
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
	
	/**
	 * Runs during test mode
	 */
	void Test() {

	}
};

START_ROBOT_CLASS(CybersonicX);

