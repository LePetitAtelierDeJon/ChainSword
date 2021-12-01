#ifndef IDLESTATE_H_
#define IDLESTATE_H_

#include <Arduino.h>
#include "StateMachine/BaseState.h"
#include "ChainSword.h"

class IdleState : public BaseState<ChainSword>
{
public:
    void execute(ChainSword *context, unsigned long millis)
    {    
        context->lightController()->execute(millis);
        if(millis - previousMillis > 10000)
        {
            context->lightController()->SetEffect("Scanner", millis);  
            previousMillis = millis;
        }
    }

    void enter(ChainSword *context, unsigned long millis)
    {        
        Serial.println("-- Chainsword ready to use --"); 
        context->lightController()->GetLight().changeTargetColor(Color(0, 10, 20));
        context->lightController()->GetLight().changeColor(Color(0, 20, 40));          
        previousMillis = millis; 
    }

    void exit(ChainSword *context, unsigned long millis)
    {
        Serial.println("Exit idle.");
        context->lightController()->StopEffect("Scanner", millis);
    }

private:
    unsigned long previousMillis = 0;
};
#endif // !IDLESTATE_H_