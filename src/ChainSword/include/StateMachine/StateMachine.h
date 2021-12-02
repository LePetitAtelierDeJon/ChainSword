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
    inline void setContext(T *context) { this->context = context; }

public:
    /**
     * @brief Change the current state of state machine. Call Exit of the state before change, and call Enter after change.
     *
     * @param newState New state, Enter method is called after change.
     * @param millis current time.
     * @return true if the state changes correctly.
     * @return false if at least one of the state is null.
     */
    bool changeState(BaseState<T> *newState, unsigned long millis)
    {
        if (nullptr == currentState && nullptr == newState)
        {
            return false;
        }

        if (nullptr != currentState)
        {
            previousState = currentState;
            currentState->exit(context, millis);
        }
        currentState = newState;
        currentState->enter(context, millis);
        return true;
    }

    /**
     * @brief Make the transition between currentState and the state corresponding to the transitionIndex inside currentState.
     *
     * @param transitionIndex Index of the transition inside the exitState of the state, [0, 9].
     * @param millis current time.
     */
    void makeTransition(uint8_t transitionIndex, unsigned long millis)
    {
        if (nullptr != currentState)
        {
            BaseState<T> *newState = currentState->stateForTransitionIndex(transitionIndex);
            if(newState != nullptr)
            {
                changeState(newState, millis);
            }
        }
    }

    /**
     * @brief update the currentState and the globalState.
     *
     * @param millis current time.
     */
    void execute(unsigned long millis) const
    {
        if (nullptr != currentState)
        {
            currentState->execute(context, millis);
        }

        if (nullptr != globalState)
        {
            globalState->execute(context, millis);
        }
    }

    /**
     * @brief Return to previous state.
     *
     */
    void revertToPreviousState()
    {
        changeState(previousState);
    }

private:
/**
 * @brief Context of the state machine. Used for calling context method inside states.
 * 
 */
    T *context;
    BaseState<T> *currentState;
    BaseState<T> *previousState;
    BaseState<T> *globalState;
};

#endif // !STATEMACHINE_H_