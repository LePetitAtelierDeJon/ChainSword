#ifndef BASESTATE_H_
#define BASESTATE_H_

#include <Arduino.h>

template <class T>
class StateMachine;

/**
 * @brief Base class for state used by the StateMachine.
 *
 * @tparam T Type of state context.
 */
template <class T>
class BaseState
{
public:
    virtual ~BaseState() {}

    /**
     * @brief Called when the StateMachine updates the state.
     *
     * @param context Context of the state.
     * @param millis Current time.
     */
    virtual void execute(T *context, unsigned long millis) = 0;

    /**
     * @brief Called when the StateMachine enters the state.
     *
     * @param context Context of the state.
     * @param millis Current time.
     */
    virtual void enter(T *context, unsigned long millis) = 0;

    /**
     * @brief Called when the StateMachine exits the state.
     *
     * @param context Context of the state.
     * @param millis Current time.
     */
    virtual void exit(T *context, unsigned long millis) = 0;

    /**
     * @brief Add states where it is possible to exit with the correct transitionIndex.
     *
     * @param transitionIndex Index for the transition [0, 9].
     * @param exitState State where it is possible to exit.
     */
    inline void addExitState(uint8_t transitionIndex, BaseState<T> *exitState)
    {
        exitStates_[transitionIndex] = exitState;
    }

    /**
     * @brief Get the state for the transitionIndex.
     *
     * @param transitionIndex Index for the transition [0, 9].
     * @return BaseState<T>* The state with transitionIndex as index.
     */
    inline BaseState<T> *stateForTransitionIndex(uint8_t transitionIndex) const
    {
        return exitStates_[transitionIndex];
    }

    /**
     * @brief Set the StateMachine object.
     *
     * @param stateMachine StateMachine to use.
     */
    inline void setStateMachine(StateMachine<T> *stateMachine)
    {
        stateMachine_ = stateMachine;
    }

protected:
    StateMachine<T> *stateMachine_;

private:
    /**
     * @brief Array of exitStates.
     * @todo Dynamically create the array.
     *
     */
    BaseState<T> *exitStates_[10];
};
#endif // !BASESTATE_H_