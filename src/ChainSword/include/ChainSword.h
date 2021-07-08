#ifndef CHAINSWORD_H_
#define CHAINSWORD_H_

#include "Light/LightController.h"

class ChainSword
{
public:
    inline bool isTriggerOn() { return isTriggerOn_; }
    inline void toggleTrigger() { isTriggerOn_ = !isTriggerOn_; }
    inline void setTriggerOn() { isTriggerOn_ = true; }
    inline void setTriggerOff() { isTriggerOn_ = false; }

    inline void setLight(LightController* light) {light_ = light; }
    inline LightController* light() const {return light_; }

private:
    bool isTriggerOn_;
    LightController* light_;

};

#endif // !CHAINSWORD_H_