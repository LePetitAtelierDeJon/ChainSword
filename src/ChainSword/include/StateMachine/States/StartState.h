#ifndef STARTSTATE_H_
#define STARTSTATE_H_

#include <Arduino.h>
#include "StateMachine/BaseState.h"
#include "StateMachine/States/TransitionIndex.h"
#include "ChainSword.h"

// forward declaration
class ChainSword;

class StartState : public BaseState<ChainSword>
{
public:
    void execute(ChainSword *context, unsigned long millis);

    void enter(ChainSword *context, unsigned long millis);

    void exit(ChainSword *context, unsigned long millis);

};
#endif // !STARTSTATE_H_