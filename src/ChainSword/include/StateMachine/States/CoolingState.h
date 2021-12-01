#ifndef COOLINGSTATE_H_
#define COOLINGSTATE_H_

#include <Arduino.h>
#include "StateMachine/BaseState.h"
#include "StateMachine/States/TransitionIndex.h"
#include "ChainSword.h"

class CoolingState : public BaseState<ChainSword>
{
public:
    void execute(ChainSword *context, unsigned long millis)
    {
        context->lightController()->execute(millis);
        if(millis - startMillis >= 3000)
        {
            switchState(COOLED_TRANSITION, millis);
        }
    }

    void enter(ChainSword *context, unsigned long millis)
    {
        Serial.println("-- Start Cooling Machine --");       
        context->lightController()->SetEffect(COOLING_ANIMATION, millis);  
        startMillis = millis;
    }

    void exit(ChainSword *context, unsigned long millis)
    {
        Serial.println("-- End Cooling Machine --");
        context->lightController()->StopEffect(COOLING_ANIMATION, millis);
        
    }

private:
    unsigned long startMillis;
};
#endif // !COOLINGSTATE_H_