#ifndef COLOR_H_
#define COLOR_H_

struct Color
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
        int newRed = red + color.trueRed;
        int newGreen = green + color.trueGreen;
        int newBlue = blue + color.trueBlue;

        return Color(newRed, newGreen, newBlue);
    }

    Color operator/(const int divider)
    {
        float newRed = ((float)red / divider);
        float newGreen = ((float)green / divider);
        float newBlue = ((float)blue / divider);

        Color c = Color((int)newRed, (int)newGreen, (int)newBlue);
        c.trueRed = newRed;
        c.trueGreen = newGreen;
        c.trueBlue = newBlue;
        return c;
    }

    Color &operator+=(const Color &color)
    {
        this->red += color.trueRed;
        this->green += color.trueGreen;
        this->blue += color.trueBlue;

        return *this;
    }

    Color operator-(const Color &color)
    {
        int newRed = red - color.trueRed;
        int newGreen = green - color.trueGreen;
        int newBlue = blue - color.trueBlue;

        return Color(newRed, newGreen, newBlue);
    }

    Color &operator-=(const Color &color)
    {
        this->red -= color.trueRed;
        this->green -= color.trueGreen;
        this->blue -= color.trueBlue;

        return *this;
    }
};

#endif // !COLOR_H_
