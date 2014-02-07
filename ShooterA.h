#ifndef ShooterA_H
#define ShooterA_H

#include "WPILib.h"
#include "utils/Controls.h"

class ShooterA {
	
private:
    static ShooterA* m_instance;

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
    static ShooterA* GetInstance();

    ShooterA();

    void Reset();
    
    void Shoot();
    void PullBackLauncher();
    void Lock();
    void Set();
    void CheckReset();

    void EnableTeleopControls();
	
};

#endif
