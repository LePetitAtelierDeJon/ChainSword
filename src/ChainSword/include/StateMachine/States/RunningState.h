#ifndef RUNNINGSTATE_H_
#define RUNNINGSTATE_H_

#include <Arduino.h>
#include "StateMachine/BaseState.h"
#include "ChainSword.h"
#include "Light/Color.h"
#include "StateMachine/States/TransitionIndex.h"

class RunningState : public BaseState<ChainSword>
{
public:
    void execute(ChainSword *context, unsigned long millis)
    {
        context->lightController()->execute(millis);
        if (context->lightController()->isEffectStopped(RUNNING_ANIMATION))
        {
            if (!transitionOver)
            {
                previousMillis = millis;
                transitionOver = true;
            }
            else if (millis - previousMillis > 2000)
            {
                switchState(OVERHEAT_TRANSITION, millis);
            }
        }
    }

    void enter(ChainSword *context, unsigned long millis)
    {
        //Serial.println("Enter Running");

        context->lightController()->SetEffect(RUNNING_ANIMATION, millis);
        transitionOver = false;
    }

    void exit(ChainSword *context, unsigned long millis)
    {
       // Serial.println("exit running state");
        context->stopMotor();
    }

private:
    unsigned long previousMillis = 0;
    bool transitionOver = false;
};
#endif // !RUNNINGSTATE_H_