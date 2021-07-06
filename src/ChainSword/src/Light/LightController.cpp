// #include "Light.h"

// /**
//  * Light constructor
//  * @param strip The led strip used.
//  * @param pixelCount The number of pixel needed for the light.
//  * @param firstPixelIndex The index of the first pixel.
//  * @param updateFrequency The update frequency of the light.
//  * @param lightColor The light Color
//  */
// Light::Light(Adafruit_NeoPixel &strip, uint8_t pixelCount, uint8_t firstPixelIndex, long updateFrequency, Color lightColor) : strip_(strip),
//                                                                                                                               pixelCount_(pixelCount), firstPixelIndex_(firstPixelIndex), currentIndex_(firstPixelIndex), updateFrequency_(updateFrequency), lightColor_(lightColor), lightState_(LightState::Initialization) {}

// /**
//  * The update method of the light, called every time the updateFrequency is reached.
//  */
// void Light::update()
// {
//     unsigned long currentMillis = millis();

//     if (currentMillis - previousMillis_ >= updateFrequency_)
//     {
//         switch (lightState_)
//         {
//         case LightState::Initialization:
//             processInitialization();
//         case LightState::Wipe:
//             wipeLight();
//             break;
//         case LightState::Blink:
//             processBlink(currentMillis);
//             break;
//         case LightState::Scanner:
//             processScanner(currentMillis);
//             break;
//         case LightState::Crawl:
//             processCrawl(currentMillis);
//             break;
//         case LightState::FadeTo:
//             proccessFadeTo(currentMillis);
//             break;
//         case LightState::Fade:
//             proccessFade(currentMillis);
//             break;
//         }
//         previousMillis_ = currentMillis;
//     }
// }

// /**
//  * Fill the pixel one after the other with a color.
//  */
// void Light::wipeLight()
// {
//     if (currentIndex_ < firstPixelIndex_ + pixelCount_)
//     {
//         strip_.setPixelColor(currentIndex_++, strip_.Color(lightColor_.red, lightColor_.green, lightColor_.blue));
//         strip_.show();
//     }
//     else
//     {
//         lightState_ = LightState::Idle;
//     }
// }

// /**
//  * Fill the pixel one after the other with a color.
//  */
// void Light::processInitialization()
// {
//     if (currentIndex_ < firstPixelIndex_ + pixelCount_)
//     {
//         strip_.setPixelColor(currentIndex_++, strip_.Color(lightColor_.red, lightColor_.green, lightColor_.blue));
//         strip_.show();
//     }
//     else
//     {
//         lightState_ = LightState::Idle;
//     }
// }

// /**
//  * Update the blink state.
//  * @param millis the current elapsedTime.
//  */
// void Light::processBlink(unsigned long millis)
// {
//     if (millis - previousEffectMillis_ >= effectFrequency_)
//     {
//         if (effectCounter_ > 0 || effectCounter_ <= -1)
//         {
//             if (blinkState_)
//             {
//                 off();
//             }
//             else
//             {
//                 on();
//                 decrementEffectCounter();
//             }
//             blinkState_ = !blinkState_;

//             previousEffectMillis_ = millis;
//         }
//         else
//         {
//             stopEffect();
//         }
//     }
// }

// void Light::processScanner(unsigned long millis)
// {
//     if (millis - previousEffectMillis_ >= effectFrequency_)
//     {
//         if (effectCounter_ > 0 || effectCounter_ <= -1)
//         {
//             strip_.setPixelColor(currentIndex_, 0);
//             currentIndex_ += effectDirection_;
//             if (currentIndex_ >= firstPixelIndex_ + pixelCount_-1 || currentIndex_ <= firstPixelIndex_)
//             {
//                 effectDirection_ *= -1;
//                 if (effectDirection_ == 1)
//                 {
//                     decrementEffectCounter();
//                 }
//             }
//             strip_.setPixelColor(currentIndex_, strip_.Color(lightColor_.red, lightColor_.green, lightColor_.blue));

//             strip_.show();
//             previousEffectMillis_ = millis;
//         }
//         else
//         {
//             stopEffect();
//         }
//     }
// }

// void Light::processCrawl(unsigned long millis)
// {
//     if (millis - previousEffectMillis_ >= effectFrequency_)
//     {
//         if (effectCounter_ > 0 || effectCounter_ <= -1)
//         {
//             strip_.setPixelColor(currentIndex_++, 0);
//             if (currentIndex_ > firstPixelIndex_ + pixelCount_)
//             {
//                 currentIndex_ = firstPixelIndex_;
//                 decrementEffectCounter();
//             }
//             strip_.setPixelColor(currentIndex_, strip_.Color(lightColor_.red, lightColor_.green, lightColor_.blue));

//             strip_.show();
//             previousEffectMillis_ = millis;
//         }
//         else
//         {
//             stopEffect();
//         }
//     }
// }

// void Light::proccessFadeTo(unsigned long millis)
// {
//     if (millis - previousEffectMillis_ >= effectFrequency_)
//     {
//         if (effectCounter_ >= 0)
//         {
//             uint8_t red = ((lightColor_.red * (effectCounter_)) + (targetColor_.red * effectCounterTotal_ - effectCounter_)) / effectCounterTotal_;
//             uint8_t green = ((lightColor_.green * (effectCounter_)) + (targetColor_.green * effectCounterTotal_ - effectCounter_)) / effectCounterTotal_;
//             uint8_t blue = ((lightColor_.blue * (effectCounter_)) + (targetColor_.blue * effectCounterTotal_ - effectCounter_)) / effectCounterTotal_;

//             Color color = Color(red, green, blue);
//             transitionColor_ = color;
//             strip_.fill(strip_.Color(color.red, color.green, color.blue));
//             strip_.show();
//             previousEffectMillis_ = millis;
//             decrementEffectCounter();
//         }
//         else
//         {
//             lightColor_ = transitionColor_;
//             stopEffect();
//         }
//     }
// }

// void Light::proccessFade(unsigned long millis)
// {
//     if (millis - previousEffectMillis_ >= effectFrequency_)
//     {
//         if (lightColor_.red != 0 || lightColor_.blue != 0 || lightColor_.green != 0)
//         {
//             lightColor_.dim();
//             strip_.fill(strip_.Color(lightColor_.red, lightColor_.green, lightColor_.blue));
//             strip_.show();
//             previousEffectMillis_ = millis;
//         }
//         else
//         {
//             stopEffect();
//         }
//     }
// }

// /**
//  * Change the color for the light.
//  * @param red Red component of the color.
//  * @param green Green component of the color.
//  * @param blue Blue component of the color.
//  */
// void Light::changeColor(uint8_t red, uint8_t green, uint8_t blue)
// {
//     // uint32_t color = strip_.Color(red, green, blue);
//     Color color = Color(red, green, blue);
//     changeColor(color);
// }

// void Light::changeColor(Color color)
// {
//     lightColor_ = color;
//     for (int index = firstPixelIndex_; index < firstPixelIndex_ + pixelCount_; ++index)
//     {
//         strip_.setPixelColor(index, strip_.Color(lightColor_.red, lightColor_.green, lightColor_.blue));
//     }
//     if (lightState_ == LightState::Idle)
//     {
//         strip_.show();
//     }
// }

// /**
//  * Hey, who turned out the lights?
//  */
// void Light::off()
// {
//     for (int index = firstPixelIndex_; index < firstPixelIndex_ + pixelCount_; ++index)
//     {
//         strip_.setPixelColor(index, 0);
//     }
//     strip_.show();
// }

// /**
//  * Turn on the lights.
//  */
// void Light::on()
// {
//     for (int index = firstPixelIndex_; index < firstPixelIndex_ + pixelCount_; ++index)
//     {
//         strip_.setPixelColor(index, strip_.Color(lightColor_.red, lightColor_.green, lightColor_.blue));
//     }
//     strip_.show();
// }

// /**
//  * Set blink status;
//  */
// void Light::blink(uint8_t times, unsigned long period)
// {
//     lightState_ = LightState::Blink;
//     effectCounter_ = times;
//     effectFrequency_ = period;
//     blinkState_ = true;
//     previousEffectMillis_ = millis();
// }

// void Light::wipe()
// {
//     off();
//     lightState_ = LightState::Wipe;
// }

// void Light::fade(uint8_t times, unsigned long period)
// {
//     lightState_ = LightState::Fade;
//     effectCounter_ = times;
//     effectFrequency_ = period;
//     previousEffectMillis_ = millis();
// }

// void Light::fadeTo(uint8_t times, Color color, unsigned long period)
// {
//     lightState_ = LightState::FadeTo;
//     targetColor_ = color;
//     effectCounter_ = times;
//     effectCounterTotal_ = times;
//     effectFrequency_ = period;
//     transitionColor_ = (lightColor_ - targetColor_) / effectCounter_;
//     previousEffectMillis_ = millis();
// }

// void Light::crawl(uint8_t times, unsigned long period)
// {
//     lightState_ = LightState::Crawl;
//     effectCounter_ = times;
//     effectFrequency_ = period;
//     previousEffectMillis_ = millis();
// }

// void Light::scanner(uint8_t times, unsigned long period)
// {
//     lightState_ = LightState::Scanner;
//     effectCounter_ = times;
//     effectFrequency_ = period;
//     previousEffectMillis_ = millis();
//     effectDirection_ = 1;
// }

// void Light::decrementEffectCounter()
// {
//     if (effectCounter_ > 0)
//     {
//         --effectCounter_;
//     }
// }

// void Light::stopEffect()
// {
//     on();
//     lightState_ = LightState::Idle;
//     previousEffectMillis_ = 0;
// }

#include "Light/LightController.h"

LightController::LightController(Light &light) : light_(light) {}

Light &LightController::GetLight() const
{
    return light_;
}

void LightController::AddLightEffect(String effectName, LightEffect *effect)
{
    lightEffects_[effectName] = effect;
}

void LightController::SetEffect(String effectName, unsigned long millis)
{
    lightEffects_[effectName]->start(millis);
    activeLightEffect_ = effectName;
}

void LightController::execute(unsigned long millis)
{
    if (lightEffects_[activeLightEffect_]->canExecute(millis))
    {
        lightEffects_[activeLightEffect_]->execute(millis);
    }
}