#ifndef CONTROLS_H
#define CONTROLS_H

#include "WPILib.h"

class Controls {

private:
	static Controls* m_instance;
	Joystick* m_leftStick;
	Joystick* m_rightStick;

	Joystick* m_OperatorStick;
	
public:
	static Controls* GetInstance();
	Controls();
	
	float GetLeftY();
	float GetRightY();
	bool GetLeftTrigger();
	bool GetRightTrigger();
	bool GetLeftButton(int button);
	bool GetRightButton(int button);
	
	float GetOperatorY();
	bool GetOperatorButton(int button);
	bool GetOperatorTrigger();
	float GetOperatorThrottle();
};
#endif
