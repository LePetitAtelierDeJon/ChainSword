#include "Light/LightController.h"

LightController::LightController(Light &light) : light_(light) {}

Light &LightController::GetLight() const
{
    return light_;
}

void LightController::AddLightEffect(uint8_t effectIndex, LightEffect *effect)
{
    effect->setLight(light_);
    lightEffects_[effectIndex] = effect;
}

void LightController::SetEffect(uint8_t effectIndex, unsigned long millis)
{
    lightEffects_[effectIndex]->start(millis); 
    activeLightEffect_ = effectIndex;    
}

void LightController::StopEffect(uint8_t effectIndex, unsigned long millis)
{
    lightEffects_[effectIndex]->stop();
    activeLightEffect_ = -1;
}

void LightController::execute(unsigned long millis)
{
    if (activeLightEffect_ != -1)
    {
        if (lightEffects_[activeLightEffect_]->canExecute(millis))
        {
            lightEffects_[activeLightEffect_]->execute(millis);
        }
    }
}