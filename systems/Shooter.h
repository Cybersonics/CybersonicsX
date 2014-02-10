#ifndef SHOOTER_H
#define SHOOTER_H

#include "WPILib.h"
#include "../utils/Controls.h"

class Shooter {
	
private:
    static Shooter* m_instance;

    DoubleSolenoid* m_Launcher;
    DoubleSolenoid* m_Trigger;

    Controls* m_controls;

    Timer* m_timer;

   enum ResetSequence {
    	Waiting,
        Firing,
        Resetting,
        Locking
    } ShooterReset;

    

public:
    static Shooter* GetInstance();

    Shooter();

    void Reset();
    
    void Shoot();
    void PullBackLauncher();
    void Lock();
    void Set();
    void CheckReset();

    void EnableTeleopControls();
	
};

#endif
