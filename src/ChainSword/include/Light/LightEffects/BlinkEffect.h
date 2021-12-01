#ifndef BLINKEFFECT_H_
#define BLINKEFFECT_H_

#include "LightEffect.h"

class BlinkEffect : public LightEffect
{
public:
    virtual ~BlinkEffect() {}

    void start(unsigned long startMillis) override;
    void executeEffect(unsigned long millis) override;
    void stop() override;

private:
    bool blinkState_;
};

#endif // !BLINKEFFECT_H_