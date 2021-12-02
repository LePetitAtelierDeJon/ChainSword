#include "StateMachine/States/IdleState.h"
#include "ChainSword.h"

void IdleState::execute(ChainSword *context, unsigned long millis)
{
    context->lightController()->execute(millis);

    if (isStarting || millis - previousMillis > 10000)
    {
        context->lightController()->SetEffect(IDLE_ANIMATION, millis);
        previousMillis = millis;
        isStarting = false;
    }
}

void IdleState::enter(ChainSword *context, unsigned long millis)
{
    Serial.println("-- Chainsword ready to use --");
    previousMillis = millis;
    isStarting = true;
}

void IdleState::exit(ChainSword *context, unsigned long millis)
{
    Serial.println("-- Start to use Chainsword --");
    context->lightController()->StopEffect(IDLE_ANIMATION, millis);
}