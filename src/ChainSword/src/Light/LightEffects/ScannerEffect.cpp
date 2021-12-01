#include "Light/LightEffects/ScannerEffect.h"

void ScannerEffect::start(unsigned long startMillis)
{
    LightEffect::start(startMillis);
    light_->changeColor(effectColor_);
}

void ScannerEffect::executeEffect(unsigned long millis)
{
    light_->setPixelColor(currentIndex_ - (effectDirection_ * effectSize_), effectColor_);

    if (currentIndex_ < light_->firstPixelIndex() + light_->pixelCount() && currentIndex_ >= light_->firstPixelIndex())
    {
        light_->setPixelColor(currentIndex_, targetColor_);
    }

    if (currentIndex_ >= light_->firstPixelIndex() + light_->pixelCount() - 1 + effectSize_ || currentIndex_ <= light_->firstPixelIndex() - effectSize_)
    {
        effectDirection_ *= -1;
        if (effectDirection_ == 1)
        {
            decrementEffectCounter();
        }
    }
    currentIndex_ += effectDirection_;

    previousEffectMillis_ = millis;
}

void ScannerEffect::stop(bool turnOff)
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

void ScannerEffect::setup(uint8_t effectCounter, unsigned long effectFrequency, bool turnOffAtStop)
{
    LightEffect::setup(effectCounter, effectFrequency, turnOffAtStop);
    effectSize_ = 0;
    effectDirection_ = 1;
}

void ScannerEffect::setEffectSize(uint8_t effectSize)
{
    effectSize_ = effectSize;
}