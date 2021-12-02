#ifndef RUNNINGSTATE_H_
#define RUNNINGSTATE_H_

#include <Arduino.h>
#include "StateMachine/BaseState.h"

// forward declaration
class ChainSword;

class RunningState : public BaseState<ChainSword>
{
public:
    void execute(ChainSword *context, unsigned long millis);

    void enter(ChainSword *context, unsigned long millis);

    void exit(ChainSword *context, unsigned long millis);

private:
    unsigned long previousMillis = 0;
    bool transitionOver = false;
};
#endif // !RUNNINGSTATE_H_