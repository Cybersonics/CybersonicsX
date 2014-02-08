#include "WPILib.h"
#include "systems/Drivetrain.h"
#include "systems/PickupA.h"
#include "systems/ShooterA.h"
#include "systems/ShooterB.h"
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

public:
	CybersonicX(void){
		drivetrain = Drivetrain::GetInstance();
		controls = Controls::GetInstance();
		if(ROBOT == "A"){
			//Robot A specific things
			
			//ShooterA* shooter = ShooterA::GetInstance();
			//PickupA* pickup = PickupA::GetInstance();
		}
		
		if(ROBOT == "B"){
			//Robot B specific things
			
			//ShooterB* shooter = ShooterB::GetInstance();
		}
			
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous()
	{
		
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl()
	{
		while (IsOperatorControl() && IsEnabled())
		{
			drivetrain->EnableTeleopControls();
			
		}
	}
	
	/**
	 * Runs during test mode
	 */
	void Test() {

	}
};

START_ROBOT_CLASS(CybersonicX);

