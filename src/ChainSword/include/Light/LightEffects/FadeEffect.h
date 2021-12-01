#ifndef FADEEFFECT_H_
#define FADEEFFECT_H_

#include "LightEffect.h"

class FadeEffect : public LightEffect
{
public:
    virtual ~FadeEffect() {}
    
    void start(unsigned long startMillis);
    void executeEffect(unsigned long millis);
    bool isStopped() const;
    void stop(bool turnOff);

private:
    Color currentColor;
    Color addColor;
};

#endif // !FADEEFFECT_H_