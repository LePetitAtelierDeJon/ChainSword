#ifndef LIGHTCONTROLLER_H
#define LIGHTCONTROLLER_H

#include <Arduino.h>
#include <ArduinoSTL.h>
#include <map>

#include "Light/Light.h"
#include "Light/LightEffects/LightEffect.h"



class LightController
{
public:
    LightController(Light &light);
    Light &GetLight() const;
    void AddLightEffect(String effectName, LightEffect* effect);
    void SetEffect(String effectName, unsigned long millis);
    void execute(unsigned long millis);

private:
    Light &light_;
    std::map<String, LightEffect*> lightEffects_;
    String activeLightEffect_;
};

#endif // !LIGHTCONTROLLER_H