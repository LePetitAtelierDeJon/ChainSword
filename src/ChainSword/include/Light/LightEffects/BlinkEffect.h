#ifndef BLINKEFFECT_H_
#define BLINKEFFECT_H_

#include "LightEffect.h"

class BlinkEffect : public LightEffect
{
public:
    virtual ~BlinkEffect() {}

    void start(unsigned long startMillis);
    void executeEffect(unsigned long millis);
    bool isStopped() const;
    void stop(bool turnOff);

private:
    bool blinkState_;
};

#endif // !BLINKEFFECT_H_