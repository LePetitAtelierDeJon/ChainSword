#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "StateMachine/StateMachine.h"
#include "StateMachine/States/StartState.h"
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
ChainSword chainSword;

const Color primaryColor = Color(20, 20, 0);
const Color secondaryColor = Color(0, 20, 20);
Light bladeLight(&strip, LED_COUNT, 0, 60, primaryColor);
LightController controller(bladeLight);
BlinkEffect blink;
ColorWipeEffect wipe;
ScannerEffect scanner;
CrawlEffect crawl;

void setup()
{
  Serial.begin(9600);
  // stateMachine.setOwner(&chainSword);

  stateMachine.changeState(&startState);
  bladeLight.changeTargetColor(secondaryColor);
  strip.begin();
  strip.show();
  blink.init(&bladeLight);
  blink.setup(4, 500);
  controller.AddLightEffect("Blink", &blink);
  wipe.init(&bladeLight);
  wipe.setup(4, 50, false);
  controller.AddLightEffect("Wipe", &wipe);
  scanner.init(&bladeLight);
  scanner.setup(2, 20, false);
  scanner.setEffectSize(3);
  controller.AddLightEffect("Scanner", &scanner);
  // crawl.init(&bladeLight);
  // crawl.setup(-1, 20);
  // crawl.setEffectSize(5);
  // controller.AddLightEffect("Crawl", &crawl);
  controller.SetEffect("Scanner", millis());
}

void loop()
{
  controller.execute(millis());
}