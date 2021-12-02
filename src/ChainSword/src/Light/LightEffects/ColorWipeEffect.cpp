#include "Light/LightEffects/ColorWipeEffect.h"

void ColorWipeEffect::start(unsigned long startMillis)
{
    LightEffect::start(startMillis);
    light_->changeColor(effectColor_);
}

void ColorWipeEffect::executeEffect(unsigned long millis)
{
    if (currentIndex_ < light_->firstPixelIndex() + light_->pixelCount())
    {
        light_->setPixelColor(currentIndex_, targetColor_);
    }
    else
    {
        decrementEffectCounter();
        currentIndex_ = 0;
        if (currentEffectCounter_ > 0 || effectCounter_ <= -1)
        {
            light_->changeColor(effectColor_);
        }
    }

    if (currentEffectCounter_ > 0)
    {
        ++currentIndex_;
        previousEffectMillis_ = millis;
    }
}

void ColorWipeEffect::stop()
{
    LightEffect::stop();
    if (turnOffAtStop_)
    {
        light_->off();
    }
    else
    {
        light_->changeColor(targetColor_);
    }
}