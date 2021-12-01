#ifndef LIGHTCONTROLLER_H
#define LIGHTCONTROLLER_H

#include <Arduino.h>

#include "Light/Light.h"
#include "Light/LightEffects/LightEffect.h"

class LightController
{
public:
    LightController(Light &light);
    Light &GetLight() const;
    void AddLightEffect(uint8_t effectIndex, LightEffect *effect);
    void SetEffect(uint8_t effectIndex, unsigned long millis);
    void StopEffect(uint8_t effectIndex, unsigned long millis);
    void execute(unsigned long millis);

    inline bool isEffectStopped(uint8_t effectIndex)
    {
        return lightEffects_[effectIndex]->isStopped();
    }

private:
    Light &light_;
    LightEffect * lightEffects_[10];
    int8_t activeLightEffect_;
};

#endif // !LIGHTCONTROLLER_H