#include "Light/LightEffects/CrawlEffect.h"

void CrawlEffect::start(unsigned long startMillis)
{
    previousEffectMillis_ = startMillis;
    currentEffectCounter_ = effectCounter_;
}

void CrawlEffect::executeEffect(unsigned long millis)
{
    light_->setPixelColor(currentIndex_ - effectSize_);

    if (currentIndex_ < light_->firstPixelIndex() + light_->pixelCount())
    {
        light_->setPixelTargetColor(currentIndex_);
    }

    currentIndex_ += 1;

    if (currentIndex_ >= light_->firstPixelIndex() + light_->pixelCount() + effectSize_ )
    {
        decrementEffectCounter();
        currentIndex_ = 0;
    }

    previousEffectMillis_ = millis;
}

void CrawlEffect::stop(bool turnOff)
{
    light_->on();
    previousEffectMillis_ = 0;
    currentIndex_ = 0;
}

bool CrawlEffect::isStopped() const
{
    return false;
}

void CrawlEffect::setup(uint8_t effectCounter, unsigned long effectFrequency)
{
    effectCounter_ = effectCounter;
    effectFrequency_ = effectFrequency;
    currentIndex_ = 0;
    fadeSize_ = 0;
    effectSize_ = 0;
}

void CrawlEffect::setEffectSize(uint8_t effectSize)
{
    effectSize_ = effectSize;
}
