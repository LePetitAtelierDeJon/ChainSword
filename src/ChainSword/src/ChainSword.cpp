#include "ChainSword.h"

#include "StateMachine/States/StartState.h"
#include "StateMachine/States/IdleState.h"
#include "StateMachine/States/RunningState.h"
#include "StateMachine/States/FullPowerState.h"
#include "StateMachine/States/CoolingState.h"
#include "StateMachine/States/TransitionIndex.h"

ChainSword::ChainSword()
{
    startState = new StartState();
    idleState = new IdleState();
    runningState = new RunningState();
    fullPowerState = new FullPowerState();
    coolingState = new CoolingState();

    stateMachine_ = new StateMachine<ChainSword>();
    stateMachine_->setOwner(this);
}

void ChainSword::init()
{
    Serial.println("+++ Setup Light Effects +++");
    // Start animation
    wipe_.setup(1, 30, false);
    wipe_.setTargetColor(baseBlue);
    lightController_->AddLightEffect(STARTUP_ANIMATION, &wipe_);

    // Blade heating animation
    fade_.setup(20, 100, false);
    fade_.setTargetColor(red);
    fade_.setEffectColor(baseBlue);
    lightController_->AddLightEffect(RUNNING_ANIMATION, &fade_);

    // Overheat animation
    crawl_.setup(-1, 8, false);
    crawl_.setEffectSize(10);
    crawl_.setTargetColor(red);
    crawl_.setEffectColor(overheatBaseColor);
    lightController_->AddLightEffect(OVERHEAT_ANIMATION, &crawl_);

    // Cooling animation
    blink_.setup(-1, 150, false);
    blink_.setTargetColor(coolingColor);
    blink_.setEffectColor(coolingColor2);
    lightController_->AddLightEffect(COOLING_ANIMATION, &blink_);

    // Idle animation
    scanner_.setup(1, 50, false);
    scanner_.setEffectSize(3);
    scanner_.setEffectColor(baseBlue);
    scanner_.setTargetColor(accentuatedBlue);
    lightController_->AddLightEffect(IDLE_ANIMATION, &scanner_);

    // Setup States
    Serial.println("+++ Setup States +++");
    startState->addExitState(IDLE_TRANSITION, idleState);
    startState->setStateMachine(stateMachine_);

    idleState->addExitState(PULL_TRIGGER_TRANSITION, runningState);
    idleState->setStateMachine(stateMachine_);

    runningState->addExitState(RELEASE_TRIGGER_TRANSITION, coolingState);
    runningState->addExitState(OVERHEAT_TRANSITION, fullPowerState);
    runningState->setStateMachine(stateMachine_);

    fullPowerState->addExitState(RELEASE_TRIGGER_TRANSITION, coolingState);
    fullPowerState->setStateMachine(stateMachine_);

    coolingState->addExitState(PULL_TRIGGER_TRANSITION, runningState);
    coolingState->addExitState(COOLED_TRANSITION, idleState);
    coolingState->setStateMachine(stateMachine_);

    stateMachine_->changeState(startState, millis());
}

void ChainSword::toggleTrigger(unsigned long millis)
{
    isTriggerOn_ = !isTriggerOn_;
    if (isTriggerOn_)
    {
        Serial.println("+++ Chainsword Activated +++");
        stateMachine_->makeTransition(PULL_TRIGGER_TRANSITION, millis);
    }
    else
    {
        Serial.println("+++ Chainsword Deactivated +++");
        stateMachine_->makeTransition(RELEASE_TRIGGER_TRANSITION, millis);
    }
}

void ChainSword::execute(unsigned long millis) const
{
    stateMachine_->execute(millis);
}