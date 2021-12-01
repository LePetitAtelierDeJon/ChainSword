#include "Light/LightEffects/FadeEffect.h"

void FadeEffect::start(unsigned long startMillis)
{
    currentEffectCounter_ = effectCounter_;
    previousEffectMillis_ = startMillis;
    isStopped_ = false;
    currentColor = effectColor_;    
    addColor = (targetColor_ - currentColor) / effectCounter_;
    light_->changeColor(currentColor);    
}

void FadeEffect::executeEffect(unsigned long millis)
{
    currentColor += addColor;
    light_->changeColor(currentColor);
    decrementEffectCounter();
}

void FadeEffect::stop(bool turnOff)
{
    if (turnOff)
    {
        light_->off();
    }
    else
    {
        light_->on();
    }

    previousEffectMillis_ = 0;
}