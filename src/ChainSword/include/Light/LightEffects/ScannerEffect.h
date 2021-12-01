#ifndef SCANNEREFFECT_H_
#define SCANNEREFFECT_H_

#include "Light/LightEffects/LightEffect.h"

class ScannerEffect : public LightEffect
{
public:
    virtual ~ScannerEffect() {}

    void setup(uint8_t effectCounter, unsigned long effectFrequency, bool turnOffAtStop) override;
    void start(unsigned long startMillis) override;
    void executeEffect(unsigned long millis) override;
    void stop(bool turnOff) override;
    void setEffectSize(uint8_t effectSize);

private:
   int8_t currentIndex_; 
   int8_t effectDirection_;
   uint8_t effectSize_;
   Color otherColor_;
};

#endif // !SCANNEREFFECT_H_