#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "StateMachine/StateMachine.h"
#include "StateMachine/States/StartState.h"
#include "StateMachine/States/IdleState.h"
#include "StateMachine/States/RunningState.h"
#include "ChainSword.h"
#include "Light/Light.h"
#include "Light/LightController.h"
#include "Light/LightEffects/BlinkEffect.h"
#include "Light/LightEffects/ColorWipeEffect.h"
#include "Light/LightEffects/ScannerEffect.h"
#include "Light/LightEffects/CrawlEffect.h"

#define LED_PIN 6
#define LED_COUNT 32

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
StateMachine<ChainSword> stateMachine;
StartState startState;
IdleState idleState;
RunningState runningState;
ChainSword chainSword;

const Color primaryColor = Color(20, 20, 0);
const Color secondaryColor = Color(0, 20, 20);
Light bladeLight(&strip, LED_COUNT, 0, 60, primaryColor);
LightController controller(bladeLight);
BlinkEffect blink;
ColorWipeEffect wipe;
ScannerEffect scanner;
CrawlEffect crawl;

void trigger();
void triggerOff();

void setup()
{
    pinMode(2, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(2), trigger, CHANGE);

    Serial.begin(9600);
    Serial.println("setup");
    chainSword.setLight(&controller);
    stateMachine.setOwner(&chainSword);

    wipe.init(&bladeLight);
    wipe.setup(1, 20, false);
    controller.AddLightEffect("Wipe", &wipe);

    blink.init(&bladeLight);
    blink.setup(2, 500);
    controller.AddLightEffect("Blink", &blink);

    scanner.init(&bladeLight);
    scanner.setup(-1, 20, false);
    scanner.setEffectSize(3);
    controller.AddLightEffect("Scanner", &scanner);

    crawl.init(&bladeLight);
    crawl.setup(10, 20);
    crawl.setEffectSize(5);
    controller.AddLightEffect("Crawl", &crawl);
    //   controller.SetEffect("Scanner", millis());
    //controller.SetEffect("Crawl", millis());

    stateMachine.changeState(&startState, millis());

    // bladeLight.changeTargetColor(secondaryColor);
    strip.begin();
    strip.show();

    // bladeLight2.changeTargetColor(secondaryColor2);
    // strip.begin();
    // strip.show();
    // blink.init(&bladeLight);
    // blink.setup(4, 500);
    // controller.AddLightEffect("Blink", &blink);
    // blink2.init(&bladeLight2);
    // blink2.setup(-1, 500);
    // controller2.AddLightEffect("Blink", &blink2);
    // //   wipe.init(&bladeLight);
    // //   wipe.setup(4, 50, false);
    // //   controller.AddLightEffect("Wipe", &wipe);
    // scanner.init(&bladeLight2);
    // scanner.setup(-1, 20, false);
    // scanner.setEffectSize(3);
    // controller2.AddLightEffect("Scanner", &scanner);
    // crawl.init(&bladeLight);
    // crawl.setup(-1, 20);
    // crawl.setEffectSize(5);
    // controller.AddLightEffect("Crawl", &crawl);
    // //   controller.SetEffect("Scanner", millis());
    // controller.SetEffect("Crawl", millis());
    // controller2.SetEffect("Scanner", millis());
    // // bladeLight.changeColor(primaryColor);
    // // bladeLight2.changeColor(secondaryColor);
}

unsigned long dateDernierChangement = 0;
const unsigned long dureeAntiRebond = 10;
unsigned long plop = 0;

void trigger()
{
    unsigned long date = millis();
    if ((date - dateDernierChangement) > dureeAntiRebond)
    {
        dateDernierChangement = date;
        Serial.println(plop++);

        chainSword.toggleTrigger();
        if (chainSword.isTriggerOn())
        {
            stateMachine.changeState(&runningState, millis());
        }
        else
        {
            stateMachine.changeState(&idleState, millis());
        }
    }
}

bool switchstate = false;

void loop()
{
    //controller.execute(millis());
    //controller2.execute(millis());
    stateMachine.execute(millis());

    if (controller.isEffectStopped("Wipe") && !switchstate)
    {
        switchstate = true;
        Serial.println("change state");
        stateMachine.changeState(&idleState, millis());
    }
}