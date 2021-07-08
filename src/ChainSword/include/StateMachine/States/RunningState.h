#ifndef RUNNINGSTATE_H_
#define RUNNINGSTATE_H_

#include <Arduino.h>
#include "StateMachine/BaseState.h"
#include "ChainSword.h"
#include "Light/Color.h"

class RunningState : public BaseState<ChainSword>
{
public:
    void execute(ChainSword *context, unsigned long millis)
    {
        // currentColor += colorAdd;
        // context->light()->GetLight().changeColor(currentColor);
        context->light()->execute(millis);
    }

    void enter(ChainSword *context, unsigned long millis)
    {
        context->light()->GetLight().changeTargetColor(baseColor);
        context->light()->GetLight().changeColor(Color(0, 10, 20));
        context->light()->SetEffect("Crawl", millis);
    }

    void exit(ChainSword *context, unsigned long millis)
    {
    }

private:
    Color baseColor = Color(30, 10, 0);
    Color currentColor = Color(30, 10, 0);
    Color colorAdd = Color(22, -1, 0);
};
#endif // !RUNNINGSTATE_H_