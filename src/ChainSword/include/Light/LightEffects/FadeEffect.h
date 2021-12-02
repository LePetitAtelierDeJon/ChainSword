#ifndef FADEEFFECT_H_
#define FADEEFFECT_H_

#include "LightEffect.h"

class FadeEffect : public LightEffect
{
public:
    virtual ~FadeEffect() {}
    
    void start(unsigned long startMillis) override;
    void executeEffect(unsigned long millis) override;
    void stop() override;

private:
    Color currentColor_;
    Color addColor_;
};

#endif // !FADEEFFECT_H_