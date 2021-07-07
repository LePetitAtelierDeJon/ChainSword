#ifndef STARTSTATE_H_
#define STARTSTATE_H_

#include "StateMachine/BaseState.h"
#include "ChainSword.h"

class StartState : public BaseState<ChainSword>
{
public:
    void execute(ChainSword *context)
    {
    }

    void enter(ChainSword *context)
    {
    }

    void exit(ChainSword *context)
    {
    }
};
#endif // !STARTSTATE_H_