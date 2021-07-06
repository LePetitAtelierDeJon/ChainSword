#include "Light.h"

/**
 * Light constructor
 * @param strip The led strip used.
 * @param pixelCount The number of pixel needed for the light.
 * @param firstPixelIndex The index of the first pixel.
 * @param updateFrequency The update frequency of the light.
 * @param lightColor The light Color
 */
Light::Light(Adafruit_NeoPixel *strip, uint8_t pixelCount, uint8_t firstPixelIndex, long updateFrequency, Color lightColor) : strip_(strip),
                                                                                                                              pixelCount_(pixelCount),
                                                                                                                              firstPixelIndex_(firstPixelIndex),
                                                                                                                              updateFrequency_(updateFrequency),
                                                                                                                              lightColor_(lightColor)
{
}

Light::Light() : strip_(nullptr)
{
}

/**
 * Change the color for the light.
 * @param red Red component of the color.
 * @param green Green component of the color.
 * @param blue Blue component of the color.
 */
void Light::changeColor(uint8_t red, uint8_t green, uint8_t blue)
{
    // uint32_t color = strip_.Color(red, green, blue);
    Color color = Color(red, green, blue);
    changeColor(color);
}

void Light::changeColor(Color color)
{
    lightColor_ = color;
    strip_->fill(strip_->Color(lightColor_.red, lightColor_.green, lightColor_.blue), firstPixelIndex_, pixelCount_);
    strip_->show();
}

void Light::changeTargetColor(uint8_t red, uint8_t green, uint8_t blue)
{
    Color color = Color(red, green, blue);
    changeTargetColor(color);
}

void Light::changeTargetColor(Color color)
{
    targetColor_ = color;
    // strip_->fill(strip_->Color(targetColor_.red, targetColor_.green, targetColor_.blue), firstPixelIndex_, pixelCount_);
    // strip_->show();
}

/**
 * Hey, who turned out the lights?
 */
void Light::off()
{
    strip_->fill(0, firstPixelIndex_, pixelCount_);
    strip_->show();
}

/**
 * Turn on the lights.
 */
void Light::on()
{
    strip_->fill(strip_->Color(lightColor_.red, lightColor_.green, lightColor_.blue), firstPixelIndex_, pixelCount_);
    strip_->show();
}

/**
 * Turn on the lights.
 */
void Light::turnTargetOn()
{
    strip_->fill(strip_->Color(targetColor_.red, targetColor_.green, targetColor_.blue), firstPixelIndex_, pixelCount_);
    strip_->show();
}

void Light::setPixelColor(uint8_t pixelIndex)
{
    strip_->setPixelColor(pixelIndex, strip_->Color(lightColor_.red, lightColor_.green, lightColor_.blue));
    strip_->show();
}

void Light::setPixelTargetColor(uint8_t pixelIndex)
{
    strip_->setPixelColor(pixelIndex, strip_->Color(targetColor_.red, targetColor_.green, targetColor_.blue));
    strip_->show();
}

void Light::setPixelColor(uint8_t pixelIndex, Color color)
{
    strip_->setPixelColor(pixelIndex, strip_->Color(color.red, color.green, color.blue));
    strip_->show();
}

void Light::setPixelColor(uint8_t pixelIndex, uint32_t color)
{
    strip_->setPixelColor(pixelIndex, color);
    strip_->show();
}