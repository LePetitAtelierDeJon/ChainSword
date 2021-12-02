#include "StateMachine/States/RunningState.h"
#include "ChainSword.h"

void RunningState::execute(ChainSword *context, unsigned long millis)
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
            stateMachine_->makeTransition(OVERHEAT_TRANSITION, millis);
        }
    }
}

void RunningState::enter(ChainSword *context, unsigned long millis)
{
    Serial.println("-- Start of nominal chainsword operation --");

    context->lightController()->SetEffect(RUNNING_ANIMATION, millis);
    transitionOver = false;
    context->startMotor();
}

void RunningState::exit(ChainSword *context, unsigned long millis)
{
    Serial.println("-- End of nominal chainsword operation --");
    context->stopMotor();
}