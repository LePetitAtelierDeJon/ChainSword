#include "Light/LightEffects/BlinkEffect.h"

void BlinkEffect::start(unsigned long startMillis)
{
    LightEffect::start(startMillis);
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
    LightEffect::stop(turnOff);
    if (turnOff)
    {
        light_->off();
    } else
    {
        light_->changeColor(effectColor_);
    }
}