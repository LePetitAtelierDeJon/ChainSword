#ifndef BASESTATE_H_
#define BASESTATE_H_

template <class T>
class StateMachine;

template <class T>
class BaseState
{
public:
    virtual ~BaseState() {}

    virtual void execute(T *context, unsigned long millis) = 0;
    virtual void enter(T *context, unsigned long millis) = 0;
    virtual void exit(T *context, unsigned long millis) = 0;
    inline void addExitState(uint8_t transitionName, BaseState<T> *exitState)
    {
        exitStates_[transitionName] = exitState;
    }

    inline void switchState(uint8_t transitionName, unsigned long millis)
    {                
        BaseState<T> *state = exitStates_[transitionName];
        if(stateMachine_ != nullptr)
        {
            stateMachine_->changeState(state, millis);
        }        
    }

    inline void setStateMachine(StateMachine<T> *stateMachine)
    {
        stateMachine_ = stateMachine;
    }

private:
    //std::map<String, BaseState<T> *> exitStates_;
    BaseState<T>*  exitStates_[10];
    StateMachine<T> *stateMachine_;
};
#endif // !BASESTATE_H_