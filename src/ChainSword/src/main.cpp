#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "StateMachine/StateMachine.h"
#include "StateMachine/States/StartState.h"
#include "StateMachine/States/IdleState.h"
#include "StateMachine/States/RunningState.h"
#include "StateMachine/States/FullPower.h"
#include "StateMachine/States/CoolingState.h"
#include "StateMachine/States/TransitionIndex.h"
#include "ChainSword.h"
#include "Light/Light.h"
#include "Light/LightController.h"

#define LED_PIN 6
#define MOTOR_PIN 4
#define TRIGGER_PIN 2
#define LED_COUNT 32

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
StateMachine<ChainSword> stateMachine;
StartState startState;
IdleState idleState;
RunningState runningState;
FullPowerState fullPowerState;
CoolingState coolingState;
ChainSword chainSword;

Light bladeLight(&strip, LED_COUNT, 0, Color(0,0,0));
LightController controller(bladeLight);

void trigger();
void triggerOff();

void setup()
{
    Serial.begin(9600);
    Serial.println("+++ Machine Spirit Awaken +++");

    pinMode(TRIGGER_PIN, INPUT_PULLUP);
    pinMode(MOTOR_PIN, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(TRIGGER_PIN), trigger, CHANGE);

    Serial.println("+++ Chainsword Initialisation +++");
    chainSword.setLightController(&controller);
    chainSword.setMotorPin(MOTOR_PIN);
    chainSword.setStateMachine(&stateMachine);

    // Setup States
    Serial.println("+++ Setup States +++");
    startState.addExitState(IDLE_TRANSITION, &idleState);
    startState.setStateMachine(&stateMachine);

    idleState.addExitState(PULL_TRIGGER_TRANSITION, &runningState);
    idleState.setStateMachine(&stateMachine);

    runningState.addExitState(RELEASE_TRIGGER_TRANSITION, &coolingState);
    runningState.addExitState(OVERHEAT_TRANSITION, &fullPowerState);
    runningState.setStateMachine(&stateMachine);

    fullPowerState.addExitState(RELEASE_TRIGGER_TRANSITION, &coolingState);
    fullPowerState.setStateMachine(&stateMachine);

    coolingState.addExitState(PULL_TRIGGER_TRANSITION, &runningState);
    coolingState.addExitState(COOLED_TRANSITION, &idleState);
    coolingState.setStateMachine(&stateMachine);

    chainSword.init();
    
    stateMachine.changeState(&startState, millis());

    strip.begin();
    strip.show();

    Serial.println("+++ End of Initialisation +++");
}

unsigned long previousDelay = 0;
const unsigned long antiGhostingDelay = 100;
unsigned long plop = 0;

void trigger()
{
    unsigned long currentMillis = millis();
    if ((currentMillis - previousDelay) > antiGhostingDelay)
    {
        previousDelay = currentMillis;

        chainSword.toggleTrigger();
        if (chainSword.isTriggerOn())
        {
            Serial.println("-- Chainsword Activated --");
            stateMachine.makeTransition(PULL_TRIGGER_TRANSITION, currentMillis);
        }
        else
        {
            Serial.println("-- Chainsword Deactivated --");
            stateMachine.makeTransition(RELEASE_TRIGGER_TRANSITION, currentMillis);
        }
    }
}

bool switchstate = false;

void loop()
{
    unsigned long currentMillis = millis();
    stateMachine.execute(currentMillis);
}