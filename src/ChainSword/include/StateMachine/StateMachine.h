#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "BaseState.h"

template <class T>
class StateMachine
{
public:
    inline void setCurrentState(BaseState<T> *state) { currentState = state; }
    inline void setGlobalState(BaseState<T> *state) { globalState = state; }
    inline void setPreviousState(BaseState<T> *state) { previousState = state; }
    inline void setOwner(T *owner) { this->owner = owner; }

public:
    /**
     * @brief Change the current state of state machine. Call Exit of the state before change, and call Enter after change.
     * 
     * @param newState New state, Enter method is called after change.
     * @return true if the state changes correctly.
     * @return false if at least one of the state is null.
     */
    bool changeState(BaseState<T> *newState)
    {
        if (nullptr == currentState || nullptr == newState)
        {
            return false;
        }

        previousState = currentState;
        currentState->exit(owner);
        currentState = newState;
        currentState->enter(owner);
        return true;
    }

    void execute() const
    {
        if (currentState)
        {
            currentState->execute(owner);
        }

        if (globalState)
        {
            globalState->execute(owner);
        }
    }

    void revertToPreviousState()
    {
        changeState(previousState);
    }

    //StateMachine

private:
    T *owner;
    BaseState<T> *currentState;
    BaseState<T> *previousState;
    BaseState<T> *globalState;
};

#endif // !STATEMACHINE_H_