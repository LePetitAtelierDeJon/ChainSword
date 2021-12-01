#ifndef CHAINSWORD_H_
#define CHAINSWORD_H_

#include "Light/LightController.h"
#include "StateMachine/StateMachine.h"

#include "Light/LightController.h"
#include "Light/LightEffects/BlinkEffect.h"
#include "Light/LightEffects/ColorWipeEffect.h"
#include "Light/LightEffects/ScannerEffect.h"
#include "Light/LightEffects/CrawlEffect.h"
#include "Light/LightEffects/FadeEffect.h"

#define STARTUP_ANIMATION 0
#define IDLE_ANIMATION 1
#define RUNNING_ANIMATION 2
#define OVERHEAT_ANIMATION 3
#define COOLING_ANIMATION 4

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
    inline LightController *lightController() const {         
        return lightController_; 
        }

    inline void startMotor()
    {
        digitalWrite(motorPin_, HIGH);
    }

    inline void stopMotor()
    {
        digitalWrite(motorPin_, LOW);
    }

    inline void setMotorPin(uint8_t motorPin)
    {
        motorPin_ = motorPin;
    }

    inline void setStateMachine(StateMachine<ChainSword> *stateMachine)
    {
        stateMachine_ = stateMachine;
        stateMachine_->setOwner(this);
    }

    void init()
    {
        Serial.println("+++ Setup Light Effects +++");
        // Start animation
        wipe_.setup(1, 30, false);        
        wipe_.setTargetColor(baseBlue);
        lightController_->AddLightEffect(STARTUP_ANIMATION, &wipe_);

        // Blade heating animation
        fade_.setup(20, 100, false);
        fade_.setTargetColor(red);
        fade_.setEffectColor(baseBlue);
        lightController_->AddLightEffect(RUNNING_ANIMATION, &fade_);

        // Overheat animation
        crawl_.setup(-1, 8);
        crawl_.setEffectSize(10);
        crawl_.setTargetColor(red);
        crawl_.setEffectColor(overheatBaseColor);
        lightController_->AddLightEffect(OVERHEAT_ANIMATION, &crawl_);

        // Cooling animation
        blink_.setup(-1, 150, false);
        blink_.setTargetColor(red);
        blink_.setEffectColor(baseBlue);
        lightController_->AddLightEffect(COOLING_ANIMATION, &blink_);

        // Idle animation
        scanner_.setup(1, 50, false);
        scanner_.setEffectSize(3);
        scanner_.setEffectColor(baseBlue);
        scanner_.setTargetColor(accentuatedBlue);  
        lightController_->AddLightEffect(IDLE_ANIMATION, &scanner_);
    }

private:
    bool isTriggerOn_;
    LightController *lightController_;
    StateMachine<ChainSword> *stateMachine_;
    unsigned short heatLength_;
    unsigned short currentHeatLength_;
    uint8_t motorPin_;

    BlinkEffect blink_;
    ColorWipeEffect wipe_;
    ScannerEffect scanner_;
    CrawlEffect crawl_;
    FadeEffect fade_;

    Color baseBlue = Color(0, 10, 20);
    Color accentuatedBlue = Color(0, 20, 40);
    Color red = Color(20, 0, 0);
    Color overheatBaseColor = Color(10, 10, 0);
};

#endif // !CHAINSWORD_H_