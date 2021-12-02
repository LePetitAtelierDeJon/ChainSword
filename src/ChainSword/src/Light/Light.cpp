#include "Light/Light.h"

Light::Light(Adafruit_NeoPixel *strip,
             uint8_t pixelCount,
             uint8_t firstPixelIndex,
             Color lightColor) : strip_(strip),
                                 pixelCount_(pixelCount),
                                 firstPixelIndex_(firstPixelIndex),
                                 lightColor_(lightColor)
{
}

Light::Light() : strip_(nullptr)
{
}

void Light::changeColor(int red, int green, int blue)
{
    Color color = Color(red, green, blue);
    changeColor(color);
}

void Light::changeColor(Color color)
{
    lightColor_ = color;
    uint32_t colorInt = strip_->Color((uint8_t)lightColor_.red,
                               (uint8_t)lightColor_.green,
                               (uint8_t)lightColor_.blue);
    strip_->fill(colorInt, firstPixelIndex_, pixelCount_);
    strip_->show();
}

void Light::off()
{
    strip_->fill(0, firstPixelIndex_, pixelCount_);
    strip_->show();
}

void Light::on()
{
    uint32_t colorInt = strip_->Color((uint8_t)lightColor_.red,
                               (uint8_t)lightColor_.green,
                               (uint8_t)lightColor_.blue);
    strip_->fill(colorInt, firstPixelIndex_, pixelCount_);
    strip_->show();
}

void Light::setPixelColor(uint8_t pixelIndex)
{
    uint32_t colorInt = strip_->Color((uint8_t)lightColor_.red,
                               (uint8_t)lightColor_.green,
                               (uint8_t)lightColor_.blue);
    strip_->setPixelColor(pixelIndex, colorInt);
    strip_->show();
}

void Light::setPixelColor(uint8_t pixelIndex, Color color)
{
    uint32_t colorInt = strip_->Color((uint8_t)color.red,
                               (uint8_t)color.green,
                               (uint8_t)color.blue);
    strip_->setPixelColor(pixelIndex, colorInt);
    strip_->show();
}