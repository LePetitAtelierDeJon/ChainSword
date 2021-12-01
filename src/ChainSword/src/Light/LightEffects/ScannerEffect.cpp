#include "Light/LightEffects/ScannerEffect.h"

void ScannerEffect::start(unsigned long startMillis)
{
    light_->changeColor(effectColor_);
    previousEffectMillis_ = startMillis;
    currentEffectCounter_ = effectCounter_;
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
    if (turnOff)
    {
        light_->off();
    }
    else
    {
        light_->on();
    }

    previousEffectMillis_ = 0;
    currentIndex_ = 0;
}

bool ScannerEffect::isStopped() const
{
    return false;
}

void ScannerEffect::setup(uint8_t effectCounter, unsigned long effectFrequency, bool turnOffAtStop = true)
{
    effectCounter_ = effectCounter;
    effectFrequency_ = effectFrequency;
    currentIndex_ = 0;
    fadeSize_ = 0;
    effectSize_ = 0;
    effectDirection_ = 1;
    turnOffAtStop_ = turnOffAtStop;
}

void ScannerEffect::setEffectSize(uint8_t effectSize)
{
    effectSize_ = effectSize;
}