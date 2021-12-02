#ifndef CHAINSWORD_H_
#define CHAINSWORD_H_

#include "StateMachine/StateMachine.h"

#include "Light/LightController.h"
#include "Light/LightEffects/BlinkEffect.h"
#include "Light/LightEffects/ColorWipeEffect.h"
#include "Light/LightEffects/ScannerEffect.h"
#include "Light/LightEffects/CrawlEffect.h"
#include "Light/LightEffects/FadeEffect.h"

#include "StateMachine/States/TransitionIndex.h"

#define STARTUP_ANIMATION 0
#define IDLE_ANIMATION 1
#define RUNNING_ANIMATION 2
#define OVERHEAT_ANIMATION 3
#define COOLING_ANIMATION 4

// // Forward declaration of states
class CoolingState;
class FullPowerState;
class IdleState;
class RunningState;
class StartState;

/**
 * @brief Represent the chainsword itself. Handles the lights effect, the state machine and the motor activation.
 *
 */
class ChainSword
{
public:
    ChainSword();

public:
    /**
     * @brief Is the trigger pulled or not?
     *
     * @return true if the trigger is pulled.
     * @return false if the trigger is released.
     */
    inline bool isTriggerOn() { return isTriggerOn_; }

    /**
     * @brief toggle the state of the trigger.
     *
     */
    void toggleTrigger(unsigned long millis);

    /**
     * @brief Set the Light Controller object, it controls the light and the light effects.
     *
     * @param lightController pointer to the lightController.
     */
    inline void setLightController(LightController *lightController) { lightController_ = lightController; }

    /**
     * @brief Get the lightController object.
     *
     * @return LightController*
     */
    inline LightController *lightController() const
    {
        return lightController_;
    }

    /**
     * @brief Start the motor of the chainsword.
     *
     */
    inline void startMotor()
    {
        digitalWrite(motorPin_, HIGH);
    }

    /**
     * @brief Stop the motor of the chainsword.
     *
     */
    inline void stopMotor()
    {
        digitalWrite(motorPin_, LOW);
    }

    /**
     * @brief Set the motor pin.
     *
     * @param motorPin pin used by the motor.
     */
    inline void setMotorPin(uint8_t motorPin)
    {
        motorPin_ = motorPin;
    }

    void execute(unsigned long millis) const;

    void init();

private:
    bool isTriggerOn_;
    LightController *lightController_;

    /**
     * @brief The state machine used for handling the different state of the chainsword.
     *
     */
    StateMachine<ChainSword> *stateMachine_;
    unsigned short heatLength_;
    unsigned short currentHeatLength_;
    uint8_t motorPin_;

    BlinkEffect blink_;
    ColorWipeEffect wipe_;
    ScannerEffect scanner_;
    CrawlEffect crawl_;
    FadeEffect fade_;

    StartState *startState;
    IdleState *idleState;
    RunningState *runningState;
    FullPowerState *fullPowerState;
    CoolingState *coolingState;

    Color baseBlue = Color(0, 10, 20);
    Color accentuatedBlue = Color(0, 20, 40);
    Color red = Color(20, 0, 0);
    Color overheatBaseColor = Color(10, 10, 0);
    Color coolingColor = Color(0, 20, 10);
    Color coolingColor2 = Color(10, 20, 0);
};

#endif // !CHAINSWORD_H_