#include "StateMachine/States/FullPowerState.h"
#include "ChainSword.h"

void FullPowerState::execute(ChainSword *context, unsigned long millis)
{
    context->lightController()->execute(millis);
}

void FullPowerState::enter(ChainSword *context, unsigned long millis)
{
    Serial.println("-- ChainSword at full power! --");
    context->lightController()->SetEffect(OVERHEAT_ANIMATION, millis);
}

void FullPowerState::exit(ChainSword *context, unsigned long millis)
{
        Serial.println("-- End of full power --");
    context->lightController()->StopEffect(OVERHEAT_ANIMATION, millis);
}