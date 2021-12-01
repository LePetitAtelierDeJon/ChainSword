#include "Light/LightEffects/ColorWipeEffect.h"

void ColorWipeEffect::start(unsigned long startMillis)
{
    light_->on();
    previousEffectMillis_ = startMillis;
    currentEffectCounter_ = effectCounter_;
}

void ColorWipeEffect::executeEffect(unsigned long millis)
{
    if (currentIndex_ < light_->firstPixelIndex() + light_->pixelCount())
    {
        light_->setPixelTargetColor(currentIndex_);
    }
    else
    {
        decrementEffectCounter();
        currentIndex_ = 0;
        if (effectCounter_ > 0 || effectCounter_ <= -1)
        {
            light_->on();
        }
    }

    if (effectCounter_ > 0)
    {
        ++currentIndex_;
        previousEffectMillis_ = millis;
    }
}

void ColorWipeEffect::stop(bool turnOff)
{
    if (turnOff)
    {
        light_->off();
    }
    else
    {
        light_->turnTargetOn();
    }
    previousEffectMillis_ = 0;
    currentIndex_ = 0;
}

// bool ColorWipeEffect::isStopped() const
// {
//     return false;
// }