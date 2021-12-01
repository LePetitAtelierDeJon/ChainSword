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
        if (context->lightController()->isEffectStopped("Fade") && !transitionOver)
        {
            previousMillis = millis;
            transitionOver = true;
            context->lightController()->GetLight().changeColor(Color(20, 0, 0));
        }
        if (context->lightController()->isEffectStopped("Fade") && transitionOver && (millis - previousMillis > 2000))
        {
            switchState(OVERHEAT_TRANSITION, millis);
        }
    }

    void enter(ChainSword *context, unsigned long millis)
    {
        Serial.println("Enter Running");

        context->lightController()->GetLight().changeTargetColor(Color(20, 0, 0));
        context->lightController()->GetLight().changeColor(Color(0, 10, 20));

        context->lightController()->SetEffect("Fade", millis);  
        transitionOver = false;      
        Serial.println("End Enter Running");
    }

    void exit(ChainSword *context, unsigned long millis)
    {
        Serial.println("exit running state");
        context->stopMotor();
    }

private:
    Color baseColor = Color(30, 0, 0);
    Color currentColor = Color(30, 0, 0);
    Color colorAdd = Color(25, 0, 0);

    unsigned long previousMillis = 0;
    bool transitionOver = false;
};
#endif // !RUNNINGSTATE_H_