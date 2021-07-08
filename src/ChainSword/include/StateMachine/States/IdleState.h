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
        context->light()->execute(millis);
    }

    void enter(ChainSword *context, unsigned long millis)
    {        
        context->light()->GetLight().changeTargetColor(Color(0, 10, 20));
        //context->light()->GetLight().changeColor(Color(0, 20, 20));
        //context->light()->SetEffect("Blink", millis);
    }

    void exit(ChainSword *context, unsigned long millis)
    {
    }
};
#endif // !IDLESTATE_H_