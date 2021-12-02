#ifndef FULLPOWERSTATE_H_
#define FULLPOWERSTATE_H_

#include <Arduino.h>
#include "StateMachine/BaseState.h"

// forward declaration
class ChainSword;

class FullPowerState : public BaseState<ChainSword>
{
public:
    void execute(ChainSword *context, unsigned long millis);

    void enter(ChainSword *context, unsigned long millis);

    void exit(ChainSword *context, unsigned long millis);

};
#endif // !FULLPOWERSTATE_H_