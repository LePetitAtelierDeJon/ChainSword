#ifndef COLORWIPEEFFECT_H_
#define COLORWIPEEFFECT_H_

#include "LightEffect.h"

class ColorWipeEffect : public LightEffect
{
public:
    virtual ~ColorWipeEffect() {}
    
    void start(unsigned long startMillis);
    void executeEffect(unsigned long millis);
    bool isStopped() const;
    void stop(bool turnOff);

private:
   uint8_t currentIndex_; 
};

#endif // !COLORWIPEEFFECT_H_