#ifndef COLOR_H_
#define COLOR_H_

class Color
{
public:
    int red;
    int green;
    int blue;

    float trueRed = 0.0f;
    float trueGreen = 0.0f;
    float trueBlue = 0.0f;  


    Color(int red, int green, int blue)
    {
        this->red = red;
        this->green = green;
        this->blue = blue;
        trueRed = (float)red;
        trueGreen = (float)green;
        trueBlue = (float)blue;
    }

    Color()
    {
        red = 0;
        green = 0;
        blue = 0;
        trueRed = 0.0f;
        trueGreen = 0.0f;
        trueBlue = 0.0f;
    }

    Color operator+(const Color &color)
    {
        int newRed = red + color.red;
        int newGreen = green + color.green;
        int newBlue = blue + color.blue;

        // int16_t newRed = red + color.trueRed;
        // int16_t newGreen = green + color.trueGreen;
        // int16_t newBlue = blue + color.trueBlue;

        return Color(newRed, newGreen, newBlue);
    }

    Color operator/(const int divider)
    {
        float newRed = ((float)red / divider);
        //Serial.println(newRed);
        float newGreen = ((float)green / divider);
        //Serial.println(newGreen);
        float newBlue = ((float)blue / divider);
        //Serial.println(newBlue);

        Color c = Color((int)newRed, (int)newGreen, (int)newBlue);
        c.trueRed = newRed;
        c.trueGreen = newGreen;
        c.trueBlue = newBlue;
        return c;

        // int newRed = red / divider;

        // int newGreen = green / divider;

        // int newBlue = blue / divider;

        // return Color(newRed, newGreen, newBlue);
    }

    Color &operator+=(const Color &color)
    {
        this->red += color.trueRed;
        this->green += color.trueGreen;
        this->blue += color.trueBlue;

        // this->red += color.red;
        // this->green += color.green;
        // this->blue += color.blue;


        return *this;
    }

    Color operator-(const Color &color)
    {
        int newRed = red - color.red;
        int newGreen = green - color.green;
        int newBlue = blue - color.blue;

        return Color(newRed, newGreen, newBlue);
    }

    Color &operator-=(const Color &color)
    {
        this->red -= color.red;
        this->green -= color.green;
        this->blue -= color.blue;

        return *this;
    }

    void dim()
    {
        red >>= 1;
        green >>= 1;
        blue >>= 1;
    }
};

#endif // !COLOR_H_
