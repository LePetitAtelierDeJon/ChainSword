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

void FadeEffect::stop()
{
    LightEffect::stop();
    if (turnOffAtStop_)
    {
        light_->off();
    }
    else
    {
        light_->on();
    }    
}