#include "Light/LightEffects/BlinkEffect.h"

void BlinkEffect::start(unsigned long startMillis)
{
    previousEffectMillis_ = startMillis;
}

void BlinkEffect::executeEffect(unsigned long millis)
{
    if (blinkState_)
    {
        light_->turnTargetOn();
    }
    else
    {
        light_->on();
        decrementEffectCounter();
    }
    blinkState_ = !blinkState_;
    previousEffectMillis_ = millis;
}

void BlinkEffect::stop(bool turnOff)
{
    if (turnOff)
    {
        light_->off();
    } else
    {
        light_->on();
    }

    previousEffectMillis_ = 0;
}

bool BlinkEffect::isStopped() const
{
    return false;
}
