#include "Light/LightEffects/FadeEffect.h"

void FadeEffect::start(unsigned long startMillis)
{
    LightEffect::start(startMillis);
    currentColor_ = effectColor_;
    addColor_ = (targetColor_ - currentColor_) / effectCounter_;
    light_->changeColor(currentColor_);
}

void FadeEffect::executeEffect(unsigned long millis)
{
    currentColor_ += addColor_;
    light_->changeColor(currentColor_);
    decrementEffectCounter();
}

void FadeEffect::stop(bool turnOff)
{
    LightEffect::stop(turnOff);
    if (turnOff)
    {
        light_->off();
    }
    else
    {
        light_->on();
    }    
}