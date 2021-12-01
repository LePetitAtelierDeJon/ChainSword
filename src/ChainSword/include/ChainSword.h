#ifndef CHAINSWORD_H_
#define CHAINSWORD_H_

#include "Light/LightController.h"

class ChainSword
{
public:
    inline bool isTriggerOn() { return isTriggerOn_; }
    inline void toggleTrigger()
    {
        isTriggerOn_ = !isTriggerOn_;
    }

    inline void setTriggerOn() { isTriggerOn_ = true; }
    inline void setTriggerOff() { isTriggerOn_ = false; }

    inline void setLightController(LightController *lightController) { lightController_ = lightController; }
    inline LightController *lightController() const { return lightController_; }
    
    void startMotor()
    {
        digitalWrite(motorPin_, HIGH);
    }

    void stopMotor()
    {
        digitalWrite(motorPin_, LOW);
    }

    void setMotorPin(uint8_t motorPin)
    {
        motorPin_ = motorPin;
    }

private:
    bool isTriggerOn_;
    LightController *lightController_;
    unsigned short heatLength_;
    unsigned short currentHeatLength_;
    uint8_t motorPin_;
};

#endif // !CHAINSWORD_H_