#ifndef CHAINSWORD_H_
#define CHAINSWORD_H_

class ChainSword
{
public:
    inline bool IsTriggerOn() { return isTriggerOn; }
    inline void ToggleTrigger() { isTriggerOn = !isTriggerOn; }

private:
    bool isTriggerOn;
};

#endif // !CHAINSWORD_H_