#include "Light/LightEffects/BreatheEffect.h"

void BreatheEffect::start(unsigned long startMillis)
{
    previousEffectMillis_ = startMillis;
}

void BreatheEffect::executeEffect(unsigned long millis)
{
    light_->setPixelTargetColor(currentIndex_ - effectSize_);

    if (currentIndex_ < light_->firstPixelIndex() + light_->pixelCount())
    {
        light_->setPixelColor(currentIndex_);
    }

    currentIndex_ += 1;

    if (currentIndex_ >= light_->firstPixelIndex() + light_->pixelCount() + effectSize_)
    {
        decrementEffectCounter();
        currentIndex_ = 0;
    }

    previousEffectMillis_ = millis;
}

void BreatheEffect::stop()
{
    light_->off();
    previousEffectMillis_ = 0;
    currentIndex_ = 0;
}

bool BreatheEffect::isStopped() const
{
    return false;
}

void BreatheEffect::setup(uint8_t effectCounter, unsigned long effectFrequency)
{
    effectCounter_ = effectCounter;
    effectFrequency_ = effectFrequency;
    currentIndex_ = 0;
    fadeSize_ = 0;
    effectSize_ = 0;
    effectDuration_ = 3;
}

void BreatheEffect::setEffectSize(uint8_t effectSize)
{
    effectSize_ = effectSize;
}

void BreatheEffect::setEffectDuration(uint8_t duration)
{
    effectDuration_ = duration;
}