#ifndef STARTSTATE_H_
#define STARTSTATE_H_

#include <Arduino.h>
#include "StateMachine/BaseState.h"
#include "ChainSword.h"

class StartState : public BaseState<ChainSword>
{
public:
    void execute(ChainSword *context, unsigned long millis)
    {
        context->light()->execute(millis);     
    }

    void enter(ChainSword *context, unsigned long millis)
    {        
        context->light()->GetLight().changeTargetColor(Color(0, 10, 20));
        context->light()->GetLight().changeColor(Color(0, 0, 0));
        context->light()->SetEffect("Wipe", millis);
    }

    void exit(ChainSword *context, unsigned long millis)
    {
    }
};
#endif // !STARTSTATE_H_