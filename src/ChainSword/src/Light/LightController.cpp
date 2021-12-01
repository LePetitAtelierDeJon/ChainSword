#include "Light/LightController.h"

LightController::LightController(Light &light) : light_(light) {}

Light &LightController::GetLight() const
{
    return light_;
}

void LightController::AddLightEffect(String effectName, LightEffect *effect)
{
    effect->setLight(light_);
    lightEffects_[effectName] = effect;
}

void LightController::SetEffect(String effectName, unsigned long millis)
{
    lightEffects_[effectName]->start(millis); 
    activeLightEffect_ = effectName;    
}

void LightController::StopEffect(String effectName, unsigned long millis)
{
    lightEffects_[effectName]->stop(millis);
    activeLightEffect_ = "";
}

void LightController::execute(unsigned long millis)
{
    if (activeLightEffect_ != "")
    {
        if (lightEffects_[activeLightEffect_]->canExecute(millis))
        {
            lightEffects_[activeLightEffect_]->execute(millis);
        }
    }
}