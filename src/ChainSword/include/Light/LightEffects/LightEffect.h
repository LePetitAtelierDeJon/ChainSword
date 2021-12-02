#ifndef LIGHTEFFECT_H_
#define LIGHTEFFECT_H_

#include <Adafruit_NeoPixel.h>
#include "Light/Light.h"

class LightEffect
{
public:
    virtual ~LightEffect() {}
    LightEffect() {}

    virtual void executeEffect(unsigned long millis) = 0;

    virtual void start(unsigned long startMillis);
    virtual void stop();
    virtual void setup(uint8_t effectCounter, unsigned long effectFrequency, bool turnOffAtStop);

    void execute(unsigned long millis);
    void decrementEffectCounter();

    inline virtual void setLight(Light &light)
    {
        light_ = &light;
    }

    inline void setEffectColor(Color color)
    {
        effectColor_ = color;
    }

    inline void setTargetColor(Color color)
    {
        targetColor_ = color;
    }

    inline bool canExecute(unsigned long millis) const
    {
        return (millis - previousEffectMillis_) >= effectFrequency_;
    }

    inline bool isStopped() const
    {
        return isStopped_;
    };

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