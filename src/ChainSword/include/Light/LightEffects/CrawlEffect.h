#ifndef CRAWLEFFECT_H_
#define CRAWLEFFECT_H_

#include "LightEffect.h"

class CrawlEffect : public LightEffect
{
public:
    virtual ~CrawlEffect() {}

    void setup(uint8_t effectCounter, unsigned long effectFrequency, bool turnOffAtStop) override;
    void start(unsigned long startMillis) override;
    void executeEffect(unsigned long millis) override;
    void stop() override;
    void setEffectSize(uint8_t effectSize);

private:
   int8_t currentIndex_; 
   int8_t effectDirection_;
   uint8_t effectSize_;
   uint8_t fadeSize_;
   Color otherColor_;
};

#endif // !CRAWLEFFECT_H_