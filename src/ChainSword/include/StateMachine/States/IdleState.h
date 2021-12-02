#ifndef IDLESTATE_H_
#define IDLESTATE_H_

#include <Arduino.h>
#include "StateMachine/BaseState.h"

// forward declaration
class ChainSword;

class IdleState : public BaseState<ChainSword>
{
public:
    void execute(ChainSword *context, unsigned long millis);

    void enter(ChainSword *context, unsigned long millis);

    void exit(ChainSword *context, unsigned long millis);


private:
    unsigned long previousMillis = 0;
    bool isStarting = true;
};
#endif // !IDLESTATE_H_