#ifndef __DRAWABLE_H__
#define __DRAWABLE_H__

#include <Vector2.h>
#include <Adafruit_ILI9341.h>

class Drawable // abstract
{
protected:
    Vector2 pos;

public:
    Drawable();
    Drawable(Vector2 pos);
    Drawable(int16_t x, int16_t y);

    const Vector2 getPos();

    virtual void draw(Adafruit_ILI9341 *tft) = 0; // = 0 means that this method has to be implemented in the derived class
    virtual void undraw(Adafruit_ILI9341 *tft) = 0;

    virtual void doStep(unsigned long delta, Adafruit_ILI9341 *tft); // no = 0 because this method is optional
};

#endif