#include "Light/LightEffects/BlinkEffect.h"

void BlinkEffect::start(unsigned long startMillis)
{
    previousEffectMillis_ = startMillis;
    currentEffectCounter_ = effectCounter_;
    light_->changeColor(effectColor_);
}

void BlinkEffect::executeEffect(unsigned long millis)
{
    if (blinkState_)
    {
        light_->changeColor(targetColor_);
    }
    else
    {
        light_->changeColor(effectColor_);
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
        light_->changeColor(effectColor_);
    }

    previousEffectMillis_ = 0;
}

bool BlinkEffect::isStopped() const
{
    return false;
}
