#ifndef COLORWIPEEFFECT_H_
#define COLORWIPEEFFECT_H_

#include "LightEffect.h"

class ColorWipeEffect : public LightEffect
{
public:
    virtual ~ColorWipeEffect() {}
    
    void start(unsigned long startMillis) override;
    void executeEffect(unsigned long millis) override;
    void stop() override;

private:
   uint8_t currentIndex_; 
};

#endif // !COLORWIPEEFFECT_H_