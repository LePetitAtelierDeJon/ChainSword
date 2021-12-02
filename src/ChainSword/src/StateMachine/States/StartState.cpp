#include "StateMachine/States/StartState.h"
#include "ChainSword.h"

void StartState::execute(ChainSword *context, unsigned long millis)
{
    context->lightController()->execute(millis);
    if (context->lightController()->isEffectStopped(STARTUP_ANIMATION))
    {
        stateMachine_->makeTransition(IDLE_TRANSITION, millis);
    }
}

void StartState::enter(ChainSword *context, unsigned long millis)
{
    Serial.println("-- Starting... --");
    context->lightController()->SetEffect(STARTUP_ANIMATION, millis);
}

void StartState::exit(ChainSword *context, unsigned long millis)
{
    Serial.println("-- Setup Done --");
}