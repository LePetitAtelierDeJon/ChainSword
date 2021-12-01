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
        if(context->lightController()->isEffectStopped("Wipe"))
        {
            switchState(IDLE_TRANSITION, millis);
        }
    }

    void enter(ChainSword *context, unsigned long millis)
    {        
        Serial.println("enter start");
        context->lightController()->GetLight().changeTargetColor(Color(0, 10, 20));
        context->lightController()->GetLight().changeColor(Color(0, 0, 0));
        context->lightController()->SetEffect("Wipe", millis);
    }

    void exit(ChainSword *context, unsigned long millis)
    {
        Serial.println("exit start");
    }
};
#endif // !STARTSTATE_H_