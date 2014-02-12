#ifndef AUTO_CONTROLLER_H
#define AUTO_CONTROLLER_H

#include "WPILib.h"
#include "../systems/Drivetrain.h"
#include "../systems/Pickup.h"
#include "../systems/Shooter.h"

class AutoController {
private:
	static AutoController* m_instance;
	
	Drivetrain* drivetrain;
	Shooter* shooter;
	Pickup* pickup;
	
	Timer* m_timer;
	int m_step;
	
public:
	static AutoController* GetInstance();
	AutoController();
	void Reset();
	
	void Test();
	
	void DoNothing();
};

#endif
