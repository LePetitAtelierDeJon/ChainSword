#include "Light/LightEffects/CrawlEffect.h"

void CrawlEffect::start(unsigned long startMillis)
{
    LightEffect::start(startMillis);
    light_->changeColor(effectColor_);
}

void CrawlEffect::executeEffect(unsigned long millis)
{
    light_->setPixelColor(currentIndex_ - effectSize_, effectColor_);

    if (currentIndex_ < light_->firstPixelIndex() + light_->pixelCount())
    {
        light_->setPixelColor(currentIndex_, targetColor_);
    }

    currentIndex_ += 1;

    if (currentIndex_ >= light_->firstPixelIndex() + light_->pixelCount() + effectSize_)
    {
        decrementEffectCounter();
        currentIndex_ = 0;
    }

    previousEffectMillis_ = millis;
}

void CrawlEffect::stop(bool turnOff)
{
    LightEffect::stop(turnOff);
    light_->on();
}

void CrawlEffect::setup(uint8_t effectCounter, unsigned long effectFrequency, bool turnOffAtStop)
{
    LightEffect::setup(effectCounter, effectFrequency, turnOffAtStop);
    fadeSize_ = 0;
    effectSize_ = 0;
}

void CrawlEffect::setEffectSize(uint8_t effectSize)
{
    effectSize_ = effectSize;
}
