#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

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
Light bladeLight(&strip, LED_COUNT, 0, Color(0,0,0));

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

void trigger();

/**
 * @brief Arduino setup callback. Init the chainsword components.
 * 
 */
void setup()
{
    Serial.begin(9600);
    Serial.println("+++ Machine Spirit Awaken +++");

    pinMode(TRIGGER_PIN, INPUT_PULLUP);
    pinMode(MOTOR_PIN, OUTPUT);
    // Attach the interrupt for the trigger action.
    // The interrupt call the trigger method.
    attachInterrupt(digitalPinToInterrupt(TRIGGER_PIN), trigger, CHANGE);

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
    chainSword.execute(currentMillis);
}

/**
 * @brief Method called when the trigger is pulled or released.
 * Anti ghosting delay is provided to avoid ghost calls.
 * 
 */
void trigger()
{
    unsigned long currentMillis = millis();
    if ((currentMillis - previousDelay) > antiGhostingDelay)
    {
        previousDelay = currentMillis;
        chainSword.toggleTrigger(currentMillis);        
    }
}