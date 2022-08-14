#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <ezButton.h>

#include "ChainSword.h"
#include "Light/Light.h"
#include "Light/LightController.h"

#define LED_PIN 6
#define MOTOR_PIN 4
#define TRIGGER_PIN 2
#define LED_COUNT 32

/**
 * @brief RGB Strop led.
 *
 */
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

/**
 * @brief The light inside the blade.
 *
 */
Light bladeLight(&strip, LED_COUNT, 0, Color(0, 0, 0));

/**
 * @brief The light controller for the light bladeLight.
 *
 */
LightController controller(bladeLight);

/**
 * @brief The chainsword object.
 *
 */
ChainSword chainSword;

// variables for antiGhosting on the trigger.
unsigned long previousDelay = 0;
const unsigned long antiGhostingDelay = 100;

ezButton triggerButton(TRIGGER_PIN);

void trigger();

/**
 * @brief Arduino setup callback. Init the chainsword components.
 *
 */
void setup()
{
    Serial.begin(9600);
    Serial.println("+++ Machine Spirit Awaken +++");

    pinMode(MOTOR_PIN, OUTPUT);
    triggerButton.setDebounceTime(antiGhostingDelay);

    Serial.println("+++ Chainsword Initialisation +++");
    chainSword.setLightController(&controller);
    chainSword.setMotorPin(MOTOR_PIN);

    chainSword.init();

    strip.begin();
    strip.show();

    Serial.println("+++ End of Initialisation +++");
}

/**
 * @brief Arduino loop callback. execute the statemachine execute method.
 *
 */
void loop()
{
    unsigned long currentMillis = millis();
    triggerButton.loop();

    if (triggerButton.isPressed())
    {
        chainSword.toggleTrigger(currentMillis);
    }

    if (triggerButton.isReleased())
    {
        chainSword.toggleTrigger(currentMillis);
    }

    chainSword.execute(currentMillis);
}