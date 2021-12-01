#ifndef STARTSTATE_H_
#define STARTSTATE_H_

#include <Arduino.h>
#include "StateMachine/BaseState.h"
#include "StateMachine/States/TransitionIndex.h"
#include "ChainSword.h"

class StartState : public BaseState<ChainSword>
{
public:
    void execute(ChainSword *context, unsigned long millis)
    {
        context->lightController()->execute(millis);
        if(context->lightController()->isEffectStopped(STARTUP_ANIMATION))
        {
            switchState(IDLE_TRANSITION, millis);
        }
    }

    void enter(ChainSword *context, unsigned long millis)
    {        
        Serial.println("-- Start Chainsword Initiaisation --");
        context->lightController()->SetEffect(STARTUP_ANIMATION, millis);
    }

    void exit(ChainSword *context, unsigned long millis)
    {
        Serial.println("-- Chainsword Initialization Over --");
    }
};
#endif // !STARTSTATE_H_