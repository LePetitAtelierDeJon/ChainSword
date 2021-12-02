#ifndef COOLINGSTATE_H_
#define COOLINGSTATE_H_

#include <Arduino.h>
#include "StateMachine/BaseState.h"

// forward declaration
class ChainSword;

class CoolingState : public BaseState<ChainSword>
{
public:
    void execute(ChainSword *context, unsigned long millis);

    void enter(ChainSword *context, unsigned long millis);

    void exit(ChainSword *context, unsigned long millis);

private:
    unsigned long startMillis;
};
#endif // !COOLINGSTATE_H_