#ifndef COLOR_H_
#define COLOR_H_

/**
 * @brief Color struct, contains the representation of a color in Red, Green & Blue.
 * @n Each color component is represented by an integer value, used for displaying and use in light object (for rgb strip led).
 * @n But also by a float value, used for the operators, particularly the / operator.
 * @remark unsigned int is not used, although rgb led only support unsiged value, because when fading form one color to another, some components may be negative.
 */
struct Color
{
public:
    int red;
    int green;
    int blue;

    float floatRed = 0.0f;
    float floatGreen = 0.0f;
    float floatBlue = 0.0f;

    /**
     * @brief Construct a new Color object.
     *
     * @param red red component.
     * @param green green component.
     * @param blue blue component.
     */
    Color(int red, int green, int blue)
    {
        this->red = red;
        this->green = green;
        this->blue = blue;
        floatRed = (float)red;
        floatGreen = (float)green;
        floatBlue = (float)blue;
    }

    /**
     * @brief Construct a new Color object. Color is set to black (0,0,0).
     *
     */
    Color()
    {
        red = 0;
        green = 0;
        blue = 0;
        floatRed = 0.0f;
        floatGreen = 0.0f;
        floatBlue = 0.0f;
    }

    /**
     * @brief + operator override.
     *
     * @param color Color to add to the current color.
     * @return Color New color resulting from the addition of current color and color parameter.
     */
    Color operator+(const Color &color)
    {
        int newRed = red + color.floatRed;
        int newGreen = green + color.floatGreen;
        int newBlue = blue + color.floatBlue;

        return Color(newRed, newGreen, newBlue);
    }

    /**
     * @brief / operator override.
     *
     * @param divider number to divide each color component with.
     * @return Color New color resulting from the division of current color by divider parameter.
     */
    Color operator/(const int divider)
    {
        float newRed = ((float)red / divider);
        float newGreen = ((float)green / divider);
        float newBlue = ((float)blue / divider);

        Color c = Color((int)newRed, (int)newGreen, (int)newBlue);
        c.floatRed = newRed;
        c.floatGreen = newGreen;
        c.floatBlue = newBlue;
        return c;
    }

    /**
     * @brief += operator override.
     *
     * @param color Color to add to the current color.
     * @return Color& New value for current color resulting from the addition of current color and color parameter.
     */
    Color &operator+=(const Color &color)
    {
        this->red += color.floatRed;
        this->green += color.floatGreen;
        this->blue += color.floatBlue;

        return *this;
    }

    /**
     * @brief - operator override.
     *
     * @param color Color to add to the current color.
     * @return Color New color resulting from the substraction of current color and color parameter.
     */
    Color operator-(const Color &color)
    {
        int newRed = red - color.floatRed;
        int newGreen = green - color.floatGreen;
        int newBlue = blue - color.floatBlue;

        return Color(newRed, newGreen, newBlue);
    }

    /**
     * @brief -= operator override.
     *
     * @param color Color to add to the current color.
     * @return Color& New value for current color resulting from the substraction of current color and color parameter.
     */
    Color &operator-=(const Color &color)
    {
        this->red -= color.floatRed;
        this->green -= color.floatGreen;
        this->blue -= color.floatBlue;

        return *this;
    }
};

#endif // !COLOR_H_
