#include "StateMachine/States/CoolingState.h"
#include "ChainSword.h"

void CoolingState::execute(ChainSword *context, unsigned long millis)
{
    context->lightController()->execute(millis);
    if (millis - startMillis >= 3000)
    {
        stateMachine_->makeTransition(COOLED_TRANSITION, millis);
    }
}

void CoolingState::enter(ChainSword *context, unsigned long millis)
{
    Serial.println("-- Start Chainsword Cooling --");
    context->stopMotor();
    context->lightController()->SetEffect(COOLING_ANIMATION, millis);
    startMillis = millis;
}

void CoolingState::exit(ChainSword *context, unsigned long millis)
{
    Serial.println("-- End Chainsword Cooling --");
    context->lightController()->StopEffect(COOLING_ANIMATION, millis);
}