#ifndef LIGHTCONTROLLER_H
#define LIGHTCONTROLLER_H

#include <Arduino.h>

#include "Light/Light.h"
#include "Light/LightEffects/LightEffect.h"

/**
 * @brief Want to control a light? Want to add awesome effect on the light? Use this class!
 *
 */
class LightController
{
public:
    /**
     * @brief Construct a new Light Controller object
     *
     * @param light
     */
    LightController(Light &light);

    /**
     * @brief Get the Light object
     *
     * @return Light&
     */
    Light &GetLight() const;

    /**
     * @brief Add a LightEffect to the light controller.
     *
     * @param effectIndex index of the LightEffect in the effect array [0,9].
     * @param effect Pointer to the LightEffect.
     */
    void AddLightEffect(uint8_t effectIndex, LightEffect *effect);

    /**
     * @brief Activate the LightEffect at effectIndex.
     *
     * @param effectIndex index of the LightEffect in the effect array [0,9].
     * @param millis current time.
     */
    void SetEffect(uint8_t effectIndex, unsigned long millis);

    /**
     * @brief Stop the LightEffect at effectIndex.
     *
     * @param effectIndex index of the LightEffect in the effect array [0,9].
     * @param millis current time.
     */
    void StopEffect(uint8_t effectIndex, unsigned long millis);

    /**
     * @brief Update the light effect.
     *
     * @param millis current time.
     */
    void execute(unsigned long millis);

    /**
     * @brief Is the effect stopped.
     *
     * @param effectIndex index of the LightEffect in the effect array [0,9].
     * @return true if the effect is stopped.
     * @return false if the effect is running.
     */
    inline bool isEffectStopped(uint8_t effectIndex)
    {
        return lightEffects_[effectIndex]->isStopped();
    }

private:
    Light &light_;
    /**
     * @brief array of LightEffect.
     * @todo Dynamically create the array.
     * 
     */
    LightEffect *lightEffects_[10];
    int8_t activeLightEffect_;
};

#endif // !LIGHTCONTROLLER_H