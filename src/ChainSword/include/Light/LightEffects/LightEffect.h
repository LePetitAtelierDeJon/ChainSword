#ifndef LIGHTEFFECT_H_
#define LIGHTEFFECT_H_

#include <Adafruit_NeoPixel.h>
#include "Light/Light.h"

class LightEffect
{
public:
    virtual ~LightEffect() {}
    LightEffect() {}

    virtual void setLight(Light &light)
    {
        light_ = &light;
    }

    virtual void setup(uint8_t effectCounter, unsigned long effectFrequency, bool turnOffAtStop = true)
    {
        effectCounter_ = effectCounter;
        currentEffectCounter_ = effectCounter_;
        effectFrequency_ = effectFrequency;
        currentIndex_ = 0;
        turnOffAtStop_ = turnOffAtStop;
        isStopped_ = false;
    }

    virtual void start(unsigned long startMillis) = 0;
    virtual void executeEffect(unsigned long millis) = 0;

    void execute(unsigned long millis)
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
                stop(turnOffAtStop_);
            }
        }
    }

    inline bool isStopped() const { return isStopped_; };
    virtual void stop(bool turnOff) = 0;

    inline void decrementEffectCounter()
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

    inline Color effectColor() const
    {
        return effectColor_;
    }

    inline Color targetColor() const
    {
        return targetColor_;
    }

    inline void setEffectColor(Color color)
    {
        effectColor_ = color;
    }

    inline void setTargetColor(Color color)
    {
        targetColor_ = color;
    }

    inline bool canExecute(unsigned long millis) { return (millis - previousEffectMillis_) >= effectFrequency_; }

protected:
    Light *light_;
    uint8_t effectCounter_;
    uint8_t currentEffectCounter_;
    unsigned long effectFrequency_;
    unsigned long previousEffectMillis_;
    uint8_t currentIndex_;
    bool turnOffAtStop_;
    bool isStopped_ = false;
    Color effectColor_;
    Color targetColor_;
};

#endif // !LIGHTEFFECT_H_