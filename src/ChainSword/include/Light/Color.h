#ifndef COLOR_H_
#define COLOR_H_

struct Color
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    Color(uint8_t red, uint8_t green, uint8_t blue)
    {
        this->red = red;
        this->green = green;
        this->blue = blue;
    }

    Color()
    {
        red = 0;
        green = 0;
        blue = 0;
    }

    Color operator+(const Color &color)
    {
        uint8_t newRed = red + color.red;
        uint8_t newGreen = green + color.green;
        uint8_t newBlue = blue + color.blue;

        return Color(newRed, newGreen, newBlue);
    }

    Color operator/(const uint8_t divider)
    {
        uint8_t newRed = red / divider;
        uint8_t newGreen = green / divider;
        uint8_t newBlue = blue / divider;

        return Color(newRed, newGreen, newBlue);
    }

    Color& operator+=(const Color &color)
    {
        this->red += color.red;
        this->green += color.green;
        this->blue += color.blue;

        return *this;
    }

    Color operator-(const Color &color)
    {
        uint8_t newRed = red - color.red;
        uint8_t newGreen = green - color.green;
        uint8_t newBlue = blue - color.blue;

        return Color(newRed, newGreen, newBlue);
    }

    Color& operator-=(const Color &color)
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
