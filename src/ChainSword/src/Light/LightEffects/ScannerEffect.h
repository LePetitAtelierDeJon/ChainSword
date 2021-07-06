#ifndef SCANNEREFFECT_H_
#define SCANNEREFFECT_H_

#include "LightEffect.h"

class ScannerEffect : public LightEffect
{
public:
    virtual ~ScannerEffect() {}

    void setup(uint8_t effectCounter, unsigned long effectFrequency, bool turnOffAtStop = true);
    void start(unsigned long startMillis);
    void executeEffect(unsigned long millis);
    bool isStopped() const;
    void stop(bool turnOff);
    void setEffectSize(uint8_t effectSize);

private:
   int8_t currentIndex_; 
   int8_t effectDirection_;
   uint8_t effectSize_;
   uint8_t fadeSize_;
   Color otherColor_;
};

#endif // !SCANNEREFFECT_H_