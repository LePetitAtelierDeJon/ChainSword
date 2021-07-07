#ifndef LIGHTEFFECT_H_
#define LIGHTEFFECT_H_

#include <Adafruit_NeoPixel.h>
#include "Light/Light.h"

class LightEffect
{
public:
    virtual ~LightEffect() {}
    LightEffect() {}

    virtual void init(Light *light)
    {
        light_ = light;
    }

    virtual void setup(uint8_t effectCounter, unsigned long effectFrequency, bool turnOffAtStop = true)
    {
        effectCounter_ = effectCounter;
        effectFrequency_ = effectFrequency;
        currentIndex_ = 0;
        turnOffAtStop_ = turnOffAtStop;
    }

    virtual void start(unsigned long startMillis) = 0;
    virtual void executeEffect(unsigned long millis) = 0;

    void execute(unsigned long millis)
    {
        if (canExecute(millis))
        {
            if (effectCounter_ > 0 || effectCounter_ <= -1)
            {
                executeEffect(millis);
                previousEffectMillis_ = millis;
            }
            else
            {
                stop(turnOffAtStop_);
            }
        }
    }

    virtual bool isStopped() const = 0;
    virtual void stop(bool turnOff) = 0;

    inline void decrementEffectCounter()
    {
        if (effectCounter_ > 0)
        {
            --effectCounter_;
        }
    }

    inline bool canExecute(unsigned long millis) { return (millis - previousEffectMillis_) >= effectFrequency_; }

protected:
    Light *light_;
    uint8_t effectCounter_;
    unsigned long effectFrequency_;
    unsigned long previousEffectMillis_;
    uint8_t currentIndex_;
    bool turnOffAtStop_;
};

#endif // !LIGHTEFFECT_H_