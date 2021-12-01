#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

#include "Light/Color.h"

/**
 * Enumeration for the different state of a light.
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
 * Representation of a light, made from several pixel from neo pixel strip.
 */
class Light
{
public:
	Light();

	/**
	 * Light constructor
	 * @param strip The led strip used.
	 * @param pixelCount The number of pixel needed for the light.
	 * @param firstPixelIndex The index of the first pixel.
	 * @param lightColor The light Color
	 */
	Light(Adafruit_NeoPixel *strip, uint8_t pixelCount, uint8_t firstPixelIndex, Color lightColor);

	/**
	 * Set a new color for the light.
	 * @param red Red component of the color.
	 * @param green Green component of the color.
	 * @param blue Blue component of the color.
	 */
	void changeColor(int red, int green, int blue);

	/**
	 * Set a new color for the light.
	 * @param color new color.	
	 */
	void changeColor(Color color);

	/**
	* Hey, who turned out the lights?
	*/
	void off();

	/**
	* Turn on the lights.
	*/
	void on();


	inline uint8_t firstPixelIndex() const { return firstPixelIndex_; }
	inline uint8_t pixelCount() const { return pixelCount_; }
	void setPixelColor(uint8_t pixelIndex);
	void setPixelColor(uint8_t pixelIndex, Color color);
	void setPixelColor(uint8_t pixelIndex, uint32_t color);

    inline Color color() const { return lightColor_; }

private:
	Adafruit_NeoPixel *strip_;

	uint8_t pixelCount_;
	uint8_t firstPixelIndex_;

	Color lightColor_;
};

#endif // !LIGHT_HPP_