#ifndef BASESTATE_H_
#define BASESTATE_H_

template <class T>
class BaseState
{
public:
    virtual ~BaseState() {}

    virtual void execute(T *context, unsigned long millis) = 0;
    virtual void enter(T *context, unsigned long millis) = 0;
    virtual void exit(T *context, unsigned long millis) = 0;
    
};

#endif // !BASESTATE_H_