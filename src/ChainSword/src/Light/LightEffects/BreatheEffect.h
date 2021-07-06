#ifndef BREATHEEFFECT_H_
#define BREATHEEFFECT_H_

#include "LightEffect.h"

class BreatheEffect : public LightEffect
{
public:
    virtual ~BreatheEffect() {}

    void setup(uint8_t effectCounter, unsigned long effectFrequency);
    void start(unsigned long startMillis);
    void executeEffect(unsigned long millis);
    bool isStopped() const;
    void stop();
    void setEffectSize(uint8_t effectSize);
    void setEffectDuration(uint8_t duration);

private:
    int8_t currentIndex_;
    int8_t effectDirection_;
    uint8_t effectSize_;
    uint8_t fadeSize_;
    uint8_t effectDuration_;
};

#endif // !BREATHEEFFECT_H_