#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

#include "Light/Color.h"

/**
 * @brief Enumeration for the different state of a light.
 *
 */
enum class LightState
{
    Initialization,
    Wipe,
    Blink,
    Fade,
    FadeTo,
    Crawl,
    Scanner,
    Idle,
    MaxState
};

/**
 * @brief Representation of a light, made from several pixel from neo pixel strip.
 *
 */
class Light
{
public:
    /**
     * @brief Construct a new Light object
     *
     */
    Light();

    /**
     * @brief Construct a new Light object
     *
     * @param strip The led strip used.
     * @param pixelCount The number of pixel needed for the light.
     * @param firstPixelIndex The index of the first pixel.
     * @param lightColor The light Color
     */
    Light(Adafruit_NeoPixel *strip, uint8_t pixelCount, uint8_t firstPixelIndex, Color lightColor);

    /**
     * @brief Set a new color for the light.
     *
     * @param red Red component of the color.
     * @param green Green component of the color.
     * @param blue Blue component of the color.
     */
    void changeColor(int red, int green, int blue);

    /**
     * @brief Set a new color for the light.
     *
     * @param color new color.
     */
    void changeColor(Color color);

    /**
     * @brief Hey, who turned out the lights?
     *
     */
    void off();

    /**
     * @brief Turn on the lights.
     *
     */
    void on();

    /**
     * @brief get the index of the first pixel for the light. Useful when several light object shares the same strip.
     *
     * @return uint8_t index of the first pixel.
     */
    inline uint8_t firstPixelIndex() const
    {
        return firstPixelIndex_;
    }

    /**
     * @brief Get the light's number of pixel. Useful when several light object shares the same strip.
     *
     * @return uint8_t
     */
    inline uint8_t pixelCount() const
    {
        return pixelCount_;
    }

    /**
     * @brief Set, for the pixel at pixelIndex, the current color of the light.
     *
     * @param pixelIndex Index of the pixel.
     */
    void setPixelColor(uint8_t pixelIndex);

    /**
     * @brief Set, for the pixel at pixelIndex, the color parameter as Color struct.
     *
     * @param pixelIndex Index of the pixel.
     * @param color Color to set to the pixel.
     */
    void setPixelColor(uint8_t pixelIndex, Color color);

    /**
     * @brief Get the current color of the light.
     *
     * @return Color of the light.
     */
    inline Color color() const { return lightColor_; }

private:
    /**
     * @brief NeoPixel strip led.
     *
     */
    Adafruit_NeoPixel *strip_;

    /**
     * @brief Number of pixel on the light.
     *
     */
    uint8_t pixelCount_;

    /**
     * @brief Index of the first pixel on the light.
     *
     */
    uint8_t firstPixelIndex_;

    /**
     * @brief Current color of the light.
     *
     */
    Color lightColor_;
};

#endif // !LIGHT_HPP_