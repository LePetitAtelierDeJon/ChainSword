#include "Light/LightEffects/LightEffect.h"

void LightEffect::start(unsigned long startMillis)
{
    previousEffectMillis_ = startMillis;
    currentEffectCounter_ = effectCounter_;
    isStopped_ = false;
}

void LightEffect::setup(uint8_t effectCounter, unsigned long effectFrequency, bool turnOffAtStop)
{
    effectCounter_ = effectCounter;
    currentEffectCounter_ = effectCounter_;
    effectFrequency_ = effectFrequency;
    currentIndex_ = 0;
    turnOffAtStop_ = turnOffAtStop;
    isStopped_ = false;
}

void LightEffect::execute(unsigned long millis)
{
    if (canExecute(millis))
    {
        if (currentEffectCounter_ > 0 || currentEffectCounter_ <= -1)
        {
            executeEffect(millis);
            previousEffectMillis_ = millis;
        }
        else
        {
            stop();
        }
    }
}

void LightEffect::decrementEffectCounter()
{
    if (currentEffectCounter_ > 0)
    {
        --currentEffectCounter_;
    }

    if (currentEffectCounter_ <= 0)
    {
        isStopped_ = true;
    }
}

void LightEffect::stop()
{
    previousEffectMillis_ = 0;
    currentIndex_ = 0;
}