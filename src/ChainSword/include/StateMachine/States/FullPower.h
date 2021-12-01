#ifndef FULLPOWERSTATE_H_
#define FULLPOWERSTATE_H_

#include <Arduino.h>
#include "StateMachine/BaseState.h"
#include "ChainSword.h"

class FullPowerState : public BaseState<ChainSword>
{
public:
    void execute(ChainSword *context, unsigned long millis)
    {    
        context->lightController()->execute(millis);
    }

    void enter(ChainSword *context, unsigned long millis)
    {    
        Serial.println("Overheat State");
        context->lightController()->GetLight().changeTargetColor(Color(20, 0, 0));
        context->lightController()->GetLight().changeColor(Color(10, 10, 0));
        context->lightController()->SetEffect("Crawl", millis);    
    }

    void exit(ChainSword *context, unsigned long millis)
    {
    }
};
#endif // !FULLPOWERSTATE_H_